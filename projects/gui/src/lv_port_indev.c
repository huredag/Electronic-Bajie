/**
 * @file lv_port_indev.c
 * @brief LVGL input device porting for CST816 touch (TD1601)
 */

#include "lv_port_indev.h"
#include "CST816.h"

static lv_indev_drv_t indev_drv;

static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    cst816_data_t touch;

    if (Touch_Poll(&touch)) {
        data->point.x = touch.x;
        data->point.y = touch.y;
        data->state   = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void lv_port_indev_init(void)
{
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    lv_indev_drv_register(&indev_drv);
}
