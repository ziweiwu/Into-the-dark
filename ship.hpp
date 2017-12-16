/*****************************************************************************
** program name: ship.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: a header file for class ship. It includes the
   a default constructor, a copy constructor and a destructor. It includes
   member variables name, description, fuel, fuel_tank, fuelPacks,
   fuelPacks_capacity, antiParticles, antiParticles_capacity,
   antiMatter_created. Set and get methods for each of its variable.
   Two vector container antParticles_storage and fuelPacks_storage. Member
   functions include add_antiParticles, create_antiMatter, add_fuelPacks, 
   consume_fuel, display_status. Helper functions include antiParticles_isfull
   fuelPacks_isfull, and ran_out_fuel.
*****************************************************************************/
#ifndef SHIP_HPP
#define SHIP_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

class ship {
   private:
    // member variables
    std::string name;
    std::string description;
    int crews;
    int fuel;
    int fuel_tank;
    int fuelPacks;
    int fuelPacks_capacity;
    int antiParticles;
    int antiParticles_capacity;
    bool antiMatter_created;

    std::vector<std::string> antiParticles_storage;
    std::vector<std::string> fuelPacks_storage;

   public:
    ship();             // constructor
    virtual ~ship();    // destructor

    // set methods
    void set_name(std::string);
    void set_description(std::string);
    void set_fuel(int);
    void set_fuel_tank(int);
    void set_crews(int);

    void set_antiParticles(int);
    void set_antiParticlesCapacity(int);

    void set_fuelPacks(int);
    void set_fuelPacksCapacity(int);

    void set_antiMatter_created(bool);

    // get methods
    std::string get_name();
    std::string get_description();
    int get_fuel();
    int get_fuel_tank();
    int get_crews();

    int get_antiParticles();
    int get_antiParticlesCapacity();

    int get_fuelPacks();
    int get_fuelPacksCapacity();

    bool get_antiMatter_created();

    // member functions
    void add_antiParticles(int quantity);
    void create_antiMatter();

    void add_fuelPacks(int quantity);
    void use_fuelPacks();
    void consume_fuel(int);

    void display_status();

    // helper functions
    bool antiParticles_isfull();
    bool fuelPacks_isfull();
    bool ran_out_fuel();
};

#endif
