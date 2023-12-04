
#include <iostream>
#include <cstdlib>
#include <thread>

#include "cellsLives.h"
#include "display.h"

using namespace std;

int main()
{
  vector<vector<char>> grid = {
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', 'X', 'X', 'X', '.', '.', '.'},
      {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
  };

  int maxGenerations = 100;
  int generation = 0;

  while (generation < maxGenerations) {
    displayGeneration(grid, generation);

    // Generate the next generation
    vector<vector<char>> nextGeneration = grid;
    generateNextGeneration(nextGeneration);

    // Check for no change between generations
    if (hasNoChange(grid, nextGeneration)) {
      cout << "No more evolution. Stopping the program.\n";
      break;
    }

    // Update the current generation
    grid = nextGeneration;

    // Pause for a short duration to visualize the changes
    this_thread::sleep_for(chrono::milliseconds(500));

    generation++;
  }

  return 0;
}