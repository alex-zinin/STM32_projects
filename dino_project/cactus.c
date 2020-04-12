#include"cactus.h"
//#include"dinopints.h"

 typedef	struct 
{
	signed char a;
	signed char b;
}pairc;

void drawcactus(cactus ct)
{
  int i = 0;
  int j = 0;
  int ps = ct.posx;
  int gr = ct.posy;
      for(i = 0; i < 4; i++)
    {
      for(j = 0; j < 7; j++)
      {
          drawpixel(ps+2*i, gr-2*j);
      }
    }

pairc pc[200] = {{+6, -14},
{+8, -8},
{+10, -8},
{+10, -10},
{+4, -14},
{+2, -14},
{-2, -8},
{-4, -8},
{-4, -10},
{-4, -12},
{+10, -12},
{+4, -16},
{+2, -16},
{+4, -16},
{-4, -12},
{+10, -12}};
for(int i = 0; i < 17; i++)
	{
		drawpixel(ps+pc[i].a,gr+pc[i].b);
	}
     
}



void cactusmove(cactus *ct)
{
  ct->posx =ct->posx-ct->speed;
  if(ct->posx < -10)
    ct->posx = 135;
}
void cactusdel(cactus ct)
{
  int i = 0;
  int j = 0;
  int ps = ct.posx;
  int gr = ct.posy;
      for(i = 0; i < 4; i++)
    {
      for(j = 0; j < 7; j++)
      {
        if(gr-2*j != 55)
          delpixel(ps+2*i, gr-2*j);

      }
    }
     pairc p[200] = {{+6, -14},
{+4, -16},
{+4, -12},
{+8, -8},
{+10, -8},
{+10, -10},
{-4, -12},
{+10, -12},
{+4, -14},
{+2, -14},
{+4, -16},
{+2, -16},
{-2, -8},
{-4, -8},
{-4, -10},
{-4, -12},
{+10, -12}};

for(int i = 0; i < 18; i++)
	{
		delpixel(ps+p[i].a,gr+p[i].b);
	}

}
