/*****************************************************************************
** Program name: main.cpp
** Author: Wu, Ziwei
** Date: 2017-11-25
** Description: the main function for the program. It initializes the game
   into the darkness
*****************************************************************************/
#include <ctime>
#include "menu.hpp"

/**
   How to use:
   Compile the program by typing command "make" in the command line, then
   execute "./main".  Clean the program files by "make clean".
    
   The program initialize the game into the darkness. The player will explore
   various planets, and gather resources, and to find the passage to save humanity
 */

int main() {
    // set a random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    Menu menu1;

    return 0;
}
