#ifndef INC_07_JEU_DE_LA_VIE_IOCONSOLE_H
#define INC_07_JEU_DE_LA_VIE_IOCONSOLE_H


#include <string>

#ifdef _WIN32
#define CLEAR_SCREEN "CLS"
#else
#define CLEAR_SCREEN "clear"
#endif

const int GAME_ROW        = 9;
const int GAME_COL        = 9;
const int NUM_GENERATIONS = 6;


void printIntroduction();

void printLineOfDashes();

void printGenerationTitle();

void printGrid(int grid[][GAME_COL]);

#endif //INC_07_JEU_DE_LA_VIE_IOCONSOLE_H
