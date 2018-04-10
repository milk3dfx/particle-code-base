#include "morse.h"

char* alphobet [] = {
    ".-",       // A
    "-...",     // B
    "-.-.",     // C
    "-..",      // D
    ".",        // E
    "..-.",     // F
    "--.",      // G
    "....",     // H
    "..",       // I
    ".---",     // J
    "_._",      // K
    ".-..",     // L
    "--",       // M
    "-.",       // N
    "---",      // O
    ".--.",     // P
    "--.-",     // Q
    ".-.",      // R
    "...",      // S
    "-",        // T
    "..-",      // U
    "...-",     // V
    ".--",      // W
    "-..-",     // X
    "-.--",     // Y
    "--.."      // Z
};

char* numbers [] = {
    "-----",    // 0
    ".----",    // 1
    "..---",    // 2
    "...--",    // 3
    "....-",    // 4
    ".....",    // 5
    "-....",    // 6
    "--...",    // 7
    "---..",    // 8
    "----."     // 9
};

char* TranslateChar(char ch)
    {
    // For numbers
    if (ch >= 48 && ch <= 57)
        {
        return numbers[ch - 48];
        }
    // For capetal letters
    if (ch >= 65 && ch <= 90)
        {
        ch = ch + 32;
        }
    // For small case letters
    if (ch >= 97 && ch <= 122)
        {
        return alphobet[ch - 97];
        }
    return "";
    }
