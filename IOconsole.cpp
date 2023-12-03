
#include "IOconsole.h"
#include <iostream>
#include <iomanip>
#include <string_view>


using namespace std;


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

const std::string TITLE = "GENERATION NO ";
const char        SPACE = ' ';
static int        gen   = 0;

void printGenerationTitle() {
    if (gen <= MAX_NUM_OF_GENERATIONS) {
        system(CLEAR_SCREEN);
        printLineOfDashes();
        cout << setw(8) << setfill(SPACE) << "" << TITLE << gen << endl;
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

void printEndMessage(string_view endMessage) {
    cout << endl << endMessage << endl;
}

