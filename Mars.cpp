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
    set_fuelcost(100);
    set_antiparticles(20);
    set_fuelpacks(20);
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
    
    if(myship->ran_out_fuel()){return;}
    
    std::cout << std::endl;
    std::cout << "Frontier has arrived to Mars. " << std::endl;
    myship->consume_fuel(100);
    std::cout << "Bio-detector detects signs of extraterrestrial being."
              << std::endl;
}

/*****************************************************************************
                           explore
******************************************************************************/
void Mars::explore(ship* myship) {
    // explore
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Explorative probe is heading to the surface of "
              << get_name() << std::endl;
    myship->consume_fuel(get_fuelcost());

    if (myship->ran_out_fuel()) {
        return;
    }
    
    std::cout << "Explorative probe has landed on "
              << get_name() << std::endl;
    myship->consume_fuel(get_fuelcost());
    
    int roll1 = 0;
    roll1 = rand() % (3) + 1;

    // meet the prophet
    if (roll1 == 1) {
        std::cout << "Probe is searching for the origin of life signal...\n";
        std::cout << "Crew encounters a unknown being. A female humanoid like "
                     "being addressed in white robe.\n";
        std::cout << "With fair hair and skin. Her beauty stunned the crew.\n";
        std::cout << "She speaks in a strange language. But mysteriously the crews can understand the language.\n";
        std::cout
            << "My name is Aria. I am from a planet from another universe.\n";
        std::cout << "I am travel from 10 bllion light year afar. I am here to "
                     "guide you people.\n";
        std::cout
            << "Only way for humanity to survive to dive into the darkness..."
            << std::endl;
        return;
    }

    // meet the predator
    if (roll1 == 2) {
        std::cout << "Probe is searching for the origin of life signal...\n";
        std::cout << "Crew encounters a unknown being. A gigantic creature emerged from the ground.\n";
        std::cout << "The crew draw their weapons.\n";
        std::cout<<"Before they fire at it, the creature leaped into the sky.\n";
        std::cout << "Lost contact with the crews..." << std::endl;
        myship->set_crews(myship->get_crews() - 10);

        return;
    }

        std::cout << "Probe is searching for the origin of life signal...\n";
        std::cout << "The crews could not find any life form."<<std::endl;

    // if anti particles are available for gathering
    if (get_antiparticles() > 0) {
        int roll2 = 0;
        roll2 = rand() % (5) + 1;

        std::cout << roll2 << " anti-particles are found." << std::endl;
        myship->add_antiParticles(roll2);
        set_antiparticles(get_antiparticles() - roll2);
    }

    // if fuel packss are available for gathering
    if (get_fuelpacks() > 0) {
        int roll3 = 0;
        roll3 = rand() % (5) + 1;

        std::cout << roll3 << " fuelpacks are found." << std::endl;
        myship->add_fuelPacks(roll3);
        set_fuelpacks(get_fuelpacks() - roll3);
    }


}
