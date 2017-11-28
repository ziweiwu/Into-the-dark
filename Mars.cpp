/*****************************************************************************
** program name: Mars.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: an implementation file for class Mars. It inherits from the
the Space class.
*****************************************************************************/
#include "Mars.hpp"

/*****************************************************************************
                           Constructor
 *****************************************************************************/
Mars::Mars() {
    set_name("Mars");
    set_description("The red planet");
    set_fuelcost(80);
    set_antiparticles(35);
    set_fuelpacks(35);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Mars::~Mars() {}

/*****************************************************************************
                           Arrive
******************************************************************************/
void Mars::arrive(ship* myship) {
    myship->consume_fuel(get_fuelcost());
    if (myship->ran_out_fuel()) {
        return;
    }

    std::cout << "-----------------------------------------------------------"
              << std::endl;
    std::cout << "Frontier has arrived to Mars. " << std::endl;
    myship->consume_fuel(100);
    std::cout << "Bio-detector detects signs of extraterrestrial being."
              << std::endl;
}

/*****************************************************************************
                           explore
******************************************************************************/
void Mars::explore(ship* myship) {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Explorative probe is heading to the surface of " << get_name()
              << std::endl;
    myship->consume_fuel(get_fuelcost());

    // check if fuel is ran out.
    if (myship->ran_out_fuel()) {
        return;
    }
    std::cout << "Explorative probe has landed on " << get_name() << std::endl;

    // asks player if he/she wants to investigate the life signal
    int choice;
    std::cout << "Would you like to investigate the source of life signal? "
              << std::endl;
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

    /**********************************************************************
    ** Player is curious and would like to investigate
    ***********************************************************************/
    if (choice == 1) {
        int roll1 = 0;
        roll1 = rand() % (2) + 1;

        /**********************************************************************
        ** Meet the prophet (1/2 chance)
        ***********************************************************************/
        if (roll1 == 1) {
            std::cout
                << "Probe has reached the origin of life signal.\n";
            std::cout
                << "Crew encounters a unknown being. A female humanoid like "
                   "being addressed in white robe.\n";
            std::cout
                << "With fair hair and skin. Her beauty stunned the crew.\n";
            std::cout
                << "She speaks in a strange language. But mysteriously the "
                   "crews can understand the language.\n";
            std::cout << "My name is Aria. I am from a planet from another "
                         "universe that's very similiar the planet of yours.\n";
            std::cout
                << "I traveled from 10 bllion light year afar. I am here to "
                   "guide you people.\n";
            std::cout << "Only way for humanity to survive to dive into the "
                         "darkness..."
                      << std::endl;
            return;
        }

        /**********************************************************************
        ** Meet the predator (1/2 chance)
        ***********************************************************************/
        if (roll1 == 2) {
            std::cout
                << "Probe has reached the origin of life signal.\n";
            std::cout << "Crew encounters a unknown being. A gigantic creature "
                         "emerged from the ground.\n";
            std::cout << "The crew draw their weapons.\n";
            std::cout
                << "Before they could fire at it, the creature leaped toward "
                   "the crew.\n";
            std::cout << "Lost contact with the crews..." << std::endl;
            std::cout << "Lost 10 crews" << std::endl;

            if (myship->get_crews() - 10 <= 0) {
                myship->set_crews(0);
                std::cout << "All crew are lost." << std::endl;
            } else {
                myship->set_crews(myship->get_crews() - 10);
            }

            return;
        }
    }
    /**********************************************************************
    ** Player will gather resource instead
    ***********************************************************************/
    std::cout << "Probe is searching for the origin of life signal...\n";
    std::cout << "Probe is searching for the origin of life signal...\n";
    std::cout << "The crews could not find any life form." << std::endl;

    // if anti particles are available for gathering
    if (get_antiparticles() > 0) {
        int roll2 = 0;
        roll2 = rand() % (10) + 1;

        std::cout << roll2 << " anti-particles are found." << std::endl;
        myship->add_antiParticles(roll2);
        set_antiparticles(get_antiparticles() - roll2);
    }

    // if fuel packs are available for gathering
    if (get_fuelpacks() > 0) {
        int roll3 = 0;
        roll3 = rand() % (10) + 1;

        std::cout << roll3 << " fuelpacks are found." << std::endl;
        myship->add_fuelPacks(roll3);
        set_fuelpacks(get_fuelpacks() - roll3);
    }
}
