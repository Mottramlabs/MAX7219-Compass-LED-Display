# MAX7219-Compass-LED-Display
This compass style display has a two line 6 digit (3 plus 3) display using a MAX7219 display driver. The module is made up of two 6 digit LED displays plus 16 off 5mm LED’s in a compass layout with 22.5° increments.

      Pin connections
      Name      Arduino     ESP8266         MAX7219 7 Segment display
      -----     -------     -------         -------------------------
                +5V         5V              VCC
                GND         GND             GND
      DIN       D11/MOSI    GPIO13 (D7)     DIN
      CS        D7/SS       GPIO2 (D4)      CS
      CLK       D13/SCK     GPIO14 (D5)     CLK
      
There are two demo sketches one for Arduino one for Wemos D1 Mini. Included in the demo folders are the MAX7219 library .h and .cpp files, but these could be removed if using the MAX7219 as an installed library. If the library is installed in the IDE replace the line below.

      #include "MAX7219_Compass.h"
                  with
      #include <MAX7219_Compass.h>

