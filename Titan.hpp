/*****************************************************************************
** program name: Titan.hpp
** author: Wu, Ziwei
** date: 2017-11-22
** description: a header file for class Titan. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef TITAN_HPP
#define TITAN_HPP
#include "Space.hpp"

class Titan : public ::Space {
   public:
    // constructors and destructor
    Titan();           // constructor
    virtual ~Titan();  // destructor

    // member functions
    void arrive(ship*) override;
    void explore(ship*) override;
};

#endif
