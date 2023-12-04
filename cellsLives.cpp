#include "cellsLives.h"
#include <iostream>
using namespace std;

// change row and column value to set the canvas size
const int row = 8;
const int col = 8;

// creates row boundary
int table()
{

}





// returns the count of alive neighbours
int liveNeighbourCell(int neighbours[row][col], int rowCell, int colCell)
{
  int aliveCells = 0;
  const int radius = 1;
  for (int dv = -radius; dv <= radius; ++dv) {
    for (int dh = -radius; dh <= radius; ++dh) {
      if (dv == 0 && dh == 0) {
        int r = (rowCell + dv + row) % row;
        int c = (colCell + dh + col) % col;

        aliveCells += neighbours[r][c];
      }
    }
  }

  return aliveCells;
}

void generateNextGen(){


}







int a[row][col], b[row][col];
int i, j;
int neighbour_live_cell;

// generate matrix canvas with random values (live and
// dead cells)
for (i = 0; i < row; i++) {
for (j = 0; j < col; j++) {
a[i][j] = rand() % 2;
}
}

// print array matrix
cout << "Initial Stage:";
row_line();
for (i = 0; i < row; i++) {
cout << ":";
for (j = 0; j < col; j++) {
cout << "  " << a[i][j] << "  :";
}
row_line();
}

// next canvas values based on live neighbour count
for (i = 0; i < row; i++) {
for (j = 0; j < col; j++) {
neighbour_live_cell
= count_live_neighbour_cell(a, i, j);
if (a[i][j] == 1
&& (neighbour_live_cell == 2
|| neighbour_live_cell == 3)) {
b[i][j] = 1;
}

else if (a[i][j] == 0
&& neighbour_live_cell == 3) {
b[i][j] = 1;
}

else {
b[i][j] = 0;
}
}
}

// print next generation
cout << "\nGeneration:";
row_line();
for (i = 0; i < row; i++) {
cout << ":";
for (j = 0; j < col; j++) {
cout << "  " << b[i][j] << "  :";
}
row_line();
}