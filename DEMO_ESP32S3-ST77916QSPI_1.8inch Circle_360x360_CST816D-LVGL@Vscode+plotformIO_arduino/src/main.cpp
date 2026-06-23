/*************************************************************************************************
 ****@CompanyName  : 深圳市沃乐康科技有限公司
 ****@FileName     : ESP32S3-ST77916QSPI_1.8inch Circle_360x360_CST816D-LVGL@Vscode+plotformIO_arduino
 ****@Description  : 基于ESP32S3R8N16主控在Vscode+plotformIO_arduino框架环境下 使用TFT-eSPI库用QSPI接口模式驱动ST77916 360*360圆屏 触摸CST9217 演示LVGL V8例程
 ****@Contact      : www.wlklcd.com   https://wlklcd.1688.com/  0755-32882855   
 *                               接线图             
 *                SPI-TFT屏幕 -------------- ESP32C3
 *                       GND --------------  Gnd
 *                       VCC --------------- 3.3
 *                       SCK  -------------- IO21   SPI时钟脚
 *                       MOSI/SDA0 --------- IO47   QSPI数据0
 *                       RES --------------  IO45   复位脚
 *                       DC/SDA1  ---------- IO40   QSPI数据1
 *                       CS  --------------  IO41   片选脚
 *                       BLC --------------  IO42   低电平背光亮，高电平背光灭
 *                       SDA2 -------------  IO46   QSPI数据2
 *                       SDA3 -------------  IO48   QSPI数据3
 *               TOUCH   CTP-SDA ----------  IO11   触摸IIC 数据脚
 *               TOUCH   CTP-SCL ----------  IO12   触摸IIC 时钟脚
 *               TOUCH   CTP-RST ----------  IO13   触摸复位脚
 *               TOUCH   CTP-INT ----------  IO14   触摸中断脚
 * 以上为带底板排针的模块接法， 裸屏参照规格书依次类推。
 * 需要显示屏请联系咨询，企业淘宝店：https://shop341012592.taobao.com/   
**************************************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////
//说明:  我们是屏幕生产厂家 不是做嵌入式开发的,写代码不是我们的专业, 虽然例程在我们手上已验证OK, 
//       但因为我们写程序的不专业, 也没有做严格校对.难免会有格式 语法错误 以及一些编译警告.
//       请老师高手不吝指正，谢谢。
//       有时变更了代码没有修改注释，请以代码定义为准，不要只看注释。
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include "demos\lv_demos.h"

#include <CST816S.h>
CST816S touch(11, 12, 13, 14);   //int sda, int scl, int rst, int irq


#define GFX_BL DF_GFX_BL // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

//Arduino_DataBus *bus = new Arduino_ESP32SPI(40 /* DC */,41 /* CS */, 21 /* SCK */, 47 /* MOSI */);                                   //SPI模式 
Arduino_DataBus *bus = new Arduino_ESP32QSPI(41 /* CS */, 21 /* SCK */, 47 /* D0 */, 40 /* D1 */, 46 /* D2 */, 48 /* D3 */);       //QSPI模式
Arduino_GFX *gfx = new Arduino_ST77916(bus, 45/* RES */, 0 /* rotation */, true /* IPS */);


/*Change to your screen resolution*/
static const uint16_t screenWidth  = 360;
static const uint16_t screenHeight = 360;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight/10 ];

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
#ifndef DIRECT_MODE
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif
#endif // #ifndef DIRECT_MODE

  lv_disp_flush_ready(disp_drv);
}



void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
  //Serial.println("Data x ");
 // uint16_t touchX, touchY;

  //bool touched = tft.getTouch(&touchX, &touchY, 600);
 //bool a=1;
  if (!touch.available())
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touch.data.x;
    data->point.y = touch.data.y;
    /*Set the coordinates*/
    // data->point.x = touchX * 1.33;
    // data->point.y = touchY * 0.75;
  }
}

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println( LVGL_Arduino );
     
    touch.begin();
    lv_init();

      // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
    gfx->setRotation(0); /* Landscape orientation, flipped */
    
    pinMode(DF_GFX_BL,OUTPUT);
    digitalWrite(DF_GFX_BL,LOW);


    /*Set the touchscreen calibration data,
     the actual data for your display can be acquired using
     the Generic -> Touch_calibrate example from the TFT_eSPI library*/
    //uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
    //tft.setTouch( calData );

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight/10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );
  
    /* Create simple label */
    lv_obj_t *label = lv_label_create( lv_scr_act() );
    lv_label_set_text( label, "Hello Ardino and LVGL!");
    lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
 
    /* Try an example. See all the examples 
     * online: https://docs.lvgl.io/master/examples.html
     * source codes: https://github.com/lvgl/lvgl/tree/e7f88efa5853128bf871dde335c0ca8da9eb7731/examples */
     //lv_example_btn_1();
   
     /*Or try out a demo. Don't forget to enable the demos in lv_conf.h. E.g. LV_USE_DEMOS_WIDGETS*/
      lv_demo_widgets();               
     //lv_demo_benchmark();          
     //lv_demo_keypad_encoder();     
     //lv_demo_music();              
     //lv_demo_printer();
    // lv_demo_stress();
    
    Serial.println( "Setup done" );
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay( 5 );
}
