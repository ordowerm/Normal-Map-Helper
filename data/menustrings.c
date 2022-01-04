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
const char* componentPromptRHex = "What is the hex value for the Red component?";
const char* componentPromptGHex = "What is the hex value for the Green component?";
const char* componentPromptBHex = "What is the hex value for the Blue component?";
const char* componentPromptR = "What is the [0,1] value for the Red component?";
const char* componentPromptG = "What is the [0,1] value for the Green component?";
const char* componentPromptB = "What is the [0,1] value for the Blue component?";
const char* cardinalErrorMsg = "Error: you input an invalid cardinal direction. Color not updated.\n";
const char* cardinalPrompt = "Input a cardinal direction or the word \'Straight\'. Enter the letter Q to return to previous menu.";
