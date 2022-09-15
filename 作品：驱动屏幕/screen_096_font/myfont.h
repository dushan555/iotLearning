/**
 * 一个二维数组的演示，取字模的时候大家可以参考
const uint8_t myImages[][每个字模的字符数] = {
  {字模的16进制内容},
  {字模的16进制内容},//每个花括号之间必须有逗号间隔
  {字模的16进制内容},
  {字模的16进制内容},
  {字模的16进制内容},
};  //末尾必须有;号

调用方法
u8g2.drawXBM(x坐标, y坐标, 宽度, 高度, 想显示的字模内容[第几个字模?]);
*/

const uint8_t myfonts[][128] = {
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x60, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xC0, 0xF0, 0xFF, 0x7F,
    0x60, 0xF0, 0xFF, 0x7F, 0x30, 0x30, 0x00, 0x60, 0x38, 0x32, 0x00, 0x60, 0x18, 0x37, 0x00, 0x60,
    0x0C, 0xF3, 0xFF, 0x7F, 0xFE, 0xF1, 0xFF, 0x7F, 0xFE, 0x30, 0x00, 0x60, 0xC0, 0x30, 0x00, 0x00,
    0x60, 0xB0, 0xFF, 0xFF, 0x30, 0xB0, 0xFF, 0xFF, 0x38, 0xB0, 0x31, 0xC6, 0xF8, 0xB7, 0x31, 0xC6,
    0xFC, 0xBF, 0x31, 0xC6, 0x3C, 0x98, 0xFF, 0xFF, 0x00, 0x98, 0xFF, 0xFF, 0xE0, 0x9F, 0x31, 0xC6,
    0xFE, 0x9F, 0x31, 0xC6, 0x1E, 0x8C, 0x31, 0xC6, 0x00, 0x8E, 0x31, 0xC6, 0x00, 0x87, 0x01, 0xFC,
    0x00, 0x82, 0x01, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0xFE, 0x9F, 0xFF, 0x7F,
    0xFC, 0x80, 0xFF, 0x7F, 0xC0, 0x80, 0x01, 0x60, 0xC0, 0x80, 0x01, 0x60, 0xC0, 0x80, 0x01, 0x60,
    0xC0, 0x80, 0xFF, 0x7F, 0xFF, 0x9F, 0xFF, 0x7F, 0xFF, 0x9F, 0x01, 0x60, 0xE0, 0x00, 0x00, 0x00,
    0xE0, 0xE2, 0xFF, 0xFF, 0xF0, 0xE7, 0xFF, 0xFF, 0xF0, 0x0E, 0xC0, 0x00, 0xD8, 0x1C, 0xC0, 0x00,
    0xDC, 0x08, 0xC0, 0x00, 0xCE, 0xC0, 0xFF, 0xFF, 0xC6, 0xC0, 0xFF, 0xFF, 0xC3, 0x00, 0xC0, 0x00,
    0xC2, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0xF0, 0xFF, 0xFF, 0xC0, 0xF0, 0xFF, 0xFF,
    0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
  {}, {}, {}, {},
};





#define T 3
const static unsigned char animation[T][680] = {
  {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3c, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x07, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x3f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfe,
    0xfc, 0x8f, 0xff, 0xff, 0xff, 0xff, 0x03, 0xe0, 0xf9, 0x6f, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x87, 0xf3, 0x0f, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0x0f,
    0xe7, 0x9f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x0f, 0xee, 0xff, 0xff, 0xff,
    0xff, 0x9f, 0xff, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x7f,
    0xf8, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x7f, 0xf8, 0xdf, 0xff, 0xff,
    0xff, 0xe7, 0xff, 0xff, 0xf3, 0x9f, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff,
    0xf3, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff,
    0xff, 0xc7, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0xe7, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff,
    0xff, 0xf7, 0xff, 0xff, 0xf7, 0x7f, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff,
    0xf7, 0x7f, 0xff, 0xfd, 0xff, 0xc7, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xf9,
    0xff, 0x07, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfe, 0xff,
    0xe1, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfe, 0xff, 0xc1, 0xff, 0xff, 0xff,
    0xff, 0x1f, 0xfc, 0xff, 0x98, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x7f,
    0x3e, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf8, 0x1f, 0x7f, 0xfe, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x87, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x03, 0x80,
    0xff, 0xf9, 0xff, 0xef, 0xff, 0xff, 0x1f, 0xb8, 0xff, 0xf3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x09, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xff, 0xff, 0x59,
    0xfe, 0xe7, 0xcf, 0xff, 0xff, 0xff, 0xff, 0x9b, 0xfc, 0xf3, 0x9f, 0xff,
    0xef, 0xff, 0xff, 0x3b, 0xf9, 0xf9, 0xbf, 0xff, 0xcf, 0xff, 0xff, 0x73,
    0x72, 0xf8, 0x7f, 0xff, 0xdf, 0xff, 0xfc, 0xf7, 0x24, 0xf2, 0x7f, 0xfe,
    0xff, 0xff, 0xf9, 0xe7, 0x8c, 0xf6, 0xff, 0xfc, 0xff, 0xff, 0xfb, 0x0f,
    0xf9, 0xe4, 0xff, 0xfd, 0xff, 0xff, 0xf3, 0xdf, 0xf3, 0xe4, 0xff, 0xff,
    0xff, 0x87, 0xe7, 0x9f, 0xf3, 0xe5, 0xff, 0xff, 0xff, 0xb7, 0xcf, 0x3f,
    0xf8, 0x85, 0xff, 0xff, 0xff, 0xa7, 0xcf, 0xff, 0xe0, 0x91, 0xff, 0xff,
    0xff, 0x8f, 0x9f, 0xff, 0x8f, 0x80, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff,
    0x1f, 0xc6, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x3f, 0xf3, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xfe, 0x3f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x7f, 0xbc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0xf9, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xf2, 0xf3,
    0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xf3, 0xf7, 0xff, 0xff, 0xfe, 0xff,
    0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
  },
  {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfe,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xe0, 0xff, 0xfd, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x87, 0xff, 0xf8, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0x1f,
    0xff, 0xfd, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0x9f, 0xff, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x7f,
    0xf8, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x7f, 0xf8, 0xff, 0xff, 0xff,
    0xff, 0x87, 0xff, 0xff, 0xf0, 0xf7, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff,
    0xf1, 0xf7, 0xdf, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf7, 0xff, 0x9f, 0xff,
    0xff, 0xc7, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff,
    0xe7, 0xff, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff,
    0xff, 0x07, 0xfc, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf8, 0xff,
    0xf7, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf0, 0xff, 0xf3, 0xdf, 0xff, 0xff,
    0xff, 0x07, 0xe0, 0xff, 0xc3, 0x9f, 0xff, 0xff, 0xff, 0x0f, 0xe0, 0xff,
    0x81, 0x3f, 0x7f, 0xfe, 0xff, 0x0f, 0xc0, 0xff, 0x31, 0x7f, 0xff, 0xf8,
    0xff, 0x1f, 0xc0, 0xff, 0x7c, 0x7e, 0x7e, 0xfc, 0xff, 0x3f, 0xc0, 0x7f,
    0xfc, 0xfe, 0x7c, 0xfb, 0xff, 0x7b, 0x80, 0x1f, 0xfc, 0xfd, 0xfd, 0xff,
    0xff, 0xf3, 0x80, 0x07, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xe7, 0x03, 0xe0,
    0xf2, 0xf3, 0xf3, 0xff, 0xff, 0xcf, 0x1f, 0xd8, 0xe5, 0xe7, 0xe7, 0xff,
    0xff, 0xcf, 0xff, 0x93, 0xc9, 0xef, 0xef, 0xff, 0xff, 0x9f, 0xff, 0xb3,
    0xd3, 0xe7, 0xcf, 0xff, 0xff, 0x3f, 0xff, 0x37, 0x87, 0xf3, 0xdf, 0xff,
    0x7f, 0x7c, 0xff, 0x77, 0x2e, 0xf8, 0xff, 0xff, 0x7f, 0x79, 0xfe, 0xe7,
    0x46, 0xf8, 0xff, 0xff, 0x7f, 0xfb, 0xfc, 0x8f, 0x90, 0xf2, 0xff, 0xff,
    0x7f, 0xf8, 0xf9, 0x0f, 0xb8, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x9f,
    0x9a, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x3f, 0xc2, 0xe1, 0xff, 0xff,
    0xff, 0xff, 0xe7, 0x7f, 0xf8, 0x81, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff,
    0xf1, 0x81, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xe7, 0xa1, 0xff, 0xff,
    0xff, 0xcf, 0x9f, 0xff, 0x8f, 0x8c, 0xff, 0xff, 0xff, 0xa7, 0xff, 0xff,
    0x3f, 0xce, 0xff, 0xff, 0xff, 0xb7, 0xff, 0xff, 0x3f, 0xe3, 0xff, 0xfb,
    0xff, 0x8f, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff,
    0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff
  },
  { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfe,
    0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x03, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0x1f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x7f, 0xee, 0xff, 0xff, 0xff,
    0xff, 0x9f, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff,
    0x99, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x39, 0xff, 0xfe, 0xff,
    0xff, 0x87, 0xff, 0xff, 0x73, 0xff, 0xf0, 0xff, 0xff, 0xc7, 0xff, 0xff,
    0x71, 0xfe, 0xf9, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf1, 0xfc, 0xf8, 0xff,
    0x3f, 0x03, 0xf8, 0xff, 0xf1, 0xfd, 0xf3, 0xff, 0x3f, 0x03, 0xe0, 0xff,
    0xe1, 0xfb, 0xff, 0xff, 0x3f, 0x03, 0x80, 0xff, 0xe1, 0xf3, 0xff, 0xff,
    0x3f, 0x03, 0x80, 0xff, 0xf3, 0xe7, 0xff, 0xff, 0x7f, 0x07, 0x00, 0xff,
    0xf7, 0xef, 0xff, 0xfd, 0x7f, 0x07, 0x00, 0xfe, 0xd3, 0xcf, 0xff, 0xf9,
    0x7f, 0x06, 0x00, 0xfe, 0x83, 0x9f, 0xff, 0xff, 0x7f, 0x0e, 0x00, 0xfe,
    0x31, 0xbf, 0xff, 0xff, 0xf8, 0x0c, 0x00, 0xfc, 0x71, 0xfe, 0xff, 0xff,
    0xfb, 0x1c, 0x00, 0xfc, 0xf4, 0xfe, 0xff, 0xff, 0xfb, 0x39, 0x00, 0x7c,
    0xe2, 0xfd, 0x7f, 0xfe, 0xfd, 0x7b, 0x00, 0x1e, 0xc7, 0xf9, 0x7f, 0xfe,
    0xff, 0xf3, 0x00, 0x86, 0x8f, 0xf3, 0xff, 0xff, 0xff, 0xe7, 0x03, 0xe0,
    0x1d, 0xe7, 0xff, 0xff, 0xff, 0xcf, 0x0f, 0xf8, 0x19, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf3, 0x3b, 0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0x73, 0xe4, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf7, 0x27, 0xf0, 0xff, 0xff,
    0x6f, 0xff, 0xff, 0xf7, 0x8f, 0xf8, 0xff, 0xe3, 0x2f, 0xff, 0xff, 0x67,
    0xc8, 0xf1, 0xff, 0xe9, 0x9f, 0xff, 0xff, 0x6f, 0x93, 0xf4, 0xff, 0xe3,
    0xff, 0xff, 0xff, 0x4f, 0x33, 0xf6, 0xff, 0xf7, 0xff, 0xff, 0xff, 0x1f,
    0xf8, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xf7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xf8, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf1, 0xe3, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc1, 0x7f, 0xfe,
    0xff, 0xfb, 0xff, 0xff, 0x8f, 0xdc, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff,
    0x3f, 0xce, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xe3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x7f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9,
    0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x9f, 0xff,
    0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xe7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff
  }
};
