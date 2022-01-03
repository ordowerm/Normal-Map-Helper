#include "./headers/menuCallbacks.h"

//Displays message indicating the completion of a menu function
void EndMenu(int isRoot)
{
  if (isRoot)
  {
    printf("%s",returnMessageRoot);
  }
  else
  {
    printf("%s",returnMessageNode);
  }
}
