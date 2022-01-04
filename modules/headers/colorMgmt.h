#define COLORS

/*
Forward declarations of color functions, structures, constants, and macros
*/

//RGBA space of [0,1] for each component
typedef struct color
{
  float r;
  float g;
  float b;
} Color;

//Constant strings for debug messages
const char* redLabel = "Red: ";
const char* blueLabel = "Blue: ";
const char* greenLabel = "Green: ";


//Functions
void CorrectColor(Color* c); //corrects color components whose values aren't between [0,1]
Color MakeColor(float r, float g, float b); //sets rgb values and returns the new color
void PrintHex(Color* c); //prints hex code for color
Color Lerp(Color* c0, Color* c1, float t); //linearly interpolates between two colors
void PrintFloat(Color* c);
void HexToFloat(Color* c, int r, int g, int b);


//Color constants corresponding to compass directions
const Color north = {0.5,1,0.5};
const Color south = {0.5,0,0.5};
const Color east = {1,0.5,0.5};
const Color west = {0,0.5,0.5};
const Color straight = {0.5,0.5,1};

//Other color constants
const Color black = {0,0,0};
const Color white = {1,1,1};


Color GetCardinal(char* input);

int CEquals(Color a, Color b); //returns whether two colors are equal
