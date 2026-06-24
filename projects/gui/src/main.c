

/******************************************************************************
 * @file     main.c
 * @brief    GUI 主程序：ST77916 QSPI 屏 + CST816 触摸 + LVGL
 * @version  V2.0
 * @date     2026-06-23
 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <drv/uart.h>
#include <drv/tick.h>
#include "board_config.h"
#include "board_init.h"
#include "ST77916.h"
#include "CST816.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

static void lv_demo_hello(void)
{
    /* 诊断测试：红色背景验证数据通路 */
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_make(0xFF, 0x00, 0x00), 0);
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);

    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello LVGL!");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

int main(void)
{
    board_init();
    printf("Hello World!\n");

    /* 1. 初始化 LCD */
    LCD_Init();

    /* 2. 初始化触摸 */
    Touch_Init();

    /* 3. 初始化 LVGL */
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    /* 4. 创建一个简单界面验证 LVGL 跑通 */
    lv_demo_hello();

    printf("LVGL started, tick=%lu ms\r\n", (unsigned long)csi_tick_get_ms());

    /* 5. 主循环 */
    while (1) {
        lv_timer_handler();
        mdelay(5);
    }

    return 0;
}
