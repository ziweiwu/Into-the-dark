/*****************************************************************************
** program name: black_hole.cpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: an implementation file for class Blackhole. It inherits from the
the Space class.
*****************************************************************************/
#include "black_hole.hpp"

    /*****************************************************************************
                               Constructor
     *****************************************************************************/
    Blackhole::Blackhole() {
    set_name("Black hole");
    set_description("This is a black hole");
    set_fuelcost(0);
    set_antiparticles(0);
    set_fuelpacks(0);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Blackhole::~Blackhole() {}

/*****************************************************************************
                           Arrive
******************************************************************************/
void Blackhole::arrive(ship* myship) {
    std::cout << "----------------------------------------------------------"
              << std::endl;
    std::cout << "Frontier is approaching blackhole. " << std::endl;
    std::cout << "Detects an enormous gravitional wave. " << std::endl;
    std::cout << "Detects an enormous level of X-rays and Gamma rays." << std::endl;
    if (myship->get_antiMatter_created()) {
        std::cout<<"Anti-matter is ready to be ejected by the particle accelerator."
            <<std::endl;
    }

    // The connection between blackhole and Titan is lost
    // once the player arrives due to strong gravity pull
    get_down()->set_up(nullptr);
    set_down(nullptr);
}

/*****************************************************************************
                           explore
******************************************************************************/
void Blackhole::explore(ship* myship) {
    int choice = 0;

    if (myship->get_antiMatter_created()) {
        std::cout << "Do you want to eject the anti-matter toward the black hole?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        do {
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice < 1 || choice > 2) {
                std::cout << "Invalid input. Please try again: ";
            }
        } while (choice < 1 || choice > 2);

        if (choice == 1) {
            std::cout << "The ship is wrapped inside the anti-matter "
                      << std::endl;
            std::cout << "Time and space are twisted outside of ship. Suddenly "
                      << std::endl;
            std::cout << "You don't know how long the time has passed. "
                      << std::endl;
            std::cout << "the darkness becomes the shinning light..."
                      << std::endl;
            std::cout << "You lost consciousness...You don't know how long has "
                         "passed "
                      << std::endl;
            std::cout << "'Captain, Look!', you hear someone is shouting. You "
                         "openned your eyes. "
                      << std::endl;
            std::cout << "Outside the cabinate window, you see patches of "
                         "white clouds and blue sky."
                      << std::endl;
            std::cout << "You started to wonder if it all was just a dream..."
                      << std::endl;

            std::cout << std::endl;
            std::cout << "Congratulations. You have completed the mission."
                      << std::endl;
            // mission is completed, the ship went through black hole
            // turned out it's also a worm hole to another universe
            myship->set_crews(1000);
        }
        return;
    }
    std::cout << "Time and space are twisted outside and inside of the ship."
              << std::endl;
    std::cout << "The ship is engulfed by the darkness." << std::endl;
    // black hole destroyed the ship;
    myship->set_crews(0);
}
