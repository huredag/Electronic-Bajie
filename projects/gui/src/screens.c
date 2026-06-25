/******************************************************************************
 * @file     screens.c
 * @brief    EEZ Studio 导出的 LVGL 界面（适配 v8.3，去除 Flow 引擎依赖）
 *
 *  移植说明：
 *    - 原始文件由 EEZ Studio 生成（LVGL v9 + eez-flow C++ 运行时）
 *    - 已剥离所有 Flow 依赖，仅保留纯 LVGL API 调用
 *    - API 从 v9 降级到 v8.3（lv_image→lv_img, lv_imagebutton→lv_imgbtn 等）
 *    - 页面跳转改用 lv_scr_load_anim() 实现
 *
 * @version  V1.0
 * @date     2026-06-25
 ******************************************************************************/

#include <string.h>
#include <math.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"

/* ===========================================================================
 * 全局对象
 * =========================================================================*/

objects_t objects;
lv_obj_t *tick_value_change_obj;

/* ===========================================================================
 * cold 屏飞入动画
 * =========================================================================*/

#define FLY_FRAMES   10
#define FLY_STAGGER   2
#define FLY_SX       0
#define FLY_SY     330

static lv_obj_t  *fly_btns[5];
static int32_t    fly_tx[5], fly_ty[5], fly_tick[5];
static lv_timer_t *fly_timer = NULL;

static void cold_fly_cb(lv_timer_t *t) {
    (void)t;
    bool all_done = true;
    for (int i = 0; i < 5; i++) {
        int32_t f = fly_tick[i];
        if (f < 0)          { fly_tick[i]++; all_done = false; continue; }
        if (f > FLY_FRAMES) { continue; }
        all_done = false;
        float p  = (float)f / FLY_FRAMES;
        float ep = 1.0f - (1.0f - p) * (1.0f - p);
        float arc_p = 4.0f * ep * (1.0f - ep);
        int32_t x = (int32_t)(FLY_SX + (fly_tx[i] - FLY_SX) * ep + 0.5f);
        int32_t y = (int32_t)(FLY_SY + (fly_ty[i] - FLY_SY) * ep - 60.0f * arc_p + 0.5f);
        lv_obj_set_pos(fly_btns[i], x, y);
        fly_tick[i]++;
    }
    if (all_done) { lv_timer_del(fly_timer); fly_timer = NULL; }
}

static void cold_screen_loaded_cb(lv_event_t *e) {
    (void)e;
    fly_btns[0] = lv_obj_get_child(objects.cold, 0); fly_tx[0]=36;  fly_ty[0]=132;
    fly_btns[1] = lv_obj_get_child(objects.cold, 2); fly_tx[1]=75;  fly_ty[1]=48;
    fly_btns[2] = lv_obj_get_child(objects.cold, 3); fly_tx[2]=180; fly_ty[2]=48;
    fly_btns[3] = lv_obj_get_child(objects.cold, 4); fly_tx[3]=270; fly_ty[3]=113;
    fly_btns[4] = lv_obj_get_child(objects.cold, 1); fly_tx[4]=66;  fly_ty[4]=222;
    for (int i = 0; i < 5; i++) {
        fly_tick[i] = -(i * FLY_STAGGER);
        lv_obj_set_pos(fly_btns[i], FLY_SX, FLY_SY);
    }
    if (fly_timer) { lv_timer_del(fly_timer); fly_timer = NULL; }
    fly_timer = lv_timer_create(cold_fly_cb, 16, NULL);
}

/* ===========================================================================
 * 事件回调（用 LVGL 原生页面跳转替代 Flow 事件传播）
 * =========================================================================*/

static void event_handler_cb_mode_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        lv_scr_load_anim(objects.cold, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, false);
    }
}

static void event_handler_cb_main_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        lv_scr_load_anim(objects.cold, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, false);
    }
}

static void event_handler_cb_cold_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_CLICKED) {
        lv_scr_load_anim(objects.main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, false);
    }
}

/* ===========================================================================
 * mode 屏：3D 圆柱滚动菜单
 * =========================================================================*/

#define MODE_BTN_COUNT  6
#define MODE_BASE_SZ    60
#define MODE_STEP       105
#define MODE_CENTER_X   180
#define MODE_CENTER_Y   180

static lv_obj_t *mode_btns[MODE_BTN_COUNT];
static float mode_offset   = 0.0f;
static float mode_velocity = 0.0f;
static int32_t mode_last_y = 0;
static bool mode_dragging  = false;

static void mode_layout_update(void) {
    for (int i = 0; i < MODE_BTN_COUNT; i++) {
        float dy = i * (float)MODE_STEP - mode_offset;
        float adist = dy < 0 ? -dy : dy;

        if (adist > (float)MODE_STEP * 1.5f) {
            lv_obj_add_flag(mode_btns[i], LV_OBJ_FLAG_HIDDEN);
            continue;
        }
        lv_obj_clear_flag(mode_btns[i], LV_OBJ_FLAG_HIDDEN);

        /* v8.3 只支持统一缩放，取 depth 做近似 */
        float depth = 1.0f - adist / ((float)MODE_STEP * 3.0f);
        uint16_t zoom = (uint16_t)(256.0f * depth + 0.5f);
        if (zoom < 32) zoom = 32;
        lv_img_set_zoom(mode_btns[i], zoom);

        float vis_sz = (float)MODE_BASE_SZ * zoom / 256.0f;
        int32_t x = (int32_t)(MODE_CENTER_X - vis_sz / 2.0f + 0.5f);
        int32_t y = (int32_t)(MODE_CENTER_Y + dy - vis_sz / 2.0f + 0.5f);
        lv_obj_set_pos(mode_btns[i], x, y);
    }
}

static lv_timer_t *mode_inertia_timer = NULL;

static void mode_inertia_cb(lv_timer_t *t) {
    (void)t;
    mode_offset += mode_velocity;
    mode_velocity *= 0.88f;

    float min_off = 0;
    float max_off = (MODE_BTN_COUNT - 1) * (float)MODE_STEP;
    if (mode_offset < min_off) { mode_offset = min_off; mode_velocity = 0; }
    if (mode_offset > max_off) { mode_offset = max_off; mode_velocity = 0; }

    mode_layout_update();

    if (mode_velocity > -0.5f && mode_velocity < 0.5f) {
        float step = (float)MODE_STEP;
        float nearest = (float)(int32_t)((mode_offset / step) + 0.5f) * step;
        mode_offset += (nearest - mode_offset) * 0.15f;
        mode_layout_update();
        if (mode_velocity == 0 &&
            (mode_offset > nearest - 0.5f) && (mode_offset < nearest + 0.5f)) {
            mode_offset = nearest;
            mode_layout_update();
            lv_timer_del(mode_inertia_timer);
            mode_inertia_timer = NULL;
        }
    }
}

static int32_t mode_press_start_y = 0;

static void event_handler_mode_gesture(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_indev_t *indev = lv_indev_get_act();
    if (!indev) return;

    lv_point_t pt;
    lv_indev_get_point(indev, &pt);

    if (code == LV_EVENT_PRESSED) {
        mode_dragging = true;
        mode_last_y = pt.y;
        mode_press_start_y = pt.y;
        mode_velocity = 0;
        if (mode_inertia_timer) {
            lv_timer_del(mode_inertia_timer);
            mode_inertia_timer = NULL;
        }
    } else if (code == LV_EVENT_PRESSING && mode_dragging) {
        int32_t dy_val = mode_last_y - pt.y;
        mode_last_y = pt.y;
        mode_velocity = (float)dy_val;
        mode_offset += (float)dy_val;

        float min_off = 0, max_off = (MODE_BTN_COUNT - 1) * (float)MODE_STEP;
        if (mode_offset < min_off) mode_offset = min_off;
        if (mode_offset > max_off) mode_offset = max_off;

        mode_layout_update();
    } else if (code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
        mode_dragging = false;
        int32_t total = pt.y - mode_press_start_y;
        if (total < 0) total = -total;
        if (total < 8 && code == LV_EVENT_RELEASED) {
            lv_scr_load_anim(objects.cold, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, false);
        }
        if (mode_inertia_timer == NULL)
            mode_inertia_timer = lv_timer_create(mode_inertia_cb, 16, NULL);
    }
}

/* ===========================================================================
 * 页面创建
 * =========================================================================*/

void create_screen_mode() {
    lv_obj_t *obj = lv_obj_create(NULL);
    objects.mode = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 360, 360);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 0, 0);

    lv_obj_t *cont = lv_obj_create(obj);
    lv_obj_set_pos(cont, 0, 0);
    lv_obj_set_size(cont, 360, 360);
    lv_obj_set_style_pad_all(cont, 0, 0);
    lv_obj_set_style_bg_opa(cont, 0, 0);
    lv_obj_set_style_border_width(cont, 0, 0);
    lv_obj_set_style_radius(cont, 0, 0);
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *touch = lv_obj_create(obj);
    lv_obj_set_pos(touch, 0, 0);
    lv_obj_set_size(touch, 360, 360);
    lv_obj_set_style_bg_opa(touch, 0, 0);
    lv_obj_set_style_border_width(touch, 0, 0);
    lv_obj_set_style_radius(touch, 0, 0);
    lv_obj_clear_flag(touch, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(touch, event_handler_mode_gesture, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(touch, event_handler_mode_gesture, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(touch, event_handler_mode_gesture, LV_EVENT_RELEASED, NULL);
    lv_obj_add_event_cb(touch, event_handler_mode_gesture, LV_EVENT_PRESS_LOST, NULL);

    const lv_img_dsc_t *srcs[MODE_BTN_COUNT] = {
        &img_popup_button_mode_hum_off_background_image,
        &img_popup_button_mode_hot_off_background_image,
        &img_popup_button_mode_flash_off_background_image,
        &img_popup_button_mode_cold_off_background_image,
        &img_popup_button_fan_level_down_off_background_image,
        &img_popup_button_fan_high_off_background_image,
    };
    for (int i = 0; i < MODE_BTN_COUNT; i++) {
        lv_obj_t *img = lv_img_create(cont);
        lv_img_set_src(img, srcs[i]);
        lv_img_set_pivot(img, 0, 0);
        lv_obj_set_style_bg_opa(img, 0, 0);
        lv_obj_set_style_border_width(img, 0, 0);
        lv_obj_add_flag(img, LV_OBJ_FLAG_CLICKABLE);
        mode_btns[i] = img;
    }
    objects.obj0 = mode_btns[3];
    lv_obj_add_event_cb(mode_btns[3], event_handler_cb_mode_obj0, LV_EVENT_ALL, NULL);

    mode_offset = 0;
    mode_velocity = 0;
    mode_layout_update();
}

void tick_screen_mode() {
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(NULL);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 360, 360);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 66, 62);
            lv_obj_set_size(obj, 233, 225);
            lv_arc_set_range(obj, 0, 40);
            lv_arc_set_value(obj, 25);
            lv_arc_set_bg_angles(obj, 180, 360);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x2196f3), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 159, 108);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_cn_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "制冷");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 227, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_popup_button_fan_high_off_background_image);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 150, 180);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_popup_button_fan_level_down_off_background_image);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 152, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_popup_button_kt_off_background_image);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 48, 210);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 60);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_popup_button_mode_cold_off_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_popup_button_mode_cold_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &img_popup_button_mode_cold_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &img_popup_button_mode_cold_off_background_image, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj3, LV_EVENT_ALL, NULL);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.v = obj;
            lv_obj_set_pos(obj, 161, 143);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25\xC2\xB0""C");
        }
    }
}

void tick_screen_main() {
}

void create_screen_cold() {
    lv_obj_t *obj = lv_obj_create(NULL);
    objects.cold = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 360, 360);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.snow = obj;
            lv_obj_set_pos(obj, 36, 132);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 60);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_popup_button_mode_cold_off_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_popup_button_mode_cold_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &img_popup_button_mode_cold_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &img_popup_button_mode_cold_off_background_image, NULL);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 66, 222);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 60);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_popup_button_mode_set_back_background_image, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_cold_obj4, LV_EVENT_ALL, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 75, 48);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 60);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_popup_button_mode_hum_off_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_popup_button_mode_hum_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &img_popup_button_mode_hum_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &img_popup_button_mode_hum_off_background_image, NULL);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 180, 48);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 60);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_popup_button_mode_flash_off_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_popup_button_mode_flash_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &img_popup_button_mode_flash_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &img_popup_button_mode_flash_off_background_image, NULL);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 270, 113);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 60);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_popup_button_mode_hot_off_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_popup_button_mode_hot_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &img_popup_button_mode_hot_on_background_image, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &img_popup_button_mode_hot_off_background_image, NULL);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
    }

    lv_obj_add_event_cb(obj, cold_screen_loaded_cb, LV_EVENT_SCREEN_LOADED, NULL);
}

void tick_screen_cold() {
}

typedef void (*tick_screen_func_t)(void);
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_mode,
    tick_screen_main,
    tick_screen_cold,
};

void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 3) {
        tick_screen_funcs[screen_index]();
    }
}

void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

/* ===========================================================================
 * 统一创建入口
 * =========================================================================*/

void create_screens(void) {
    create_screen_mode();
    create_screen_main();
    create_screen_cold();
}
