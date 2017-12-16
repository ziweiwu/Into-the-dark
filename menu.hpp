/*****************************************************************************
** program name: menu.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: a header file for class Menu. It contains a constructor and 
    a destructor. Member variables including currentLocation, quitGame.
    Set and get function for quitGame. Member functions including start_menu
    planet_menu, and draw_map. 
*****************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include "ship.hpp"
#include "Space.hpp"
#include "Jupiter.hpp"
#include "Mars.hpp"
#include "Saturn.hpp"
#include "Enceladus.hpp"
#include "Titan.hpp"
#include "black_hole.hpp"

class Menu {
   private:
    Space* currentLocation;
    bool quitGame;

   public:
    // constructors and destructor
    Menu();   // constructor
    ~Menu();  // destructor

    // set function 
    void set_quitGame(bool);
    
    // get function
    bool get_quitGame();
    
    // member function
    void start_menu();
    void planet_menu(Space*, ship*);
    void draw_map(Space*);
    
};

#endif
