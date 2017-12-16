/*****************************************************************************
** program name: Jupiter.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: an implementation file for class Jupiter. It inherits from the
   the Space class.
*****************************************************************************/
#include "Jupiter.hpp"

/*****************************************************************************
                           Constructor
 *****************************************************************************/
Jupiter::Jupiter() {
    set_name("Jupiter");
    set_description(
        "A gigantic planet that's made of hydrogen and helium gas.");
    set_fuelcost(130);
    set_antiparticles(60);
    set_fuelpacks(60);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Jupiter::~Jupiter() {}

/*****************************************************************************
                           Arrive
Arrive event for Jupiter 
******************************************************************************/
void Jupiter::arrive(ship* myship) {
    
    //consume the fuel cost
    myship->consume_fuel(get_fuelcost());
    if (myship->ran_out_fuel()) {
        return;
    }

    std::cout << "-----------------------------------------------------------"
              << std::endl;
    std::cout << "Frontier has arrived to " << get_name() << "." << std::endl;
    std::cout << "A violent magnetic storm is gathering on Jupiter."
              << std::endl;
}

/*****************************************************************************
                           explore
Explore event for Jupiter
******************************************************************************/
void Jupiter::explore(ship* myship) {
    std::cout << "Explorative probe is heading toward " << get_name()
              << std::endl;

    // consume the fuel cost
    myship->consume_fuel(get_fuelcost());
    if (myship->ran_out_fuel()) {
        return;
    }

    std::cout << "Explorative probe is diving into the atmosphere of Jupiter"
              << std::endl;

    int roll1 = rand() % (3) + 1;

    /*************************************************************************
    ** The ship encounters a strong magnetic storm (1/3 chance)
    *************************************************************************/
    if (roll1 == 1) {
        std::cout
            << "Encounter a giant storm. Lost contact with explorative probe."
            << std::endl;
        if (myship->get_crews() - 10 <= 0) {
            myship->set_crews(0);
            std::cout << "All crew are lost." << std::endl;
        } else {
            myship->set_crews(myship->get_crews() - 10);
            std::cout << "Lost 10 crews." << std::endl;
        }

        return;
    }

    /*************************************************************************
    ** Gather resource (2/3 chance) 
    *************************************************************************/
    // if anti particles are available for gathering
    if (get_antiparticles() > 0) {
        int roll2 = rand() % (5) + 5;

        std::cout << roll2 << " anti-particles are found." << std::endl;
        myship->add_antiParticles(roll2);
        set_antiparticles(get_antiparticles() - roll2);
    }

    // if fuel packss are available for gathering
    if (get_fuelpacks() > 0) {
        int roll3 = rand() % (5) + 5;

        std::cout << roll3 << " fuelpacks are found." << std::endl;
        myship->add_fuelPacks(roll3);
        set_fuelpacks(get_fuelpacks() - roll3);
    }
}
