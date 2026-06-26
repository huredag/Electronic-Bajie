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
 * @date     2026-06-25
 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <drv/uart.h>
#include <drv/tick.h>
#include <drv/irq.h>
#include "board_config.h"
#include "board_init.h"
#include "ST77916.h"
#include "CST816.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "screens.h"

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
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    /* 4. 创建 EEZ 界面并加载主屏 */
    create_screens();
    lv_scr_load(objects.main);

    printf("LVGL started, tick=%lu ms\r\n", (unsigned long)csi_tick_get_ms());

    /* 5. 主循环：持续驱动 LVGL 定时器处理（刷新、动画、事件） */
    uint32_t loop_cnt = 0;
    uint32_t last_print = 0;
    while (1) {
        lv_timer_handler();
        mdelay(5);

        loop_cnt++;
        uint32_t now = (uint32_t)csi_tick_get_ms();
        if (now - last_print >= 2000) {
            lv_mem_monitor_t mon;
            lv_mem_monitor(&mon);
            printf("[%lu ms] loop=%lu, mem used=%lu%%, frag=%lu%%\r\n",
                   (unsigned long)now,
                   (unsigned long)loop_cnt,
                   (unsigned long)mon.used_pct,
                   (unsigned long)mon.frag_pct);
            last_print = now;
        }
    }

    return 0;
}
