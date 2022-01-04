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
#include <stdio.h>

#define TITLE_BUFFER_SIZE 32
#define DESCRIPTION_BUFFER_SIZE 280
#define MAX_OPTIONS 8
#define USER_BUFFER_SIZE 8

#ifndef COLORS
#include "./headers/colorMgmt.h"
#endif

#include <unistd.h> //included for sleep call --this might not be portable. check later

typedef struct MENU
{
  struct MENU** linkedMenus; //list of linked menus
  int num_linked; //number of linked menus --> use this to define which numeric inputs are valid when asking user for input
  char* title; //title of this menu to be displayed in previous menu
  char* description; //directions to display when this menu is active
  void (* callback)(struct MENU*,Color*,Color*,Color*); //function pointer for payload of this function
} Menu;

Menu* MenuInit();
int GetOptionNumber(Menu* menu); //helper function for obtaining user input
void RunMenu(Menu* m, int isRoot, Color* color1, Color* color2, Color* outColor); //forward declaration for standard menu function; the isRoot field is a flag denoting that the current menu is the root/main menu
void SetMenuCallback(Menu* menu, void (* funcPointer)(Menu*,Color*,Color*,Color*)){ if(menu) menu->callback = funcPointer;} //for specifc menu callbacks, pass a function pointer to the struct
void AddLinkedMenu(Menu* src, Menu* linked); //dynamically add a menu
void SetMenuTitle(Menu* m, const char* s);
void SetMenuDescription(Menu* m, const char* s);
void DeleteMenu(Menu* m);

//Exception handlers -- wrappers that print text in menustrings.c
void PrintBufferError();

//Miscellaneous Functions
void GetColorInput(Color* c);
