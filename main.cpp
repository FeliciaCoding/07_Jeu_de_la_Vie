#include <cstdlib>
#include "IOconsole.h"
#include "gameOfLife.h"

using namespace std;

int main() {

    // should we put printIntroduction() in the function of runGameOfLife() ?
    printIntroduction();

    runGameOfLife();

    return EXIT_SUCCESS;
}