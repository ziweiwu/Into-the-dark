/*****************************************************************************
** program name: Space.cpp
** author: Wu, Ziwei
** date: 2017-10-25
** description: an header file for class Space. It includes the
   a default constructor, a copy constructor and a destructor. It includes
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
void Space::set_name(std::string name1) { name = name1; }

void Space::set_description(std::string descriptions1) {
    description = descriptions1;
}

void Space::set_fuelcost(int fuelcost1) { explore_fuelcost = fuelcost1; }

void Space::set_antiparticles(int n_antiparticles) {
    num_antiparticles = n_antiparticles;
}

void Space::set_fuelpacks(int n_fuelpacks) { num_fuelpacks = n_fuelpacks; }

void Space::set_left(Space* l) { left = l; }

void Space::set_right(Space* r) { right = r; }

void Space::set_up(Space* u) { up = u; }

void Space::set_down(Space* d) { down = d; }

/*****************************************************************************
 *                          get function
 *****************************************************************************/
std::string Space::get_name() { return name; }
std::string Space::get_description() { return description; }
int Space::get_fuelcost() { return explore_fuelcost; }
int Space::get_antiparticles() { return num_antiparticles; }
int Space::get_fuelpacks() { return num_fuelpacks; }

Space* Space::get_left() { return left; }
Space* Space::get_right() { return right; }
Space* Space::get_up() { return up; }
Space* Space::get_down() { return down; }
