/*****************************************************************************
** program name: Space.cpp
** author: Wu, Ziwei
** date: 2017-10-25
** description: an implementation file for class Space. It includes the
   a default constructor, a copy constructor and a destructor. It includes
   member variables name, description, fuelCost, antiParticles_available;
   fuelPacks_available. Four pointers variables that specify the connection
   that the space has including up, down, left and right. Set and get
   functions for each of the variables. Two pure abstract virutal functions
   arrive and explore.
*****************************************************************************/
#include "Space.hpp"

/*****************************************************************************
 *                          Constructor
 *****************************************************************************/
Space::Space() {
    set_name("space");
    set_description("This is just a space");
    set_fuelcost(0);
    set_antiparticles(0);
    set_fuelpacks(0);

    set_up(nullptr);
    set_down(nullptr);
    set_left(nullptr);
    set_right(nullptr);
}

/*****************************************************************************
 *                          Destructor
 *****************************************************************************/
Space::~Space() {}

/*****************************************************************************
 *                          set functions
 *****************************************************************************/
void Space::set_name(std::string n) { name = n; }
void Space::set_description(std::string d) { description = d; }
void Space::set_fuelcost(int fc) { fuelCost = fc; }
void Space::set_antiparticles(int p) { antiParticles_available = p; }
void Space::set_fuelpacks(int fp) { fuelPacks_available = fp; }

void Space::set_left(Space* l) { left = l; }
void Space::set_right(Space* r) { right = r; }
void Space::set_up(Space* u) { up = u; }
void Space::set_down(Space* d) { down = d; }

/*****************************************************************************
 *                          get function
 *****************************************************************************/
std::string Space::get_name() { return name; }
std::string Space::get_description() { return description; }
int Space::get_fuelcost() { return fuelCost; }
int Space::get_antiparticles() { return antiParticles_available; }
int Space::get_fuelpacks() { return fuelPacks_available; }

Space* Space::get_left() { return left; }
Space* Space::get_right() { return right; }
Space* Space::get_up() { return up; }
Space* Space::get_down() { return down; }
