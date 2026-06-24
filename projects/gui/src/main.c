/******************************************************************************
 * @file     main.c
 * @brief    GUI 主程序：ST77916 QSPI 屏 + CST816 触摸 + LVGL
 *
 *  系统架构：
 *    TD1601 (E906FD RISC-V, 48MHz, 192KB SRAM)
 *    ├── ST77916  360x360 圆屏，QSPI 四线接口（DW_OSPI0）
 *    ├── CST816   电容触摸，I2C 接口
 *    └── LVGL v8.3.11 图形库
 *
 *  初始化流程：
 *    board_init() -> LCD_Init() -> Touch_Init() -> lv_init()
 *    -> lv_port_disp_init() -> lv_port_indev_init() -> 创建 UI
 *
 *  主循环：
 *    lv_timer_handler() 驱动 LVGL 内部定时器（刷新、动画、输入读取）
 *    mdelay(5) 让出 CPU，约 5ms 一轮（实际刷新率由 LV_DISP_DEF_REFR_PERIOD 控制）
 *
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

/* ===========================================================================
 * 演示界面
 * =========================================================================*/

/**
 * \brief      Hello LVGL demo
 *             创建一个简单界面验证 LVGL 是否跑通：
 *             红色全屏背景 + 白色居中文字 "Hello LVGL!"
 */
static void lv_demo_hello(void)
{
    /* 设置屏幕背景为红色（诊断用途：如果看到红屏说明显示通路正常） */
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_make(0xFF, 0x00, 0x00), 0);
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, 0);

    /* 创建居中白色标签 */
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello LVGL!");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

/* ===========================================================================
 * 主函数
 * =========================================================================*/
int main(void)
{
    board_init();
    printf("Hello World!\n");

    /* 1. 初始化 LCD（复位 + OSPI + 命令表 + 背光 + 清屏） */
    LCD_Init();

    /* 2. 初始化触摸（I2C + CST816 配置） */
    Touch_Init();

    /* 3. 初始化 LVGL 核心 + 显示/输入驱动适配 */
    lv_init();                  /* LVGL 内核初始化（内存池、定时器等） */
    lv_port_disp_init();        /* 注册显示驱动（flush_cb -> LCD_addWindow） */
    lv_port_indev_init();       /* 注册输入设备（read_cb -> Touch_Poll） */

    /* 4. 创建演示界面 */
    lv_demo_hello();

    printf("LVGL started, tick=%lu ms\r\n", (unsigned long)csi_tick_get_ms());

    /* 5. 主循环：持续驱动 LVGL 定时器处理（刷新、动画、事件） */
    while (1) {
        lv_timer_handler();     /* LVGL 心跳：处理刷新、动画、输入等 */
        mdelay(5);              /* 让出 CPU，5ms 间隔 */
    }

    return 0;
}
