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


void TestFunc2()
{
  Menu* m = MenuInit();
  SetMenuTitle(m,"Test Menu");
  SetMenuDescription(m,"This is a description for a test menu. I hope you like it.\nYou can tell me that you like it at my email address.\n");

  Menu* m1 = MenuInit();
  SetMenuTitle(m1,"Child Menu 1");
  SetMenuDescription(m1,"This is a description for a non-root child.");
  AddLinkedMenu(m,m1);

  Menu* m2 = MenuInit();
  SetMenuTitle(m2,"Child Menu 2");
  SetMenuDescription(m2,"This is a description for a non-root child.");
  SetMenuCallback(m2,&TestCallback);
  AddLinkedMenu(m,m2);
  

  RunMenu(m,1);
  DeleteMenu(m);
}

int main (int argc, char** argv)
{
  TestFunc2();
  return 0;
}
