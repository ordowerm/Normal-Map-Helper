/*
Header file describing menu structures.

Idea:
  - Menus are implemented as a stack of linked list nodes.
  - They contain a reference to a callback function. This function loops when the menu is active.
  - The "base" function used in the callback displays the title of the menu, a description of the menu, and a numbered list corresponding to menu commands
  - The menu prompts user input, which should be a number between 1 and n, where n-2 is the number of submenus/commands; n-1 returns to the previous menu; and n exits the program
  - This still needs implementation, but I need a nap.
*/

#ifndef DATA_STRUCTURES
#include "dataStrux.h"
#endif

#define MENUS

#include <string.h>

typedef struct MENU
{
  int active; //boolean flag for use in the menu callback function's while-loop
  struct MENU** linkedMenus; //list of linked menus
  int num_linked; //number of linked menus --> use this to define which numeric inputs are valid when asking user for input
  char* title; //title of this menu to be displayed in previous menu
  char* description; //directions to display when this menu is active
  void* callback; //function pointer for payload of this function
} Menu;

void RunMenu(Menu* m); //forward declaration for standard menu function
void SetMenuCallback(Menu* menu, void* funcPointer){ if(menu) menu->callback = funcPointer;} //for specifc menu callbacks, pass a function pointer to the struct
void AddLinkedMenu(Menu* src, Menu* linked); //dynamically add a menu
void SetLinkedMenus(Menu* src, Menu** linked);  //sets the entire field for the linked menus
void SetMenuTitle(Menu* m, const char* s);
void SetMenuDescription(Menu* m, const char* s);
