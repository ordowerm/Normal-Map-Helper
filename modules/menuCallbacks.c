#include "./headers/menuCallbacks.h"

//Displays message indicating the completion of a menu function
void EndMenu(int isRoot)
{
  if (isRoot)
  {
    printf("%s%s",returnMessageRoot,sectionBreak);
  }
  else
  {
    printf("%s%s",returnMessageNode,sectionBreak);
  }
}


void TestCallback()
{
  printf("\n%s\n","I'm a test callback!\n");
}
