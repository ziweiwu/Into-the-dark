/*****************************************************************************
** program name: Space.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: a header file for class Space. It includes the
   a default constructor, a copy constructor and a destructor. It includes
   member variables name, description, fuelCost, antiParticles_available;
   fuelPacks_available. Four pointers variables that specify the connection
   that the space has including up, down, left and right. Set and get
   functions for each of the variables. Two pure abstract virutal functions
   arrive and explore.
*****************************************************************************/
#ifndef space_hpp
#define space_hpp

#include <iomanip>
#include <string>
#include "ship.hpp"

class Space {
   private:
    // member variables
    std::string name;
    std::string description;
    int fuelCost;                 // fuel cost to travel or explore the planet
    int antiParticles_available;  // anti-particles available on the planet
    int fuelPacks_available;      // fuel packs available on the planet

    // pointer varibles
    Space *left;
    Space *right;
    Space *up;
    Space *down;

   public:
    // constructors and destructor
    Space();               // constructor
    Space(const Space &);  // copy constructor
    virtual ~Space();      // destructor

    // set methods
    void set_name(std::string);
    void set_description(std::string);
    void set_fuelcost(int);
    void set_antiparticles(int);
    void set_fuelpacks(int);

    void set_left(Space *);
    void set_right(Space *);
    void set_up(Space *);
    void set_down(Space *);

    // get methods
    std::string get_name();
    std::string get_description();
    int get_fuelcost();
    int get_antiparticles();
    int get_fuelpacks();

    Space *get_left();
    Space *get_right();
    Space *get_up();
    Space *get_down();

    // virtual functions
    virtual void arrive(ship *) = 0;
    virtual void explore(ship *) = 0;
};

#endif
