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


//
void GetColorCallback()
{

}



void FlushInput(char* buff, int spaces)
{
  for (int i = 0; i<spaces; i++)
  {
    buff[i]='\0';
  }

}


//Gets a cardinal direction
void GetCardinalCallback(Menu* m,Color* color1,Color* color2,Color* outColor)
{
  char buffer[USER_BUFFER_SIZE];
  int active = 1;
  while(active){
    printf("\n%s\n",cardinalPrompt);
    fflush(stdout);
    scanf("%s",buffer);

    if (strcmp(buffer,"q")==0 || strcmp(buffer,"Q")==0)
    {
        printf("%s\n",returnMessageNode );
        sleep(1);
        while ((getchar()) !='\n'){} //clears input buffer
        return;
    }

    Color result = GetCardinal(buffer);
    PrintHex(&result);
    if (CEquals(result,black))
    {
      printf("\n%s\n",cardinalErrorMsg);
      printf("%s\n",returnMessageNode );
      while ((getchar()) !='\n'){} //clears input buffer
      sleep(1);
      return;
    }
    if (color1)
    {
      (*color1) = result;
    }
  }

}
