#include <string>
#include <chrono>
#include <thread>

#include "gameOfLife.h"
#include "IOconsole.h"

using namespace std;

void generateRandomGrid(int currentGrid[GAME_ROW][GAME_COL]) {
    for (int i = 0; i < GAME_ROW; i++) {
        for (int j = 0; j < GAME_COL; j++) {
            currentGrid[i][j] = rand() % 2;
        }
    }
}

// Conway's Game of Life: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
int countLiveNeighbourCell(int currentGrid[GAME_ROW][GAME_COL], int row, int col) {
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if ((i == row && j == col) || (i < 0 || j < 0)
                || (i >= GAME_ROW || j >= GAME_COL)) {
                continue;
            }
            if (currentGrid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void determineNextGrid(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]) {
    int neighbour_live_cell;

    for (int i = 0; i < GAME_ROW; i++) {
        for (int j = 0; j < GAME_COL; j++) {
            neighbour_live_cell
                    = countLiveNeighbourCell(currentGrid, i, j);
            if (currentGrid[i][j] == 1
                && (neighbour_live_cell == 2
                    || neighbour_live_cell == 3)) {
                nextGrid[i][j] = 1;
            } else if (currentGrid[i][j] == 0
                       && neighbour_live_cell == 3) {
                nextGrid[i][j] = 1;
            } else {
                nextGrid[i][j] = 0;
            }
        }
    }
}

bool hasNothingToEvaluate(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]) {

    for (int i = 0; i < GAME_ROW; ++i) {
        for (int j = 0; j < GAME_COL; ++j) {
            if (currentGrid[i][j] != nextGrid[i][j]) {
                return false;
            }
        }
    }
    return true;
}


void swapGrid(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]) {
    int tempGrid[GAME_ROW][GAME_COL];

    for (int i = 0; i < GAME_ROW; i++) {
        for (int j = 0; j < GAME_COL; j++) {
            tempGrid[i][j] = currentGrid[i][j];
        }
    }

    for (int i = 0; i < GAME_ROW; i++) {
        for (int j = 0; j < GAME_COL; j++) {
            currentGrid[i][j] = nextGrid[i][j];
        }
    }

    for (int i = 0; i < GAME_ROW; i++) {
        for (int j = 0; j < GAME_COL; j++) {
            nextGrid[i][j] = tempGrid[i][j];
        }
    }

}


int currentGrid[GAME_ROW][GAME_COL], nextGrid[GAME_ROW][GAME_COL];

void runGameOfLife() {

    generateRandomGrid(currentGrid);

    for (int i = 0; i <= MAX_NUM_OF_GENERATIONS; ++i) {

        printGenerationTitle();

        printGrid(currentGrid);

        determineNextGrid(currentGrid, nextGrid);

        if (hasNothingToEvaluate(currentGrid, nextGrid) == true) {
            break;
        }

        swapGrid(currentGrid, nextGrid);

        // Assume buffer time 1000 milliseconds in order to see the changes between generations.
        std::chrono::milliseconds timespan(1000);
        std::this_thread::sleep_for(timespan);

    }

    string endMessage = "End of the game.";
    printEndMessage(endMessage);

}