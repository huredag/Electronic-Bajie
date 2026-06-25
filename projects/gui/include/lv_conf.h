/******************************************************************************
 * @file     lv_conf.h
 * @brief    LVGL v8.3.11 配置文件（TD1601 + ST77916 360x360 圆屏专用）
 *
 *  硬件平台：
 *    MCU:     TD1601 (T-Head E906FD RISC-V, 48MHz, 192KB SRAM)
 *    显示屏:  ST77916 360x360 RGB565 QSPI 圆形 LCD
 *    触摸:    CST816 电容触摸（I2C）
 *
 *  资源分配：
 *    - LVGL 内存池: 32KB（从 192KB SRAM 中划拨）
 *    - 显示 buffer: 360*20*2 = 14.4KB（在 lv_port_disp.c 中分配）
 *    - 字体: 仅启用 Montserrat 14/16，节省 Flash
 *
 *  调优要点：
 *    - LV_MEM_SIZE 决定能同时创建多少控件，32KB 约够中等复杂度界面
 *    - LV_DISP_DEF_REFR_PERIOD 决定刷新率，33ms ≈ 30fps
 *    - LV_INDEV_DEF_READ_PERIOD 决定触摸采样率，50ms = 20Hz
 *    - 未使用的控件/主题/字体全部关闭以节省 Flash 和 RAM
 *
 * @version  V1.0
 * @date     2026-06-23
 ******************************************************************************/

#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

/* ===========================================================================
 * 颜色设置
 *   ST77916 使用 RGB565 格式，16bit 色深，不需要字节交换（MCU 小端与屏一致）
 * =========================================================================*/
#define LV_COLOR_DEPTH 16               /* 色深：16bit RGB565 */
#define LV_COLOR_16_SWAP 0              /* 字节序：0=不交换（小端 MCU 直连） */
#define LV_COLOR_SCREEN_TRANSP 0        /* 屏幕透明度：0=不支持（节省内存） */
#define LV_COLOR_MIX_ROUND_OFS 0        /* 颜色混合舍入偏移 */
#define LV_COLOR_CHROMA_KEY lv_color_hex(0x00ff00)  /* 色键（图片透明色） */

/* ===========================================================================
 * 内存设置
 *   LVGL 内部有自己的内存管理器（lv_mem），从这里划拨一块静态内存池。
 *   所有控件、样式、动画等都从这个池子里分配。
 *   32KB 对于中等界面（几十个控件）够用，复杂界面需增大。
 * =========================================================================*/
#define LV_MEM_CUSTOM 0                 /* 0=使用 LVGL 内置内存池, 1=用系统 malloc */
#if LV_MEM_CUSTOM == 0
    #define LV_MEM_SIZE (32U * 1024U)   /* 内存池大小：32KB */
    #define LV_MEM_ADR 0                /* 0=编译器自动分配地址 */
    #if LV_MEM_ADR == 0
        #undef LV_MEM_POOL_INCLUDE
        #undef LV_MEM_POOL_ALLOC
    #endif
#else
    #define LV_MEM_CUSTOM_INCLUDE <stdlib.h>
    #define LV_MEM_CUSTOM_ALLOC   malloc
    #define LV_MEM_CUSTOM_FREE    free
    #define LV_MEM_CUSTOM_REALLOC realloc
#endif

#define LV_MEM_BUF_MAX_NUM 16           /* 最大临时 buffer 数量 */
#define LV_MEMCPY_MEMSET_STD 1          /* 1=使用标准库 memcpy/memset（通常更快） */

/* ===========================================================================
 * HAL（硬件抽象层）设置
 *   定义 LVGL 与硬件交互的时间参数
 * =========================================================================*/
#define LV_DISP_DEF_REFR_PERIOD 33      /* 显示刷新周期(ms)：33ms ≈ 30fps */
#define LV_INDEV_DEF_READ_PERIOD 50     /* 输入设备读取周期(ms)：50ms = 20Hz 触摸采样 */

/* LVGL 需要一个毫秒级时钟源作为心跳，这里用 CSI 的 tick 定时器 */
#define LV_TICK_CUSTOM 1                /* 1=使用自定义 tick 源（而非 LVGL 内部计数） */
#if LV_TICK_CUSTOM
    #define LV_TICK_CUSTOM_INCLUDE "drv/tick.h"
    #define LV_TICK_CUSTOM_SYS_TIME_EXPR ((uint32_t)csi_tick_get_ms())
#endif

#define LV_DPI_DEF 160                  /* 屏幕 DPI（影响默认控件尺寸） */

/* ===========================================================================
 * 绘图功能配置
 *   控制绘图引擎的高级功能开关和缓存大小
 * =========================================================================*/
#define LV_DRAW_COMPLEX 1               /* 1=启用复杂绘图（阴影、渐变、圆弧等） */
#if LV_DRAW_COMPLEX != 0
    #define LV_SHADOW_CACHE_SIZE 0      /* 阴影缓存：0=不缓存（省 RAM，速度稍慢） */
    #define LV_CIRCLE_CACHE_SIZE 4      /* 圆弧缓存：缓存 4 种半径 */
#endif

#define LV_LAYER_SIMPLE_BUF_SIZE          (4 * 1024)    /* 简单图层 buffer */
#define LV_LAYER_SIMPLE_FALLBACK_BUF_SIZE (1 * 1024)    /* 图层回退 buffer */

#define LV_IMG_CACHE_DEF_SIZE 0         /* 图片缓存数：0=不缓存 */
#define LV_GRADIENT_MAX_STOPS 2         /* 渐变最大色标数 */
#define LV_GRAD_CACHE_DEF_SIZE 0        /* 渐变缓存：0=不缓存 */
#define LV_DITHER_GRADIENT 0            /* 渐变抖动：0=关闭 */
#define LV_DISP_ROT_MAX_BUF (10*1024)   /* 屏幕旋转用的最大 buffer */

/*-------------
 * GPU 加速
 *   TD1601 没有 GPU，全部关闭
 *-----------*/
#define LV_USE_GPU_ARM2D 0
#define LV_USE_GPU_STM32_DMA2D 0
#define LV_USE_GPU_RA6M3_G2D 0
#define LV_USE_GPU_SWM341_DMA2D 0
#define LV_USE_GPU_NXP_PXP 0
#define LV_USE_GPU_NXP_VG_LITE 0
#define LV_USE_GPU_SDL 0

/* ===========================================================================
 * 日志设置
 *   开发阶段可开启日志辅助调试，发布时关闭以节省 Flash 和 CPU
 * =========================================================================*/
#define LV_USE_LOG 1                    /* 1=启用日志 */
#if LV_USE_LOG
    #define LV_LOG_LEVEL LV_LOG_LEVEL_WARN  /* 日志级别：WARN 及以上才输出 */
    #define LV_LOG_PRINTF 1             /* 1=用 printf 输出日志 */
    /* 各模块 trace 开关（0=关闭，调试特定模块时可打开） */
    #define LV_LOG_TRACE_MEM        0   /* 内存分配追踪 */
    #define LV_LOG_TRACE_TIMER      0   /* 定时器追踪 */
    #define LV_LOG_TRACE_INDEV      0   /* 输入设备追踪 */
    #define LV_LOG_TRACE_DISP_REFR  0   /* 显示刷新追踪 */
    #define LV_LOG_TRACE_EVENT      0   /* 事件追踪 */
    #define LV_LOG_TRACE_OBJ_CREATE 0   /* 对象创建追踪 */
    #define LV_LOG_TRACE_LAYOUT     0   /* 布局追踪 */
    #define LV_LOG_TRACE_ANIM       0   /* 动画追踪 */
#endif

/* ===========================================================================
 * 断言设置
 *   开发阶段用断言捕获错误，发布时可关闭以减小代码体积
 * =========================================================================*/
#define LV_USE_ASSERT_NULL          1   /* 空指针检查 */
#define LV_USE_ASSERT_MALLOC        1   /* 内存分配失败检查 */
#define LV_USE_ASSERT_STYLE         0   /* 样式合法性检查 */
#define LV_USE_ASSERT_MEM_INTEGRITY 0   /* 内存完整性检查（很慢，仅调试用） */
#define LV_USE_ASSERT_OBJ           0   /* 对象合法性检查 */

#define LV_ASSERT_HANDLER_INCLUDE <stdint.h>
#define LV_ASSERT_HANDLER while(1);     /* 断言失败后死循环（方便 JTAG 调试） */

/* ===========================================================================
 * 调试/监控工具
 * =========================================================================*/
#define LV_USE_PERF_MONITOR 0           /* 性能监视器：0=关闭（避免频繁分配内存导致碎片化崩溃） */
#if LV_USE_PERF_MONITOR
    #define LV_USE_PERF_MONITOR_POS LV_ALIGN_BOTTOM_MID /* 显示位置：屏幕底部居中 */
#endif

#define LV_USE_MEM_MONITOR 0            /* 内存监视器：0=关闭 */
#define LV_USE_REFR_DEBUG 0             /* 刷新区域高亮：0=关闭 */

/* ===========================================================================
 * 格式化输出
 *   使用标准库 snprintf 替代 LVGL 内置实现（更可靠）
 * =========================================================================*/
#define LV_SPRINTF_CUSTOM 1
#if LV_SPRINTF_CUSTOM
    #define LV_SPRINTF_INCLUDE <stdio.h>
    #define lv_snprintf  snprintf
    #define lv_vsnprintf vsnprintf
#else
    #define LV_SPRINTF_USE_FLOAT 0
#endif

#define LV_USE_USER_DATA 1              /* 允许对象携带用户自定义数据指针 */
#define LV_ENABLE_GC 0                  /* 垃圾回收：0=不使用（MicroPython 才需要） */

/* ===========================================================================
 * 编译器设置
 *   针对 RISC-V E906 的对齐和属性配置
 * =========================================================================*/
#define LV_BIG_ENDIAN_SYSTEM 0          /* 小端序（RISC-V 默认小端） */
#define LV_ATTRIBUTE_TICK_INC
#define LV_ATTRIBUTE_TIMER_HANDLER
#define LV_ATTRIBUTE_FLUSH_READY
#define LV_ATTRIBUTE_MEM_ALIGN_SIZE 4   /* 内存对齐：4 字节 */
#define LV_ATTRIBUTE_MEM_ALIGN __attribute__((aligned(4)))
#define LV_ATTRIBUTE_LARGE_CONST
#define LV_ATTRIBUTE_LARGE_RAM_ARRAY
#define LV_ATTRIBUTE_FAST_MEM
#define LV_ATTRIBUTE_DMA
#define LV_EXPORT_CONST_INT(int_value) struct _silence_gcc_warning
#define LV_USE_LARGE_COORD 0            /* 坐标范围：0=int16_t 够用（屏幕 360px） */

/* ===========================================================================
 * 字体设置
 *   每启用一个字体都会占用 Flash，按需开启。
 *   Montserrat 是 LVGL 默认英文字体，数字代表像素高度。
 *   中文字体需要额外添加（LVGL 不内置）。
 * =========================================================================*/
#define LV_FONT_MONTSERRAT_8  0
#define LV_FONT_MONTSERRAT_10 0
#define LV_FONT_MONTSERRAT_12 0
#define LV_FONT_MONTSERRAT_14 1         /* 启用：14px，用作默认字体 */
#define LV_FONT_MONTSERRAT_16 1         /* 启用：16px，稍大号 */
#define LV_FONT_MONTSERRAT_18 0
#define LV_FONT_MONTSERRAT_20 0
#define LV_FONT_MONTSERRAT_22 0
#define LV_FONT_MONTSERRAT_24 0
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 0
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 0
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 0
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 0

#define LV_FONT_MONTSERRAT_12_SUBPX      0  /* 亚像素渲染版本 */
#define LV_FONT_MONTSERRAT_28_COMPRESSED 0  /* 压缩版本（省 Flash） */
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW 0  /* 波斯/希伯来语字体 */
#define LV_FONT_SIMSUN_16_CJK            0  /* 宋体中日韩字体（CJK 很大，按需开） */

#define LV_FONT_UNSCII_8  0             /* 像素风格小字体 */
#define LV_FONT_UNSCII_16 0

#define LV_FONT_CUSTOM_DECLARE                          /* 自定义字体声明（暂无） */
#define LV_FONT_DEFAULT &lv_font_montserrat_14          /* 全局默认字体 */
#define LV_FONT_FMT_TXT_LARGE 0         /* 大字体支持：0=不需要 */
#define LV_USE_FONT_COMPRESSED 0         /* 字体压缩：0=不使用 */
#define LV_USE_FONT_SUBPX 0             /* 亚像素渲染：0=不使用 */
#define LV_USE_FONT_PLACEHOLDER 1        /* 缺字时显示占位符 □ */

/* ===========================================================================
 * 文本设置
 * =========================================================================*/
#define LV_TXT_ENC LV_TXT_ENC_UTF8      /* 文本编码：UTF-8 */
#define LV_TXT_BREAK_CHARS " ,.;:-_"    /* 允许换行的字符 */
#define LV_TXT_LINE_BREAK_LONG_LEN 0    /* 长单词强制换行：0=不启用 */
#define LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN 3
#define LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN 3
#define LV_TXT_COLOR_CMD "#"            /* 文本内嵌颜色标记符 */
#define LV_USE_BIDI 0                   /* 双向文本（阿拉伯语等）：0=不需要 */
#define LV_USE_ARABIC_PERSIAN_CHARS 0   /* 阿拉伯/波斯字符整形：0=不需要 */

/* ===========================================================================
 * 基础控件（Widget）
 *   这些是 LVGL 的核心 UI 元素，按需启用。
 *   每个控件都会占用一定 Flash，不用的关掉。
 * =========================================================================*/
#define LV_USE_ARC        1             /* 圆弧（进度环、旋钮背景等） */
#define LV_USE_BAR        1             /* 进度条 */
#define LV_USE_BTN        1             /* 按钮 */
#define LV_USE_BTNMATRIX  1             /* 按钮矩阵（键盘布局等） */
#define LV_USE_CANVAS     0             /* 画布（自由绘图，占 RAM 大） */
#define LV_USE_CHECKBOX   1             /* 复选框 */
#define LV_USE_DROPDOWN   1             /* 下拉选择框 */
#define LV_USE_IMG        1             /* 图片显示 */
#define LV_USE_LABEL      1             /* 文本标签（最常用） */
#if LV_USE_LABEL
    #define LV_LABEL_TEXT_SELECTION 0    /* 文本选择：0=不支持 */
    #define LV_LABEL_LONG_TXT_HINT 1    /* 长文本优化提示 */
#endif
#define LV_USE_LINE       1             /* 线条 */
#define LV_USE_ROLLER     1             /* 滚轮选择器 */
#define LV_USE_SLIDER     1             /* 滑动条 */
#define LV_USE_SWITCH     1             /* 开关 */
#define LV_USE_TEXTAREA   1             /* 文本输入框 */
#if LV_USE_TEXTAREA
    #define LV_TEXTAREA_DEF_PWD_SHOW_TIME 1500  /* 密码显示时间(ms) */
#endif
#define LV_USE_TABLE      1             /* 表格 */

/* ===========================================================================
 * 扩展控件（Extra Components）
 *   比基础控件更复杂的组合控件，占用更多 Flash
 * =========================================================================*/
#define LV_USE_ANIMIMG    0             /* 动画图片 */
#define LV_USE_CALENDAR   0             /* 日历 */
#define LV_USE_CHART      0             /* 图表（折线/柱状等） */
#define LV_USE_COLORWHEEL 0             /* 色轮选择器 */
#define LV_USE_IMGBTN     0             /* 图片按钮 */
#define LV_USE_KEYBOARD   0             /* 虚拟键盘 */
#define LV_USE_LED        0             /* LED 指示灯 */
#define LV_USE_LIST       1             /* 列表（菜单常用） */
#define LV_USE_MENU       0             /* 菜单（多级导航） */
#define LV_USE_METER      1             /* 仪表盘（表针、刻度） */
#define LV_USE_MSGBOX     1             /* 消息弹框 */
#define LV_USE_SPAN       0             /* 富文本（多样式混排） */
#define LV_USE_SPINBOX    0             /* 数字微调框 */
#define LV_USE_SPINNER    1             /* 加载转圈动画 */
#define LV_USE_TABVIEW    0             /* 标签页视图 */
#define LV_USE_TILEVIEW   0             /* 瓦片视图（滑动切页） */
#define LV_USE_WIN        0             /* 窗口 */

/* ===========================================================================
 * 主题
 *   主题决定控件的默认外观（颜色、圆角、间距等）
 * =========================================================================*/
#define LV_USE_THEME_DEFAULT 1          /* 默认主题（现代扁平风） */
#if LV_USE_THEME_DEFAULT
    #define LV_THEME_DEFAULT_DARK 0             /* 0=亮色主题 */
    #define LV_THEME_DEFAULT_GROW 0             /* 按钮按下放大效果：0=关闭 */
    #define LV_THEME_DEFAULT_TRANSITION_TIME 80 /* 状态切换动画时长(ms) */
#endif
#define LV_USE_THEME_BASIC 1            /* 基础主题（极简风格） */
#define LV_USE_THEME_MONO  0            /* 单色主题（墨水屏用） */

/* ===========================================================================
 * 布局引擎
 *   类似 CSS 的 Flexbox 和 Grid 布局，简化控件排列
 * =========================================================================*/
#define LV_USE_FLEX 1                   /* Flex 弹性布局（行/列排列） */
#define LV_USE_GRID 1                   /* Grid 网格布局（行列交叉） */

/* ===========================================================================
 * 内置 Demo
 *   LVGL 官方演示程序，学习时可打开对应开关
 *   注意：widgets demo 需要较多 RAM 和 Flash
 * =========================================================================*/
#define LV_USE_DEMO_WIDGETS 0           /* 控件展示 demo */
#define LV_USE_DEMO_BENCHMARK 0         /* 性能测试 demo */
#define LV_USE_DEMO_STRESS 0            /* 压力测试 demo */
#define LV_USE_DEMO_KEYPAD_AND_ENCODER 0 /* 键盘/编码器 demo */
#define LV_USE_DEMO_MUSIC 0             /* 音乐播放器 demo */

#endif /*LV_CONF_H*/
