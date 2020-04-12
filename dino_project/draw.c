

#include"draw.h"



void drawpixel(int x, int y)
{
   oled_set_pix(x, y, clBlack);
   oled_set_pix(x+1, y+1, clBlack);
   oled_set_pix(x, y+1, clBlack);
   oled_set_pix(x+1, y, clBlack);

}

void delpixel(int x, int y)
{
 oled_set_pix(x, y, clWhite);
 oled_set_pix(x+1, y+1, clWhite);
 oled_set_pix(x, y+1, clWhite);
 oled_set_pix(x+1, y, clWhite);
}
