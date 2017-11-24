/*****************************************************************************
** program name: Enceladus.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: an implementation file for class Enceladus. It inherits from the
the Space class.
*****************************************************************************/
#include "Enceladus.hpp"

/*****************************************************************************
                           Constructor
 *****************************************************************************/
Enceladus::Enceladus() {
    set_name("Enceladus");
    set_description("A satellite of Saturn");
    set_fuelcost(50);
    set_antiparticles(20);
    set_fuelpacks(20);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Enceladus::~Enceladus() {}

/*****************************************************************************
                           Arrive
******************************************************************************/
void Enceladus::arrive(ship* myship) {
    std::cout << std::endl;
    std::cout << "Frontier has arrived on Enceladus. " << std::endl;
    myship->consume_fuel(100);
    std::cout << "Bio-detector detects signs of extraterrestrial being."
              << std::endl;
}

/*****************************************************************************
                           explore
******************************************************************************/
void Enceladus::explore(ship* myship) {
    // explore
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Explorative probe has landed on the surface of "
              << get_name() <<"."<< std::endl;
    myship->consume_fuel(get_fuelcost());

    int roll1 = 0;
    roll1 = rand() % (2) + 1;

    if (roll1 == 1) {
        std::cout<<"The crews discovered streams of water shooting up.\n";
        std::cout<<"from the ground. Seems like a source of energy is  \n";
        std::cout<<"beneath of the ground. The crews decided to explore\n";
        std::cout<<"beneath. An mysterious ruin appeared underground. \n";
        std::cout<<"There are signs of another civilization here \n";
        std::cout<<"possible billions of year ago. now what's left  \n";
        std::cout<<"are the traces of some bacteria. Suddenly, an ancient \n";
        std::cout<<"writing appeared on the wall. A sign language scientist \n";
        std::cout<<"is able to translate the writing: beware of the darkness, \n";
        std::cout<<"but you must head into it. The key is the a matter of anti.\n";
        return;
    }

    // if anti-particles are available for gathering
    if (get_antiparticles() > 0) {
        int roll2 = 0;
        roll2 = rand() % (8) + 1;

        std::cout << roll2 << " anti-particles are found." << std::endl;
        myship->add_antiParticles(roll2);
        set_antiparticles(get_antiparticles() - roll2);
    }

    // if fuel packss are available for gathering
    if (get_fuelpacks() > 0) {
        int roll3 = 0;
        roll3 = rand() % (8) + 1;

        std::cout << roll3 << " fuel packs are found." << std::endl;
        myship->add_fuelPacks(roll3);
        set_fuelpacks(get_fuelpacks() - roll3);
    } 
}
