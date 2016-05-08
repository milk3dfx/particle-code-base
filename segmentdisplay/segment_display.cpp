/**********************************************************
 * 
 * File name: segment_display.cpp
 * Author: milk3dfx 
 *
 *********************************************************/
#include "application.h"
#include "segment_display.h"
#define NPINS 7


void SegmentDisplay::Init ()
    {
    for(int i = 0; i < NPINS; i++)
        {
        pinMode(i, OUTPUT);
        }
    }
            
void SegmentDisplay::Clear ()
    {
    for(int i = 0; i < NPINS; i++)
        {
        digitalWrite(i, LOW);
        } 
    }

void SegmentDisplay::Set (byte b)
    {
    for(int i = 0; i < NPINS; i++)
        {
        digitalWrite(i, (b >> i) & 1);
        }
    }
     
void SegmentDisplay::SetDigit (byte digit)
    {
    Set (pins[digit]);
    }
    