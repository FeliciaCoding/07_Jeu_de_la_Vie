#include <cstdlib>
#include "IOconsole.h"
#include "gameOfLife.h"

using namespace std;

int main() {

    printIntroduction();

    runGameOfLife();

    return EXIT_SUCCESS;
}