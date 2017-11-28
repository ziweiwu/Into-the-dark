/*****************************************************************************
** program name: menu.cpp
** author: Wu, Ziwei
** date: 2017-10-25
** description: a implementation file for class Menu. It has a constructor
   which initialize the gameplay and a destructor. A member function fight
*****************************************************************************/
#include "menu.hpp"
#include <fstream>
#include <limits>

/*****************************************************************************
                        Constructor
*****************************************************************************/
Menu::Menu() {
    set_quitGame(false);

    // initialize the ship
    ship myship;

    // initialize the planets objects
    Mars mars1;
    Jupiter jupyter1;
    Saturn saturn1;
    Enceladus enceladus1;
    Titan titan1;
    Blackhole blackhole1;

    // links the planet objects
    mars1.set_right(&jupyter1);
    jupyter1.set_left(&mars1);

    jupyter1.set_right(&saturn1);
    saturn1.set_left(&jupyter1);

    saturn1.set_down(&enceladus1);
    enceladus1.set_up(&saturn1);

    saturn1.set_up(&titan1);
    titan1.set_down(&saturn1);

    titan1.set_up(&blackhole1);
    blackhole1.set_down(&titan1);

    start_menu();

    // if players wants to quit the game
    if (quitGame) {
        return;
    }

    // start the game
    currentLocation = &mars1;          // set current location
    currentLocation->arrive(&myship);  // arive at mars
    planet_menu(currentLocation, &myship);

    return;
}
/*****************************************************************************
                        Destructor
*****************************************************************************/
Menu::~Menu() {}

/*****************************************************************************
                        Set functions
*****************************************************************************/
void Menu::set_quitGame(bool flag) { quitGame = flag; }

/*****************************************************************************
                        get functions
*****************************************************************************/
bool Menu::get_quitGame() { return quitGame; }

/*****************************************************************************
                        start_menu
*****************************************************************************/
void Menu::start_menu() {
    int choice1 = 0;

    // Show the starting menu
    std::cout << std::endl;

    // Display an title art to the screen.
    // Source: the ascii art from http://ascii.co.uk/art/saturn//
    std::fstream artFile;
    artFile.open("title_art.txt", std::ios::in);

    std::cout << "------------------------------------------------------------"
              << std::endl;

    std::cout << "               Enter the darkness                    "
              << std::endl;

    std::cout << "-------------------------------------------------------------"
              << std::endl;
    // checks if art file can be openned
    if (artFile.is_open()) {
        // draw the art to the screen
        std::string line;
        while (getline(artFile, line)) {
            std::cout << line << std::endl;
        }
        artFile.close();
    } else {
        std::cout << "Error opening the art file. " << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "1. start game" << std::endl;
    std::cout << "2. quit" << std::endl;
    // choose first character

    do {
        std::cin >> choice1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice1 < 1 || choice1 > 2) {
            std::cout << "Invalid input. Please try again: ";
        }
    } while (choice1 < 1 || choice1 > 2);

    // if user would like quit the program
    if (choice1 == 2) {
        set_quitGame(true);
        return;
    }

    // display the background story
    std::cout << "-----------------------------------------------------------"
              << std::endl;
    std::cout << "                           Prologue                       "
              << std::endl;
    std::cout << std::endl;
    std::cout << "In 2030, the advance in technology has caused a singularity."
              << std::endl;
    std::cout << "A point of no return such that artificial intelligence has "
              << std::endl;
    std::cout << "surpassed human intelligence. Human are solely dependent on"
              << std::endl;
    std::cout
        << "AI to make decisions for them. Human distinction are approaching"
        << std::endl;
    std::cout << "as AI no longer depends on human. A group of scientist has "
              << std::endl;
    std::cout << "embarked on a journey to restore the humanity by seeking a  "
              << std::endl;
    std::cout << "a new planet in the universe. They have detected signals"
              << std::endl;
    std::cout << "of a emergying worm hole. Passage through it might be"
              << std::endl;
    std::cout << "their only hope to find a new home... " << std::endl;
    std::cout << "-----------------------------------------------------------"
              << std::endl;
    std::cout << std::endl;
    std::cout
        << "Frontier is the spaceship for the mission, it was launched just"
        << std::endl;
    std::cout << "before the AI could take control of it. This is a mission of"
              << std::endl;
    std::cout << "no return. The first destination is the red planet Mars."
              << std::endl;
}

/*****************************************************************************
 *                               planet_menu
 *****************************************************************************/
void Menu::planet_menu(Space* planet, ship* myship) {
    int choice1;
    while (myship->get_crews() > 0 && myship->get_fuel() > 0) {
        std::cout << std::endl;
        // display the map
        draw_map(planet);

        // display the ship status
        myship->display_status();

        /********************************************************************
        ** Display menu selections
        *********************************************************************/
        // basic options
        std::cout << "1. Explore " << planet->get_name()
                  << " (fuelcost: " << planet->get_fuelcost() << ")"
                  << std::endl;
        std::cout << "2. Use fuel packs." << std::endl;
        std::cout << "3. Use the particles accelerator." << std::endl;

        // options to travels
        if (planet->get_right() != nullptr) {
            std::cout << "4. Head to " << (planet->get_right())->get_name()
                      << " (fuelcost: " << (planet->get_right())->get_fuelcost()
                      << ")" << std::endl;
        } else {
            std::cout << "4. No destination available." << std::endl;
        }
        if (planet->get_left() != nullptr) {
            std::cout << "5. Head to " << (planet->get_left())->get_name()
                      << " (fuelcost: " << (planet->get_left())->get_fuelcost()
                      << ")" << std::endl;
        } else {
            std::cout << "5. No destination available." << std::endl;
        }
        if (planet->get_up() != nullptr) {
            std::cout << "6. Head to " << (planet->get_up())->get_name()
                      << " (fuelcost: " << (planet->get_up())->get_fuelcost()
                      << ")" << std::endl;
        } else {
            std::cout << "6. No destination available." << std::endl;
        }

        if (planet->get_down() != nullptr) {
            std::cout << "7. Head to " << (planet->get_down())->get_name()
                      << " (fuelcost: " << (planet->get_down())->get_fuelcost()
                      << ")" << std::endl;
        } else {
            std::cout << "7. No destination available." << std::endl;
        }
        std::cout << "8. Abort mission." << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "Enter your choice ";
            std::cin >> choice1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice1 < 1 || choice1 > 8) {
                std::cout << "Invalid input. Please try again: ";
            }
        } while (choice1 < 1 || choice1 > 8);

        // if user would like explore the planet
        if (choice1 == 1) {
            planet->explore(myship);

            // check if mission is completed;
            if (myship->get_crews() == 1000) {
                return;
            }
        }
        if (choice1 == 2) {
            myship->use_fuelPacks();
        }

        if (choice1 == 3) {
            myship->create_antiMatter();
        }

        if (choice1 == 4) {
            if (planet->get_right() != nullptr) {
                planet = planet->get_right();
                planet->arrive(myship);
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        if (choice1 == 5) {
            if (planet->get_left() != nullptr) {
                planet = planet->get_left();
                planet->arrive(myship);
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        if (choice1 == 6) {
            if (planet->get_up() != nullptr) {
                planet = planet->get_up();
                planet->arrive(myship);
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        if (choice1 == 7) {
            if (planet->get_down() != nullptr) {
                planet = planet->get_down();
                planet->arrive(myship);
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        if (choice1 == 8) {
            int choice2 = 0;
            std::cout << "Are you sure you want to give up the mission?"
                      << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;
            do {
                std::cin >> choice2;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                if (choice2 < 1 || choice2 > 2) {
                    std::cout << "Invalid input. Please try again: ";
                }
            } while (choice2 < 1 || choice2 > 2);

            if (choice2 == 1) {
                std::cout << "Mission aborted." << std::endl;
                return;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Game over. Mission failed." << std::endl;
}

/*****************************************************************************
 *                               draw_map
 *****************************************************************************/
void Menu::draw_map(Space* planet) {
    std::cout << "----------------------------------------------------------"
              << std::endl;
    std::cout << "                    Map                                    "
              << std::endl;
    std::cout << std::endl;

    // check if up has a planet
    if (planet->get_up() != nullptr) {
        std::cout << std::right << std::setw(20)
                  << (planet->get_up())->get_name() << std::endl;
        std::cout << std::right << std::setw(16) << " ^" << std::endl;
        std::cout << std::right << std::setw(16) << " |" << std::endl;
        std::cout << std::right << std::setw(16) << " |" << std::endl;
    }
    // if left has a planet
    if (planet->get_left() != nullptr) {
        std::cout << (planet->get_left())->get_name();
        std::cout << std::left << std::setw(2) << "<--- ";
    } else {
        std::cout << "            ";
    }

    std::cout << "*" << planet->get_name() << "*";

    // check if right has a planet
    if (planet->get_right() != nullptr) {
        std::cout << " --->" << (planet->get_right())->get_name() << std::endl;
    } else {
        std::cout << std::endl;
    }

    // check if down has a planet
    if (planet->get_down() != nullptr) {
        std::cout << std::right << std::setw(16) << " |" << std::endl;
        std::cout << std::right << std::setw(16) << " |" << std::endl;
        std::cout << std::right << std::setw(16) << " V" << std::endl;
        std::cout << std::right << std::setw(20)
                  << (planet->get_down())->get_name() << std::endl;
    }
    std::cout << std::endl;
}
