/**********************************************************
 * 
 * File name: segmentdisplay.ino
 * Author: milk3dfx 
 *
 *********************************************************/
#include "segment_display.h"

SegmentDisplay disp;

void loading ()
    {
    int dt = 200;
    byte n = 1;
    for(int i = 0; i < 6; i++)
        {
        disp.Set (n);
        delay (dt);
        n = n*2;
        }
    }
    
void setup ()
    {
    disp.Init();
    delay(2000);
    }

void loop()
    {
    loading ();
    loading ();
    
    for(int i = 0; i <= 9; i++)
        {
        disp.SetDigit (i);
        delay (1000);
        }
    }
