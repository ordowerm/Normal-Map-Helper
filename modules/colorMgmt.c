#ifndef COLORS
#include "./headers/colorMgmt.h"
#endif

#include <stdio.h>


extern int debug;


/*
Corrects component values so that RGB are between [0,1]
*/
void CorrectComponent(float* c)
{
  if (*c < 0){*c = 0;}
  if (*c >1){*c =1;}
}
void CorrectColor(Color* c)
{
  CorrectComponent(&(c->r));
  CorrectComponent(&(c->g));
  CorrectComponent(&(c->b));
}

/*
Returns RGB color w/ components between [0,1]
*/
Color MakeColor(float r, float g, float b)
{
  Color output;
  output.r = r;
  output.g = g;
  output.b = b;
  CorrectColor(&output);
  return output;
}

/*
Converts RGB floats to hex
*/
void PrintHex(Color* c){
  //Convert to [0,255] space
  unsigned r = 255*(c->r);
  unsigned g = 255*(c->g);
  unsigned b = 255*(c->b);

  //Bitwise-And to convert everything to a byte-size hexcode
  r= 0xFF&r;
  g= 0xFF&g;
  b= 0xFF&b;

  printf("Color: #%.2X%.2X%.2X\n",r,g,b);
}

/*
Prints RGB components to console as an ordered triplet
*/
void PrintFloat(Color* c)
{
    if (c)
    {
      printf("Color: (%.4f,%.4f,%.4f)\n",c->r,c->g,c->b);
    }
}

//interpolates the color
float LerpComponent(float a, float b, float t)
{
  if (t > 1) {t = 1;}
  if (t < 0) {t = 0;}
  return a+(b-a)*t;
}
Color Lerp(Color* c0, Color* c1, float t)
{
    float r = LerpComponent(c0->r,c1->r,t);
    float g = LerpComponent(c0->g,c1->g,t);
    float b = LerpComponent(c0->b,c1->b,t);
    return MakeColor(r,g,b);
}

//Passes hex values into color
void HexToFloat(Color* c, int r, int g, int b)
{
  if (!c) return;

  c->r = ((float)r)/255.0f;
  c->g = ((float)g)/255.0f;
  c->b = ((float)b)/255.0f;


}
