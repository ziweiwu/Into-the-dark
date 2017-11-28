/*****************************************************************************
** program name: ship.hpp
** author: Wu, Ziwei
** date: 2017-10-25
** description: a header file for class ship. It includes the
   a default constructor, a copy constructor and a destructor. It includes
*****************************************************************************/
#ifndef ship_hpp
#define ship_hpp

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
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
    // constructors and destructor
    ship();             // constructor
    ship(const ship&);  // copy constructor
    virtual ~ship();    // destructor

    // set methods
    void set_name(std::string);
    void set_description(std::string);
    void set_fuel(int);
    void set_fuel_tank(int);
    void set_inventorySize(int);
    void set_crews(int);

    void set_antiParticles(int);
    void set_fuelPacks(int);

    void set_antiParticlesCapacity(int);
    void set_fuelPacksCapacity(int);

    void set_antiMatter_created(bool);
    
    // get methods
    std::string get_name();
    std::string get_description();
    int get_fuel();
    int get_fuel_tank();
    int get_inventorySize();
    int get_crews();
    int get_antiParticles();
    int get_fuelPacks();

    int get_antiParticlesCapacity();
    int get_fuelPacksCapacity();

    bool get_antiMatter_created();

    // member functions
    void add_antiParticles(int quantity);
    void add_fuelPacks(int quantity);
    
    void use_fuelPacks();
    void create_antiMatter();

    void display_status();

    void consume_fuel(int );

    //helper functions
    bool antiParticles_isfull();
    bool fuelPacks_isfull();
    bool ran_out_fuel();
};

#endif
