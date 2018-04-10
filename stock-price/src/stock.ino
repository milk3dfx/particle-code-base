#include "application.h"
#include "HttpClient.h"

#include "../../lib/Adafruit_GFX.h"
#include "../../lib/Adafruit_SSD1306.h"

/**
* Declaring the variables.
*/
unsigned int nextTime = 0;    // Next time to contact the server
HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
    //  { "Content-Type", "application/json" },
    //  { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;


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

String GetPrice (String& msg) {
  int index = msg.indexOf("\"l\"");
  index = msg.indexOf(":", index);
  int start = msg.indexOf("\"", index);
  int end = msg.indexOf("\"", start+1);
  return msg.substring(start+1, end);
}

void setup() {
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
}

void loop() {
    if (nextTime > millis()) {
        return;
    }

    Serial.println();
    Serial.println("Application>\tStart of Loop.");
    // Request path and body can be set at runtime or at setup.
    request.hostname = "finance.google.com";
    request.port = 80;
    request.path = "/finance/info?q=ptc";

    // The library also supports sending a body with your request:
    //request.body = "{\"key\":\"value\"}";

    // Get request
    http.get(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);
    /*
    int index = response.body.indexOf("\"l\"");
    index = response.body.indexOf(":", index);
    int start = response.body.indexOf("\"", index);
    int end = response.body.indexOf("\"", start+1);
    String strPrice = response.body.substring(start+1, end);
    */
    String strPrace = GetPrice(response.body);

    Serial.print("> Price: ");
    Serial.println(strPrice);

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("PTC: " + strPrice);
    display.display();

    nextTime = millis() + 10000;
}
