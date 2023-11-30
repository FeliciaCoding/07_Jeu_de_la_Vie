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


// returns the count of alive neighbours
int count_live_neighbour_cell(int a[GAME_ROW][GAME_COL], int r, int c) {
    int i, j, count = 0;
    for (i = r - 1; i <= r + 1; i++) {
        for (j = c - 1; j <= c + 1; j++) {
            if ((i == r && j == c) || (i < 0 || j < 0)
                || (i >= GAME_ROW || j >= GAME_COL)) {
                continue;
            }
            if (a[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {

    // TODO : Introduction message (This program... )

    int currentGrid[GAME_ROW][GAME_COL], nextGrid[GAME_ROW][GAME_COL];
    int i, j;
    int neighbour_live_cell;

    // generate matrix canvas with random values (live and
    // dead cells)
    for (i = 0; i < GAME_ROW; i++) {
        for (j = 0; j < GAME_COL; j++) {
            currentGrid[i][j] = rand() % 2;
        }
    }

// TODO : printTitles Funcitons
    const int    GAME_WIDTH      = 30;
    const char   TITLE_SEPERATOR = '-';
    const char   SPACE           = ' ';
    const string TITLE           = "GENRATION NO ";
    const int    NUM_GENERATIONS = 1;  // TODO : Set back to 6 once the buffer grid is created

    system(CLEAR_SCREEN);
    cout << setw(GAME_WIDTH) << setfill(TITLE_SEPERATOR) << "" << endl;
    cout << setw(9) << setfill(SPACE) << "" << TITLE << "0" << endl;
    cout << setw(GAME_WIDTH) << setfill(TITLE_SEPERATOR) << "" << endl;

    printGrid(currentGrid);


    // calculate the subsequent generations
    for (int gen = 1; gen <= NUM_GENERATIONS; ++gen) {
        system(CLEAR_SCREEN);
        cout << setw(GAME_WIDTH) << setfill(TITLE_SEPERATOR) << "" << endl;
        cout << setw(9) << setfill(SPACE) << "" << TITLE << gen << endl;
        cout << setw(GAME_WIDTH) << setfill(TITLE_SEPERATOR) << "" << endl;
    }

    // next canvas values based on live neighbour count
    for (i = 0; i < GAME_ROW; i++) {
        for (j = 0; j < GAME_COL; j++) {
            neighbour_live_cell
                    = count_live_neighbour_cell(currentGrid, i, j);
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

    printGrid(nextGrid);

    return 0;
}