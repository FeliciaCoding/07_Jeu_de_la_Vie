#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

#ifdef _WIN32
#define CLEAR_SCREEN "CLS"
#else
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

const int GAME_ROW = 9;
const int GAME_COL = 9;

void printIntroduction() {
    cout << "This program is a C++ implementation of Conway's Game of Life\n"
            "which is a cellular automaton devised by "
            "the British mathematician John Horton Conway in 1970.\n\n";
}


const int  GAME_WIDTH      = 30;
const char TITLE_SEPERATOR = '-';

void printLineOfDashes() {
    cout << setw(GAME_WIDTH) << setfill(TITLE_SEPERATOR) << "" << endl;
}


const char   SPACE           = ' ';
const string TITLE           = "GENRATION NO ";
const int    NUM_GENERATIONS = 6;  // TODO : Set back to 6 once the buffer grid is created

static int gen = 0;

void printGenerationTitle() {
    if (gen <= NUM_GENERATIONS) {
        system(CLEAR_SCREEN);
        printLineOfDashes();
        cout << setw(9) << setfill(SPACE) << "" << TITLE << gen << endl;
        printLineOfDashes();
        ++gen;
    } else {
        return;
    }
}


void printGrid(int grid[][GAME_COL]) {
    // print column indice
    const int WIDE_ELEMENT = 3;
    cout << setw(WIDE_ELEMENT) << setfill(' ') << "";
    for (int col = 0; col < GAME_COL; ++col) {
        std::cout << right << std::setw(WIDE_ELEMENT) << col;
    }
    cout << endl;

    // print grid with row indices
    for (int row = 0; row < GAME_ROW; ++row) {
        cout << right << setw(WIDE_ELEMENT) << row;
        for (int col = 0; col < GAME_COL; ++col) {
            char symbol = (grid[row][col] == 1) ? 'X' : '.';
            cout << setw(WIDE_ELEMENT) << symbol;
        }
        cout << endl;
    }
    cout << endl;
}


int generateRandomGrid(int currentGrid[GAME_ROW][GAME_COL]) {
    for (int i = 0; i < GAME_ROW; i++) {
        for (int j = 0; j < GAME_COL; j++) {
            currentGrid[i][j] = rand() % 2;
        }
    }
}

// Conway's Game of Life: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
// live: x < 2, die
// x = 2 or x = 3, live
// x > 3 , die
// die : x = 3, live
// returns the count of alive neighbours


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

int determineNextGrid(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]) {
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

void swapGrid(int currentGrid[GAME_ROW][GAME_COL], int nextGrid[GAME_ROW][GAME_COL]){
    int tempGrid[GAME_ROW][GAME_COL];

    for (int i = 0; i < GAME_ROW; i++){
        for (int j = 0; j < GAME_COL; j++){
            tempGrid[i][j]=currentGrid[i][j];
        }
    }

    for (int i = 0; i < GAME_ROW; i++){
        for (int j = 0; j < GAME_COL; j++){
            currentGrid[i][j]=nextGrid[i][j];
        }
    }

    for (int i = 0; i < GAME_ROW; i++){
        for (int j = 0; j < GAME_COL; j++){
            nextGrid[i][j]=tempGrid[i][j];
        }
    }

}

int main() {

    int currentGrid[GAME_ROW][GAME_COL], nextGrid[GAME_ROW][GAME_COL];

    printIntroduction();

    // TODO : startGameOfLive function
    generateRandomGrid(currentGrid);

    for (int i = 0; i <= NUM_GENERATIONS; ++i ){

        printGenerationTitle();

        printGrid(currentGrid);

        determineNextGrid(currentGrid, nextGrid);

        swapGrid(currentGrid, nextGrid);

    }


    return EXIT_SUCCESS;
}