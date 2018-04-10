#include "application.h"

#include "../../lib/Adafruit_GFX.h"
#include "../../lib/Adafruit_SSD1306.h"

/**
* Declaring the variables.
*/
unsigned int nextTime = 0;    // Next time to contact the server


// Dispaly
#define OLED_RESET D4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void OnDisplayUpdate(const char *event, const char *data)
    {
    //if (nextTime > millis())
    //    {
    //    return;
    //    }
    if (data)
        {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println(data);
        display.display();
        }
    //nextTime = millis() + 1000;
    }

void setup() {
  //Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  Particle.subscribe("displayupdate", OnDisplayUpdate);
}

void loop() {

}
