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
    set_antiparticles(30);
    set_fuelpacks(30);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Enceladus::~Enceladus() {}

/*****************************************************************************
                           Arrive
******************************************************************************/
void Enceladus::arrive(ship* myship) {
    myship->consume_fuel(get_fuelcost());

    if (myship->ran_out_fuel()) {
        return;
    }

    std::cout << "-----------------------------------------------------------"
              << std::endl;
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
    std::cout << "Explorative probe is heading toward " << get_name() << "."
              << std::endl;
    myship->consume_fuel(get_fuelcost());

    if (myship->ran_out_fuel()) {
        return;
    }

    std::cout << "Explorative probe has landed on the surface of " << get_name()
              << "." << std::endl;

    int roll1 = 0;
    roll1 = rand() % (2) + 1;

    if (roll1 == 1) {
        std::cout << "The crews discovered streams of water shooting up\n";
        std::cout << "from the ground. Seems like the source of energy is  \n";
        std::cout << "beneath of the ground. \n";

        int choice;
        std::cout << "Do you like to explore the underground? " << std::endl;
        std::cout << "1. Yes " << std::endl;
        std::cout << "2. NO " << std::endl;

        do {
            std::cout << "enter your choice: ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice != 1 && choice != 2) {
                std::cout << "invalid input. please try again: ";
            }
        } while (choice != 1 && choice != 2);
        if (choice == 1) {
            std::cout << "An mysterious ruin appeared. \n";
            std::cout << "There are signs of another civilization here \n";
            std::cout
                << "possible billions of year ago. But now what's left  \n";
            std::cout << "are just traces of bacteria. Suddenly, an ancient \n";
            std::cout
                << "writing appeared on the wall. A sign language scientist \n";
            std::cout << "is able to translate the writing: \n";
            std::cout << std::endl;
            std::cout << "Beware of the darkness. \n";
            std::cout
                << "If you shall head into it.The key is the matter of Anti.\n";
        }
    }

    // if anti-particles are available for gathering
    if (get_antiparticles() > 0) {
        int roll2 = 0;
        roll2 = rand() % (10) + 2;

        std::cout << roll2 << " anti-particles are found." << std::endl;
        myship->add_antiParticles(roll2);
        set_antiparticles(get_antiparticles() - roll2);
    }

    // if fuel packss are available for gathering
    if (get_fuelpacks() > 0) {
        int roll3 = 0;
        roll3 = rand() % (10) + 2;

        std::cout << roll3 << " fuel packs are found." << std::endl;
        myship->add_fuelPacks(roll3);
        set_fuelpacks(get_fuelpacks() - roll3);
    }
}
