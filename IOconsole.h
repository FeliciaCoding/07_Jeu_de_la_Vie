#ifndef INC_07_JEU_DE_LA_VIE_IOCONSOLE_H
#define INC_07_JEU_DE_LA_VIE_IOCONSOLE_H


#include <string>

#ifdef _WIN32
#define CLEAR_SCREEN "CLS"
#else
#define CLEAR_SCREEN "clear"
#endif

const int GAME_ROW               = 9;
const int GAME_COL               = 9;
// Assume 1000 maximum generations
const int MAX_NUM_OF_GENERATIONS = 1000;


void printIntroduction();

void printLineOfDashes();

void printGenerationTitle();

void printGrid(int grid[][GAME_COL]);

void printEndMessage(std::string_view endMessage);

#endif //INC_07_JEU_DE_LA_VIE_IOCONSOLE_H
