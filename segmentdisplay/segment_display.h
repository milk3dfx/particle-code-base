/**********************************************************
 * 
 * File name: segment_display.h
 * Author: milk3dfx 
 *
 *********************************************************/
#define NPINS 6

// Mapping
/*
    Pin |   Segment
-------------------
    0   |    A
    1   |    B
    2   |    C
    3   |    D
    4   |    E
    5   |    F
    6   |    G
    7   |    F
------------------
*/
#define A 0x01
#define B 0x02
#define C 0x04
#define D 0x08
#define E 0x10
#define F 0x20
#define G 0x40

class SegmentDisplay
    {
    public:
        void Init ();
        void Clear ();
        
        void Set (byte b);
        void SetDigit (byte digit);
        
    private:
        byte pins[10] = {
            A | B | C | D | E | F,      // 0
            B | C,                      // 1
            A | B | D | E | G,          // 2
            A | B | C | D | G,          // 3
            B | C | G | F,              // 4
            A | C | D | F |G,           // 5
            A | C | D | E | F | G,      // 6
            A | B | C,                  // 7
            A | B | C | D | E | F | G,  // 8
            A | B | C | D | F |G        // 9
        };
    };