#ifndef INC_07_JEU_DE_LA_VIE_GAMEOFLIFE_H
#define INC_07_JEU_DE_LA_VIE_GAMEOFLIFE_H

#include "IOconsole.h"

void generateRandomGrid(int currentGrid[GAME_ROW][GAME_COL]);

int countLiveNeighbourCell(int currentGrid[GAME_ROW][GAME_COL], int row, int col);

void determineNextGrid(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]);

bool hasNothingToEvaluate(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]);

void swapGrid(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]);

void runGameOfLife();

#endif //INC_07_JEU_DE_LA_VIE_GAMEOFLIFE_H
