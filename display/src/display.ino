// This #include statement was automatically added by the Spark IDE.
#include "../../lib/Adafruit_GFX.h"

// This #include statement was automatically added by the Spark IDE.
#include "../../lib/Adafruit_SSD1306.h"

#include "morse.h"

#define PWM_PIN D0
#define CONNECT_PIN D7

#define DOT_LENGTH 200
#define DASH_LENGTH 3 * DOT_LENGTH

#define ELEMENT_GAP DOT_LENGTH
#define CHAR_GAP 3 * DOT_LENGTH
#define WORD_GAP 7 * DOT_LENGTH


#define OLED_RESET D4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void OnMessageHandler (const char *event, const char *data){
    if (data){
      display.clearDisplay();
      // text display tests
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println(data);
      display.display();
    }
}

void setup()   {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // Clear the buffer.
  display.clearDisplay();

  Particle.subscribe("message", OnMessageHandler);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("MorseThing");
  display.display();
}


void loop() {

}
