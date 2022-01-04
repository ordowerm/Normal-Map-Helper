#define MENU_CALLBACKS

#ifndef MENUS
#include "./menu.h"
#endif

#ifndef MENU_STRINGS
#include "../../data/menustrings.c"
#endif

#ifndef COLORS
#include "./headers/colorMgmt.h"
#endif

#include <stdio.h>

void EndMenu(int isRoot);
void TestCallback();
void GetColorCallback();
void GetCardinalCallback(Menu* m,Color* color1,Color* color2,Color* outColor);
