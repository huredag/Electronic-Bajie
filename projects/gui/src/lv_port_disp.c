/******************************************************************************
 * @file     lv_port_disp.c
 * @brief    LVGL 显示驱动适配（TD1601 + ST77916 360x360 QSPI）
 *
 *  适配说明：
 *    - LVGL 通过 flush_cb 回调将渲染好的像素块送到屏幕
 *    - 底层调用 LCD_addWindow() 走 QSPI 四线写显存
 *    - 显示 buffer 采用单 buffer 模式，每次刷新 20 行（节省 RAM）
 *
 *  调用关系：
 *    main.c -> lv_port_disp_init() -> 注册显示驱动
 *    LVGL 内部 -> disp_flush() -> LCD_addWindow() -> QSPI 发送像素
 *
 * @version  V1.0
 * @date     2026-06-23
 ******************************************************************************/

#include "lv_port_disp.h"
#include "ST77916.h"

/* ===========================================================================
 * 显示参数
 * =========================================================================*/
#define DISP_HOR_RES EXAMPLE_LCD_WIDTH      /* 水平分辨率 360 */
#define DISP_VER_RES EXAMPLE_LCD_HEIGHT     /* 垂直分辨率 360 */
#define DISP_BUF_LINES 20                   /* 显示 buffer 行数（越大越快但占 RAM 越多） */

/* ===========================================================================
 * 静态变量
 * =========================================================================*/
static lv_disp_drv_t disp_drv;              /* LVGL 显示驱动描述符 */
static lv_disp_draw_buf_t draw_buf;         /* LVGL 绘图缓冲区管理结构 */
static lv_color_t buf1[DISP_HOR_RES * DISP_BUF_LINES]; /* 绘图缓冲区（360*20*2=14400字节） */

/* ===========================================================================
 * 显示刷新回调
 * =========================================================================*/

/**
 * \brief      Display flush callback
 *             LVGL 渲染完一块区域后调用此函数，将像素数据送到 LCD 显存。
 *             完成后必须调用 lv_disp_flush_ready() 通知 LVGL 可以继续渲染。
 * \param[in]  drv      显示驱动指针（LVGL 内部传入）
 * \param[in]  area     本次刷新的矩形区域（x1,y1 ~ x2,y2）
 * \param[in]  color_p  指向 RGB565 像素数据的指针
 */
static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
{
    LCD_addWindow(area->x1, area->y1, area->x2, area->y2, (uint16_t *)color_p);
    lv_disp_flush_ready(drv);
}

/* ===========================================================================
 * 对外接口
 * =========================================================================*/

/**
 * \brief      Display port initialization
 *             初始化 LVGL 显示驱动，设置分辨率、buffer、刷新回调并注册。
 *             调用前需确保 LCD 硬件已初始化（LCD_Init() 已执行）。
 */
void lv_port_disp_init(void)
{
    /* 初始化绘图缓冲区：单 buffer 模式，大小 = 360 * 20 像素 */
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, DISP_HOR_RES * DISP_BUF_LINES);

    /* 初始化并配置显示驱动 */
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res  = DISP_HOR_RES;      /* 水平分辨率 */
    disp_drv.ver_res  = DISP_VER_RES;      /* 垂直分辨率 */
    disp_drv.flush_cb = disp_flush;         /* 刷新回调 */
    disp_drv.draw_buf = &draw_buf;          /* 绑定绘图缓冲区 */
    lv_disp_drv_register(&disp_drv);        /* 注册到 LVGL */
}
