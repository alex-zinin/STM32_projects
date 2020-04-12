


#include "dino.h"
#include"dinopoints.h"










void drawdino1(dino dn)
{
  int ps = dn.posx;
  int gr = dn.posy;

  //first foot:


	
//second foot:
  
 

 

	for(int i = 0; i < 167; i++)
	{
		drawpixel(ps+p[i].a,gr+p[i].b);
	}
  



 
 

int j = 0;
int i = 0;
  for(i = 0; i < 7; i++)
    {
      for(j = 0; j < 10; j++)
        drawpixel(ps+14+j, gr-35-i);
    }
    for(j = 0; j < 8; j++)
      drawpixel(ps+14+j, gr-42);

for(int i = 0; i < 46; i++)
	{
		delpixel(ps+p2[i].a,gr+p2[i].b);
	}


}




void dinoanimation2(dino dn)
{
  int ps = dn.posx;
  int gr = dn.posy;

  delpixel(ps+8, gr-9);
  delpixel(ps+8, gr-7);
  delpixel(ps+8, gr-5);
  delpixel(ps+10, gr-5);

}






void dinojump(int stat, dino *dn)
{
  if(stat > 0)
    dn->posy = dn->posy +1;
    else
    dn->posy = dn->posy - 1;

}

void dinodel(dino dn)
{
  int ps = dn.posx;
  int gr = dn.posy;
 
  
for(int i = 0; i < 169; i++)
	{
		delpixel(ps+p3[i].a,gr+p3[i].b);
	}
  int j = 0;
  int i = 0;
  for(i = 0; i < 7; i++)
    {
      for(j = 0; j < 10; j++)
        delpixel(ps+14+j, gr-35-i);
    }
    for(j = 0; j < 8; j++)
      delpixel(ps+14+j, gr-42);

}

void dinoanimation1(dino dn)
{

  int ps = dn.posx;
  int gr = dn.posy;

  delpixel(ps, gr-5);
  delpixel(ps+2, gr-5);
  delpixel(ps, gr-7);

  delpixel(ps, gr-9);
  delpixel(ps+2, gr-9);
  delpixel(ps, gr-11);
  delpixel(ps+2, gr-11);
  delpixel(ps+4, gr-11);
}
