#include <stdio.h>
#define MENU_STRINGS

/*
Store menu text in this file. Call them by reference when generating the menus.
*/


const char* menuBorder = "/////////////////////////////////////////\n";
const char* menuListStart = "/\t";
const char* stringBufferOverflowMsg = "Error: the text provided exceeds the maximum character limit.\n";
const char* tooManyOptionsMsg = "Error: the current menu can\'t support any more options. Menu option not added.\n";
const char* inputDirections = "Enter a number corresponding to one of the options below.\nType only the number, and then press Enter or Return.\n";
const char* returnMessageRoot = "Exiting program.\n";
const char* returnMessageNode = "Returning to previous menu.\n";
const char* exitTitle = "Exit program\n";
const char* returnTitle = "Return to previous menu\n";
const char* inputPrompt = "Type the desired number:";
const char* numberInvalidMsg = "Invalid number selected. Please choose a number between ";
const char* sectionBreak = "\n\n";
