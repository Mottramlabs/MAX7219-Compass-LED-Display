/***************************************************************************************************************************

      Arduino Demo Compass Display Version 1
      6th September 2018

      Pin connections
      Name      Arduino     ESP8266         MAX7219 7 Segment display
      -----     -------     -------         -------------------------
                +5V         5V              VCC
                GND         GND             GND
      DIN       D11/MOSI    GPIO13 (D7)     DIN
      CS        *D7/SS      *GPIO2 (D4)     CS
      CLK       D13/SCK     GPIO14 (D5)     CLK

***************************************************************************************************************************/

// SPI library needed for the MAX7219 library
#include <SPI.h>
// Display items
#include "MAX7219_Compass.h"
#define MAX7219_CS 2                  // CS pin used on Wemos
MAX7219_Digit My_Display(MAX7219_CS); // Make an instance of MAX7219_Digit called My_Display and set CS pin


void setup(void) {

  // startup display and LED test
  My_Display.Begin();         // Set's all the registers and clears the display
  My_Display.Brightness(4);   // Set brightness 0-15

  // light all segments
  My_Display.Display_Digits(1, 0x08, 0x08, 0x08, 0b111);
  My_Display.Display_Digits(2, 0x08, 0x08, 0x08, 0b111);
  My_Display.MAX7219_Write(1, 0xFF);
  My_Display.MAX7219_Write(2, 0xFF);
  delay(2000);

  // write data values to display (display_line, digit_1,, digit_2, digit_3, decimal points)
  My_Display.Brightness(15);   // Set brightness 0-15
  My_Display.Display_Digits(1, 0x00, 0x00, 0x00, 0b0);
  My_Display.Display_Digits(2, 0x00, 0x00, 0x00, 0b0);
  My_Display.MAX7219_Write(1, 0x00);
  My_Display.MAX7219_Write(2, 0x00);
  delay(2000);

} // End of setup


void loop() {

  // demo temperature display
  // write to line 2, the value, select number of decimal places, suffix 'C
  float a = 23.8;
  My_Display.Display_Value(2, a, 0, 0x11);

  // animate the compass bearing and display the number used
  // 0 = North and 15 = North North West. 8 = Sound and so on
  for (int Wind_Dir = 0; Wind_Dir < 16; Wind_Dir++) {

    // display the number of the bearing used, display with 1 decimal place because we can
    My_Display.Display_Value(1, Wind_Dir, 1, 0x0);
    // display the compass bearing on the compass LED's
    My_Display.Display_Compass(Wind_Dir);

    delay(100);
  } // end of demo loop

} // End of Loop




