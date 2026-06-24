/**
 * @file lv_port_disp.c
 * @brief LVGL display driver porting for ST77916 360x360 QSPI (TD1601)
 */

#include "lv_port_disp.h"
#include "ST77916.h"

#define DISP_HOR_RES EXAMPLE_LCD_WIDTH
#define DISP_VER_RES EXAMPLE_LCD_HEIGHT
#define DISP_BUF_LINES 20

static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[DISP_HOR_RES * DISP_BUF_LINES];

static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
{
    LCD_addWindow(area->x1, area->y1, area->x2, area->y2, (uint16_t *)color_p);
    lv_disp_flush_ready(drv);
}

void lv_port_disp_init(void)
{
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, DISP_HOR_RES * DISP_BUF_LINES);

    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res  = DISP_HOR_RES;
    disp_drv.ver_res  = DISP_VER_RES;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}
