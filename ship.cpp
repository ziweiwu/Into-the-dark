/*****************************************************************************
** program name: ship.cpp
** author: Wu, Ziwei
** date: 2017-10-25
** description: an implementation file for class ship. It includes the
   a default constructor, a copy constructor and a destructor. It includes
*****************************************************************************/
#include "ship.hpp"

/*****************************************************************************
 *                          Constructor
 *****************************************************************************/
ship::ship() {
    set_name("Frontier");
    set_description(
        "An advanced ship that's designd primarily for space"
        " exploration. It's equipped with a explore craft, a gravitional"
        " wave detector, and a particle accelerator");
    set_fuel(1600);
    set_fuel_tank(2000);
    set_antiParticlesCapacity(200);
    set_fuelPacksCapacity(100);
    set_crews(100);

    set_fuelPacks(50);
    set_antiParticles(0);

    set_antiMatter_created(false);
}

/*****************************************************************************
                           Destructor
 *****************************************************************************/
ship::~ship() {
    fuelPacks_storage.clear();
    antiParticles_storage.clear();
}

/*****************************************************************************
                          set functions
 *****************************************************************************/
void ship::set_name(std::string n) { name = n; }
void ship::set_description(std::string d) { description = d; }
void ship::set_fuel(int f) { fuel = f; }
void ship::set_fuel_tank(int ft) { fuel_tank = ft; }
void ship::set_crews(int c) { crews = c; }

void ship::set_antiParticles(int p) { antiParticles = p; }
void ship::set_fuelPacks(int fp) { fuelPacks = fp; }

void ship::set_antiParticlesCapacity(int c) { antiParticles_capacity = c; }
void ship::set_fuelPacksCapacity(int c) { fuelPacks_capacity = c; }

void ship::set_antiMatter_created(bool flag) { antiMatter_created = flag; }

/*****************************************************************************
                          get function
 *****************************************************************************/
std::string ship::get_name() { return name; }
std::string ship::get_description() { return description; }
int ship::get_fuel() { return fuel; }
int ship::get_fuel_tank() { return fuel_tank; }
int ship::get_crews() { return crews; }

int ship::get_antiParticles() { return antiParticles; }
int ship::get_fuelPacks() { return fuelPacks; }

int ship::get_antiParticlesCapacity() { return antiParticles_capacity; }
int ship::get_fuelPacksCapacity() { return fuelPacks_capacity; }

bool ship::get_antiMatter_created() { return antiMatter_created; }

/*****************************************************************************
                         add_antiParticles
*****************************************************************************/
void ship::add_antiParticles(int quantity) {
    std::cout << quantity << " anti-particles are being collected."
              << std::endl;
    for (int i = 0; i < quantity; i++) {
        if (antiParticles_isfull()) {
            std::cout << "Anti-particles chamber is full." << std::endl;
            return;
        }
        antiParticles_storage.push_back("anti-particle");
        set_antiParticles(get_antiParticles() + 1);
    }
}

/*****************************************************************************
                    antiParticles_isfull
*****************************************************************************/
bool ship::antiParticles_isfull() {
    if (get_antiParticles() >= get_antiParticlesCapacity()) {
        return true;
    }
    return false;
}
/*****************************************************************************
                         add_fuelPacks
*****************************************************************************/
void ship::add_fuelPacks(int quantity) {
    std::cout << quantity << " fuelpacks are being collected." << std::endl;
    for (int i = 0; i < quantity; i++) {
        if (fuelPacks_isfull()) {
            std::cout << "Fuelpacks chamber is full." << std::endl;
            return;
        }
        fuelPacks_storage.push_back("fuelpack");
        set_fuelPacks(get_fuelPacks() + 1);
    }
}

/*****************************************************************************
                    fuelPacks_isfull
*****************************************************************************/
bool ship::fuelPacks_isfull() {
    if (get_fuelPacks() >= get_fuelPacksCapacity()) {
        return true;
    }
    return false;
}

/*****************************************************************************
                         use_fuelPacks
*****************************************************************************/
void ship::use_fuelPacks() {
    // check if fuel pack is available
    if (get_fuelPacks() <= 0) {
        std::cout << "No more fuel packs left." << std::endl;
        return;
    }

    // ask for number of packs to use
    int quantity = 0;
    std::cout << "Please enter the number of fuel packs you would to use";
    std::cout << "(0-" << get_fuelPacks() << ")" << std::endl;

    bool notInt = false;
    do {
        std::cin >> quantity;
        notInt = std::cin.fail();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (quantity < 0 || quantity > get_fuelPacks() || notInt) {
            std::cout << "Invalid input. Please try again: ";
        }
    } while (quantity < 0 || quantity > get_fuelPacks() || notInt);

    // recovery the fuel using fuel packs
    set_fuelPacks(get_fuelPacks() - quantity);
    int fuelRecovery = quantity * 20;
    std::cout << fuelRecovery << " fuel is added." << std::endl;

    if (fuelRecovery + get_fuel() > get_fuel_tank()) {
        set_fuel(2000);
        std::cout << "Fuel tank is full" << std::endl;
    } else {
        set_fuel(get_fuel() + fuelRecovery);
    }
    // display the current fuel level
    std::cout << "Current fuel: " << get_fuel() << "/" << get_fuel_tank()
              << std::endl;
}

/*****************************************************************************
                      create_antiMatter
*****************************************************************************/
void ship::create_antiMatter() {
    if (get_antiParticles() >= 100) {
        set_antiParticles(get_antiParticles() - 100);

        std::cout << "Particle accelerator ejected 100 anti-particles"
                  << std::endl;

        std::cout << "Anti-matter is created." << std::endl;

        set_antiMatter_created(true);
        return;
    }

    std::cout << "Not enough anti-particles for particle accelerator."
              << std::endl;

    return;
}

/*****************************************************************************
                     display_status
*****************************************************************************/
void ship::display_status() {
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------"
              << std::endl;
    std::cout << "         Frontier central monitor panel           "
              << std::endl;
    std::cout << std::endl;
    std::cout << "         Crew members  : " << get_crews() << std::endl;
    std::cout << "         Fuel          : " << get_fuel() << "/"
              << get_fuel_tank() << std::endl;
    std::cout << "         Anti-particles: " << get_antiParticles()
              << std::endl;
    std::cout << "         Fuel packs    : " << get_fuelPacks() << std::endl;
    if (get_antiMatter_created()) {
        std::cout << "         Anti-matter   : Created" << std::endl;
    }

    std::cout << "----------------------------------------------------------"
              << std::endl;
    std::cout << std::endl;
}

/*****************************************************************************
                     consume_fuel
*****************************************************************************/
void ship::consume_fuel(int fuel_cost) {
    if (get_fuel() - fuel_cost <= 0) {
        std::cout << "Fuel have ran out." << std::endl;
        set_fuel(0);
        return;
    }

    set_fuel(get_fuel() - fuel_cost);
    std::cout << fuel_cost << " of fuel has been consumed." << std::endl;
}

/*****************************************************************************
                     run_out_fuel
*****************************************************************************/
bool ship::ran_out_fuel() {
    if (get_fuel() <= 0) {
        return true;
    }
    return false;
}
