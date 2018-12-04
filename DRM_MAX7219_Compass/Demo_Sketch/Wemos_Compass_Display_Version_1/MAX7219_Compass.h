
/***************************************************************************************************************************/
/*
      Pin connections
      Name      Arduino     ESP8266         MAX7219 7 Segment display
      -----     -------     -------         -------------------------
                +5V         5V              VCC
                GND         GND             GND
      DIN       D11/MOSI    GPIO13 (D7)     DIN
      CS        *D7/SS      *GPIO15 (D8)    CS
      CLK       D13/SCK     GPIO14 (D5)     CLK
*/
/***************************************************************************************************************************/

// Check that the library has not yet been called
#ifndef Max7219_Lib
#define Max7219_Lib

// Check of legacy IDE
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// Include needed library and files
#include <SPI.h>

// below is when the library is in the arduino library
//#include <Display_Font.h>

// below is when the library is loval
#include "Display_Font.h"

/***************************************************************************************************************************/
/*
  Class for writing to the MAX7219 display
*/
/***************************************************************************************************************************/
class MAX7219_Digit
{

  public:

    // Add a constructor
    MAX7219_Digit(int Pin);

    void Begin();
    void MAX7219_Write(uint8_t Address, uint8_t Data);
    void Clear();
    void Brightness(int ii);
    void Display_Digits(int Display_Num, int Char_1, int Char_2, int Char_3, int dec_p);
    void Display_Value(int Display_Num, double Display_Value, int Display_DecP, int Suffix);
    void Display_Compass(int Value);

  private:
    int _Pin; // Private version of the CS Pin
    int _Digit_Map[6] = {3, 4, 5, 6, 7, 8};
    int _Wind1[16] {64, 32, 16, 8, 4, 2, 1, 128, 0, 0, 0, 0, 0, 0, 0, 0};
    int _Wind2[16] {0, 0, 0, 0, 0, 0, 0, 0, 64, 32, 16, 8, 4, 2, 1, 128};

    // MAX7219 register list
    #define MAX7219_Noop          0x0
    #define MAX7219_DecodeMode    0x9
    #define MAX7219_Intensity     0xA
    #define MAX7219_ScanLimit     0xB
    #define MAX7219_Shutdown      0xC
    #define MAX7219_Displaytest   0xF

    #define MAX7219_Dp            0x80

};
#endif


