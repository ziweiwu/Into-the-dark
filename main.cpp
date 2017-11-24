/*****************************************************************************
** Program name: main.cpp
** Author: Wu, Ziwei
** Date: 2017-10-25
** Description: the main function for the program. It initializes the game
   play and allows the user to choose two characters to fight.
*****************************************************************************/
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <limits>
#include "menu.hpp"

/**
   How to use:
   Compile the program by typing command "make" in the command line, then
   execute "./main".  Clean the program files by "make clean".

   The game askes user to choose two characters from five characters type
   to fight. A fight will takes place where each character's attack,
   defense, strength and armor information will be display for each round,
   and the final outcome of the fight will be displayed.
 */

int main() {
    // set a random seed
    srand(time(NULL));

    Menu menu1;

    return 0;
}
