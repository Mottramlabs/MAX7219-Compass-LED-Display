# MAX7219-Compass-LED-Display
This compass style display has a two line 6 digit (3 plus 3) display using a MAX7219 display driver. The module is made up of two 6 digit LED displays plus 16 off 5mm LED’s in a compass layout with 22.5° increments.

      Pin connections
      Name      Arduino     ESP8266         MAX7219 7 Segment display
      -----     -------     -------         -------------------------
                +5V         5V              VCC
                GND         GND             GND
      DIN       D11/MOSI    GPIO13 (D7)     DIN
      CS        *D7/SS      *GPIO15 (D8)    CS
      CLK       D13/SCK     GPIO14 (D5)     CLK
      
