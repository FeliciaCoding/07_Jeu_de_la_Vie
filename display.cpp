#include "display.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void displayGeneration(const vector<vector<char>>& grid, int generation) {
  clearScreen();
  cout << "------------------------------\n";
  cout << "         GENERATION NO " << generation << "\n";
  cout << "------------------------------\n";
  for (const auto& row : grid) {
    for (char cell : row) {
      cout << "  " << cell;
    }
    cout << "\n";
  }
  cout << endl;
}

void displayGeneration(){

}