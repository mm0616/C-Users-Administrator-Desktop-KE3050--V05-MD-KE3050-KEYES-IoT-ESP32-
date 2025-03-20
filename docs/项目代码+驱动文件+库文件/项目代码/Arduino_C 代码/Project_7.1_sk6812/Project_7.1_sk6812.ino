/*
  Keyes
  sk6812
  www.keyes-robot.com
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // 所需的16兆赫Adafruit Trinket
#endif
// Arduino上的哪个引脚连接到NeoPixels上?
// 对于Trinket or Gemma，我们建议改为1:
#define LED_PIN    26
// Arduino上有多少个新像素?
#define LED_COUNT 4
// 声明我们的NeoPixel条带对象:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // 这些线路是专门支持Adafruit Trinket 的5V 16MHz.
  // 任何其他板，你可以删除这部分(但没有伤害留下它):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // 结束 Trinket-specific 代码.

  strip.begin();           // 初始化NeoPixel条带对象(REQUIRED)
  strip.show();            // 尽快关闭所有像素
  strip.setBrightness(50); // 将亮度设置为1/5(最大值为255)
}


// loop() 功能——只要开发板开着，就会重复运行 ---------------

void loop() {
  // 沿着RGB条带的长度设置各种颜色...
  colorWipe(strip.Color(255,   0,   0), 50); // Red
  colorWipe(strip.Color(  0, 255,   0), 50); // Green
  colorWipe(strip.Color(  0,   0, 255), 50); // Blue

  // 在不同的颜色做一个跑马灯的效果...
  theaterChase(strip.Color(127, 127, 127), 50); // 白色,一半亮度
  theaterChase(strip.Color(127,   0,   0), 50); // 红色,一半亮度
  theaterChase(strip.Color(  0,   0, 127), 50); // 蓝色,一半亮度

  rainbow(10);             // 沿着整个RGB条带流动的彩虹循环
  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
}


// 我们自己创建动画效果的一些功能 -----------------

// 用颜色一个接一个地填充条纹像素。RGB条带未先清除;
//  任何东西都会被一个像素一个像素地覆盖. 传入颜色(作为一个“打包”的32位值，你可以通过调用strip来获得。
// 如上面loop()函数中所示的颜色(红、绿、蓝),以及像素之间的延迟时间(以毫秒为单位).
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // 对于条带中的每个像素...
    strip.setPixelColor(i, color);         //  设置像素的颜色(在RAM中)
    strip.show();                          //  更新条带以匹配
    delay(wait);                           //  暂停一会
  }
}

// 跑马灯追逐的效果。传入一个颜色(32位值，如上所述，strip.Color(r,g,b))和帧之间的延迟时间(以毫秒为单位).
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // 重复十次...
    for(int b=0; b<3; b++) { //  'b'从0数到2...
      strip.clear();         //   将RAM中的所有像素设置为0(关闭)
      // 'c'从'b'开始计数，每步3次...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // 设置像素c的值为color
      }
      strip.show(); // 更新RGB条带的内容
      delay(wait);  // 暂停一会
    }
  }
}

// 彩虹沿着整条带子循环。在帧之间传递延迟时间(毫秒).
void rainbow(int wait) {
  // 第一个像素的色调在色轮中运行5个完整的循环.
  // 色轮的范围是65536，但如果我们滚动它是可以的, 从0数到5*65536. 
  // 每次在firstPixelHue中添加256意味着我们将让5*65536/256 = 1280通过这个外部循环:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // 偏移像素色相的量，使色轮沿色带长度旋转一圈(范围65536)
      // (strip.numPixels() 步骤):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // colorhsv()可以接受1或3个参数:一个色调(0到65535)或可选地添加饱和度和值(亮度)(每个0到255).
      // 这里我们只使用单参数的色调变体. 结果通过strip.gamma32()传递，以便在分配给每个像素之前提供“更真实的”颜色:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // 更新带新的内容
    delay(wait);  // 暂停一会
  }
}

// 彩虹跑马灯的效果。在帧之间传递延迟时间(毫秒).
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // 第一个像素从红色开始(色调0)
  for(int a=0; a<30; a++) {  // 重复30次...
    for(int b=0; b<3; b++) { //  'b'从0数到2...
      strip.clear();         //   将RAM中的所有像素设置为0(关闭)
      // 'c'从'b'开始计数，以3为单位递增...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // 像素“c”的色相偏移量使色轮沿条带的长度(strip. numpixels()步骤)旋转一圈(范围65536):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // 颜色 -> RGB
        strip.setPixelColor(c, color); // 设置像素c的值为color
      }
      strip.show();                // 更新色带的内容
      delay(wait);                 // 暂停一会
      firstPixelHue += 65536 / 90; // 一个周期的彩色轮超过90帧
    }
  }
}
