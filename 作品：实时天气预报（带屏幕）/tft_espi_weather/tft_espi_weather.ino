#include <Arduino.h>
#include <ArduinoJson.h>

//连接wifi用的库
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

//从ntp服务器更新时间(依赖 ntp 库)
#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com");

#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

#include "hefeng-min-40px.h"
#include "weather_font20.h"
#include "weather_font16.h"
#include "animation.h"

//#include "calender.h"

/******************以下为程序可配置项*******************************/

/**
   你的wifi 账号和密码
   注意：切勿连接 5G的频率、不要使用双频融合（路由器）
   注意：账号密码必须完全正确，包括字母大小写、空格、中划线、下划线
*/
const char* ssid     = "1024";
const char* password = "12345678";

//来自和风天气的密钥
const String auth = "9605c835665d4eea89ecef73627abd91";

//你的城市ID，获取方法参考课程
const String cityid = "101070102";

#include "sht30.h"
#include "wifi.h"
#include "ntptime.h"
#include "weather.h"

unsigned long last_ntp = 0;
const long interval_ntp = 1000; //时间的刷新频率（毫秒）

//天气的刷新频率
unsigned long last_weather = 0;
const long interval_weather = 1000 * 60 * 5; //时间的刷新频率（毫秒）

//明日天气的刷新频率
unsigned long last_tmr_weather = 0;
const long interval_tmr_weather = 1000 * 60 * 60; //时间的刷新频率（毫秒）

//温湿度传感器的刷新频率
unsigned long last_sht = 0;
const long interval_sht = 3000; //时间的刷新频率（毫秒）

//动画的刷新频率
long last_animation = 0;
long interval_animation = 40;

uint8_t animation_step = 0;

bool btn_state = false;

void setup() {

  Serial.begin(115200);

  tft.init();
  tft.setSwapBytes(true);
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);

  tft.setTextSize(2);

  //联网
  tft.println("Wi-Fi >> " + String(ssid));
  initWiFi();

  tft.println("");

  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
  //对时
  tft.println("Get NTP Time");
  initNtp();

  tft.println("");

  //今日天气
  tft.println("Get Today weather");
  getWeather();

  tft.setTextSize(1);
  tft.println("");
  tft.setTextSize(2);

  //未来三天的天气
  tft.println("Get Tomorrow weather");
  getTmrWeather();

  //温湿度传感器
  tft.println("");
  tft.println("load Sensor Data..");
  sht30_setup();

  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
  tft.println("");
  tft.println("start...");

  delay(500);
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  //获取单片机启动至今的毫秒数
  unsigned long currentMillis = millis();

  //update ntp 时间
  if (last_ntp == 0 || currentMillis - last_ntp >= interval_ntp) {

    last_ntp = currentMillis;
    loopNtp();

    tft.loadFont(weather_font16);
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.drawString(dt.localDate + "  " + weekOfDate1(dt.year, dt.month, dt.day) + " " + outputLunarDate(dt.year, dt.month, dt.day), 0, 0);
    tft.unloadFont();

    tft.setTextSize(5);
    tft.setTextColor(TFT_GREEN, TFT_BLACK, true);
    tft.drawString(dt.localTime, 0, 30);
  }

  //今日天气
  if (last_weather == 0 || currentMillis - last_weather >= interval_weather) {
    if (last_weather > 0) {
      getWeather();
    }
    last_weather = currentMillis;

    //擦除指定区域
    tft.fillRect(55, 90, 240, 40, TFT_BLACK);

    tft.setTextColor(TFT_YELLOW, TFT_BLACK, true);
    tft.loadFont(hefeng40);
    tft.drawString(icon(wd.now_icon), 10, 90);
    tft.unloadFont();

    tft.loadFont(weather_font20);
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.drawString(String(wd.now_temp) + "° " + wd.now_text, 55, 90);
    tft.drawString(wd.now_windDir + "" + String(wd.now_windScale) + "级 " + wd.now_windSpeed + "/KM", 55, 110);

    tft.drawLine(0, 140, 240, 140, TFT_WHITE);
  }

  //明日天气
  if (last_tmr_weather == 0 || currentMillis - last_tmr_weather > interval_tmr_weather) {
    if (last_tmr_weather > 0) {
      getTmrWeather();
    }
    last_tmr_weather = currentMillis;

    //擦除指定区域
    tft.fillRect(55, 150, 240, 40, TFT_BLACK);

    tft.loadFont(hefeng40);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK, true);
    tft.drawString(icon(wtd.iconDay), 10, 150);
    tft.unloadFont();

    tft.loadFont(weather_font20);
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.drawString("明天 " + String(wtd.tempMin) + "° - " + String(wtd.tempMax) + "°", 55, 150);
    tft.drawString(wtd.textDay, 55, 170);

    //这条线其实没必要重新绘制
    tft.drawLine(0, 200, 240, 200, TFT_WHITE);
  }

  //温湿度传感器的数据
  if (last_sht == 0 || currentMillis - last_sht > interval_sht) {
    last_sht = currentMillis;

    sht30();

    tft.loadFont(weather_font20);
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);

    tft.drawString("室温：", 0, 210);
    tft.setTextColor(TFT_GREEN, TFT_BLACK, true);
    tft.drawString(String(sht_data.temperature), 40, 210);

    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.drawString("湿度：", 80, 210);

    tft.setTextColor(TFT_GREEN, TFT_BLACK, true);
    tft.drawString(String(sht_data.humidity), 123, 210); //+3（原为120）的x轴位置，因为视觉上似乎贴的优点近了
  }

  //动画
  if (last_animation == 0 || currentMillis - last_animation > interval_animation) {
    last_animation = currentMillis;
    tft.pushImage(180, 166, animation_w, animation_h, animation[animation_step]);
    animation_step++;
    if (animation_step == animation_frame) {
      animation_step = 0;
    }
  }
}
