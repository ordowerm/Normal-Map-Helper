#ifndef PNG_UTILS
#include "./headers/pngutils.h"
#endif


//Converts PNG binary file into something legible for console printing
void PrintPngAsAscii(char* path)
{
  FILE* file = fopen(path, "rb");

  if(file)
  {
    char current;
    do
    {

      //for readability, we make a for loop that prints a line break whenever we reach the end of 2 chunks
      for (int i = 0; i<2*PNG_CHUNK_SIZE;i++)
      {
          if (i==PNG_CHUNK_SIZE){printf("\t");} //if we've reached the end of the first chunk, add whitespace

          current = fgetc(file);
          if (current !=EOF)
          {
            printf("%.2x ", (unsigned)current);

          }
          else
          {
            i = 2*PNG_CHUNK_SIZE; //end the for loop if EOF is reached
          }
      }

      printf("\n");
    } while (current != EOF);

    fclose(file);
  }
  else
  {
    printf("Error: invalid file path");
  }
}
