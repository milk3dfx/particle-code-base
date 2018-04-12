#include <MQTT.h>
#include "morse.h"
#define PWM_PIN D0
#define CONNECT_PIN D7

#define DOT_LENGTH 200
#define DASH_LENGTH 3 * DOT_LENGTH

#define CHAR_GAP DOT_LENGTH 
#define WORD_GAP 7 * DOT_LENGTH


unsigned int frequency = 500;

void PlayMorseCh (char* morseChar)
    {
    int morseLen = strlen(morseChar);
    for (int i = 0; i < morseLen; i++)
        {
        digitalWrite(D7, HIGH);
        analogWrite(PWM_PIN, 128, 2000);
        if(morseChar[i]=='.')
            {
            delay (DOT_LENGTH);
            }
        else
            {
            delay (DASH_LENGTH);
            }
        analogWrite(PWM_PIN, 0, 2000);
        digitalWrite(D7, LOW);
        if (i != morseLen - 1)
            {
            delay(CHAR_GAP);
            }
        }
    }
    
bool PlayString (char* str)
    {
    int strLen = strlen (str); 
    for (int index = 0; index < strLen; index++)
        {
        char* morseChar = TranslateChar(str[index]);
        if (strlen (morseChar) != 0)
            {
            PlayMorseCh (morseChar);
            if (index != strLen - 1)
                {
                if (str[index + 1] == ' ')
                    {
                    index = index + 1;
                    delay(WORD_GAP);
                    }
                    else
                    {
                    delay (CHAR_GAP);
                    }
                }
            }
        }
    return true;
    }

void callback(char* topic, byte* payload, unsigned int length);

MQTT client("mqtt.vsreality.com", 8883, callback);

// recieve message
void callback(char* topic, byte* payload, unsigned int length) {
    char p[length + 1];
    memcpy(p, payload, length);
    p[length] = NULL;
    PlayString (p);
    
    //String message(p);
    //client.publish("particle/out", message);
    
    // delay(1000);
}

void setup() {
    // Setup pins mode
    pinMode(CONNECT_PIN, OUTPUT);
    pinMode(PWM_PIN, OUTPUT);
    digitalWrite(CONNECT_PIN, LOW);
    
    

    // connect to the server
    client.connect("ParticleClient", "milk3dfx", "Ss198811");

    // publish/subscribe
    if (client.isConnected()) {
        //digitalWrite(CONNECT_PIN, HIGH);
        client.publish("particle/out","hello world");
        client.subscribe("particle/in");
    }
}

void loop() {
    if (client.isConnected())
        client.loop();
}