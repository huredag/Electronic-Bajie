/******************************************************************************
 * @file     lv_port_indev.c
 * @brief    LVGL 输入设备适配（TD1601 + CST816 电容触摸）
 *
 *  适配说明：
 *    - LVGL 通过 read_cb 回调定期轮询触摸状态
 *    - 底层调用 Touch_Poll() 读取 CST816 的触摸坐标
 *    - 触摸类型为 POINTER（单点触摸），适用于按钮/滑条等标准控件
 *
 *  调用关系：
 *    main.c -> lv_port_indev_init() -> 注册输入设备
 *    LVGL 内部 -> touchpad_read() -> Touch_Poll() -> I2C 读取 CST816
 *
 * @version  V1.0
 * @date     2026-06-23
 ******************************************************************************/

#include "lv_port_indev.h"
#include "CST816.h"

/* ===========================================================================
 * 静态变量
 * =========================================================================*/
static lv_indev_drv_t indev_drv;    /* LVGL 输入设备驱动描述符 */

/* ===========================================================================
 * 触摸读取回调
 * =========================================================================*/

/**
 * \brief      Touchpad read callback
 *             LVGL 每隔 LV_INDEV_DEF_READ_PERIOD(50ms) 调用一次，
 *             查询触摸芯片是否有手指按下，并返回坐标。
 * \param[in]  drv   输入设备驱动指针（LVGL 内部传入）
 * \param[out] data  输出触摸数据：坐标 + 按下/释放状态
 */
static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    cst816_data_t touch;

    if (Touch_Poll(&touch)) {
        data->point.x = touch.x;        /* 触摸 X 坐标 */
        data->point.y = touch.y;        /* 触摸 Y 坐标 */
        data->state   = LV_INDEV_STATE_PRESSED;
        // printf("touch: x=%d y=%d points=%d\r\n",  data->point.x, data->point.y, touch.points);

    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

/* ===========================================================================
 * 对外接口
 * =========================================================================*/

/**
 * \brief      Input device port initialization
 *             初始化 LVGL 触摸输入设备，设置类型和读取回调并注册。
 *             调用前需确保触摸硬件已初始化（Touch_Init() 已执行）。
 */
void lv_port_indev_init(void)
{
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;  /* 单点触摸类型 */
    indev_drv.read_cb = touchpad_read;          /* 读取回调 */
    lv_indev_drv_register(&indev_drv);          /* 注册到 LVGL */
}
