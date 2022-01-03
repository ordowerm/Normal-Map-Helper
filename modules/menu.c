#ifndef MENU_STRINGS
#include "../data/menustrings.c"
#endif

#ifndef MENU_CALLBACKS
#include "./menuCallbacks.c"
#endif

#ifndef MENUS
#include "./headers/menu.h"
#endif

/*
Defines the bodies for the functions declared in menu.h

Struct body pasted below for workflow purposes:
typedef struct MENU
{
  struct MENU** linkedMenus; //list of linked menus
  int num_linked; //number of linked menus --> use this to define which numeric inputs are valid when asking user for input
  char* title; //title of this menu to be displayed in previous menu
  char* description; //directions to display when this menu is active
  void* callback; //function pointer for payload of this function
} Menu;


IDs for data values printed below:
 menuBorder
 menuStart

*/

//Returns an initialized Menu
Menu* MenuInit()
{
    Menu* output = (Menu*)malloc(sizeof(Menu));
    output->num_linked=0;
    output->title = (char*)malloc(TITLE_BUFFER_SIZE*sizeof(char)); //initial buffer size of title
    output->description = (char*)malloc(DESCRIPTION_BUFFER_SIZE*sizeof(char)); //initial buffer size of description
    output->linkedMenus = (Menu**)malloc(MAX_OPTIONS*sizeof(Menu*));
    output->callback = NULL; //default to no callback. If this pointer is set to NULL, then just call the normal RunMenu function. Otherwise, call the function in question
    return output;
}

//Helper function for getting user input in RunMenu
int GetOptionNumber(Menu* m)
{
  long int selection = 0;
  char buffer[USER_BUFFER_SIZE];
  printf("\n%s\n",inputPrompt);
  while (1)
  {
    //Get user input
    if(fgets(buffer, USER_BUFFER_SIZE, stdin))
    {
      selection = strtol(buffer,NULL,0);
    }

    if (selection < 1 || selection > m->num_linked+1)
    {
      printf("%s%i and %i.\n",numberInvalidMsg,1,m->num_linked+1);
    }
    else
    {
      break;
    }
  }

  return selection-1; //offset by one to account for zero-indexing
}

//Default menu behavior handling input loop
void RunMenu(Menu* m, int isRoot)
{
  if (!m) return;
  int active = 1;
  while(active)
  {
    printf("%s",menuBorder);
    printf("%s:\n\n", m->title);
    printf("%s\n", m->description);
    printf("%s\n", inputDirections);

    //Display menu options
    for (int i = 0; i< m->num_linked; i++)
    {
      printf("\t%i - %s\n",i+1,m->linkedMenus[i]->title);
    }

    //Display return/exit option
    if (isRoot)
    {
      printf("\t%i - %s\n",m->num_linked+1,exitTitle);
    }
    else
    {
      printf("\t%i - %s\n",m->num_linked+1,returnTitle );
    }

    printf("%s",menuBorder);

    int selection = GetOptionNumber(m); //obtain user input
    //If the selection corresponds to the "return or quit" command, run it.
    if (selection == m->num_linked)
    {
        EndMenu(isRoot);
        active = 0;
    }
    //Otherwise, it's just a regular menu
    else
    {
      //If the callback is defined, call it.
      if (m->linkedMenus[selection]->callback)
      {
        void (*callback)() = (m->linkedMenus[selection]->callback);
        (*callback)();
      }
      //If it's not defined, call the regular RunMenu function
      else
      {
        RunMenu(m->linkedMenus[selection],0);
      }
    }
  }

}

//Adds a menu/option to the current menu list, provided the maximum number of options has not been reached
void AddLinkedMenu(Menu* src, Menu* linked)
{
  if (!src || !linked) return;
  if (src->num_linked < MAX_OPTIONS)
  {
    src->linkedMenus[src->num_linked] = linked;
    src->num_linked++;
  }
  else
  {
    printf("%s\n", tooManyOptionsMsg);
  }
}

//Helper function for setting string fields
void SetMenuString(char* field, const char* s, int limit)
{
  int len = strlen(s);
  strncpy(field,s,limit);
  if (len>limit)
  {
    len = limit-1;
    PrintBufferError();
    field[len]='\0';
  }
}

//Sets the menu title
void SetMenuTitle(Menu* m, const char* s)
{
  if (!m) return;
  SetMenuString(m->title,s,TITLE_BUFFER_SIZE);

}

//Sets the menu description
void SetMenuDescription(Menu* m, const char* s)
{
  if (!m) return;
  SetMenuString(m->description,s,DESCRIPTION_BUFFER_SIZE);
}

//Basically, an exception handler for menu inputs that are too long.
void PrintBufferError()
{
  printf("%s\n",stringBufferOverflowMsg);
}

//Recursively delete menu options
void DeleteMenu(Menu* m)
{
  if (!m) return;
  free(m->title);
  free(m->description);
  for (int i = 0; i < m->num_linked; i++)
  {
    DeleteMenu(m->linkedMenus[i]);
  }
  free(m->linkedMenus);
  free(m);
}
