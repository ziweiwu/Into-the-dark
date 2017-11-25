/*****************************************************************************
** program name: Saturn.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: an implementation file for class Saturn. It inherits from the
the Space class.
*****************************************************************************/
#include "Saturn.hpp"

/*****************************************************************************
                           Constructor
 *****************************************************************************/
Saturn::Saturn() {
    set_name("Saturn");
    set_description(
        "You have entered Saturn. A planet with "
        "beautiful planetary rings.");
    set_fuelcost(120);
    set_antiparticles(50);
    set_fuelpacks(30);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Saturn::~Saturn() {}

/*****************************************************************************
                           Arrive
******************************************************************************/
void Saturn::arrive(ship* myship) {
    myship->consume_fuel(get_fuelcost());
    
    
    if(myship->ran_out_fuel()){return;}
    
    std::cout << std::endl;
    std::cout << "Frontier has arrived to Saturn. " << std::endl;
    myship->consume_fuel(100);
    std::cout << "Detects strong gravitional signals in plantery ring."
              << std::endl;
}

/*****************************************************************************
                           explore
******************************************************************************/
void Saturn::explore(ship* myship) {
    // consume the fuel cost

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Explorative probe is heading toward"
              << get_name() <<"."<< std::endl;
    myship->consume_fuel(get_fuelcost());

    if (myship->ran_out_fuel()) {
        return;
    }
   
    int roll1 = 0;
    roll1 = rand() % (3) + 1;

    // a chance to gather additional anti-particles
    if (roll1 == 1) {
        std::cout << "Probe detected the presence of anti-particles in the "
                     "planetary ring."
                  << std::endl;
        
        int extra_particles = 0;
        extra_particles = rand() % (6) + 1;

        std::cout <<extra_particles<< " anti-particles are collected." << std::endl;
        myship->add_antiParticles(5);
        set_antiparticles(get_antiparticles()-extra_particles);
    }

    // a chance to encounter comets and cause leaking fuel
    if (roll1 == 2) {
        std::cout
            << "Encountered a fleet of comets as the probe is acrossing the "
               "planetary rings."
            << std::endl;

        std::cout << "Caused a leakage in fuel tank." << std::endl;
        myship->consume_fuel(100);
    }

    std::cout << "Explorative probe has entered the atmosphere of "
              << get_name() <<"."<< std::endl;

    // if anti-particles are available for gathering
    if (get_antiparticles() > 0) {
        int roll2 = 0;
        roll2 = rand() % (5) + 5;

        std::cout << roll2 << " anti-particles are found." << std::endl;
        myship->add_antiParticles(roll2);
        set_antiparticles(get_antiparticles() - roll2);
    }

    // if fuel packss are available for gathering
    if (get_fuelpacks() > 0) {
        int roll3 = 0;
        roll3 = rand() % (5) + 5;

        std::cout << roll3 << " fuel packs are found." << std::endl;
        myship->add_fuelPacks(roll3);
        set_fuelpacks(get_fuelpacks() - roll3);
    
    }
}
