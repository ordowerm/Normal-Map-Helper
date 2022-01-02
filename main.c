#include <stdio.h>

#ifndef COLORS
#include "./modules/colorMgmt.c"
#endif

#ifndef MENUS
#include "./modules/menu.c"
#endif

int debug = 1; //global debug variable, marked extern in module files

void TestFunc0()
{
  Color c0 = MakeColor(1.0f,0,0.5);
  PrintFloat(&c0);
  PrintHex(&c0);
}

void TestFunc1()
{
    Color c0 = MakeColor(1,0,0);
    Color c1 = MakeColor(0,0,0);
    Color result = Lerp(&c0,&c1,-4);
    PrintHex(&result);
}

int main (int argc, char** argv)
{
  TestFunc1();
  return 0;
}
