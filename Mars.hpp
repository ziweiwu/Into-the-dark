/*****************************************************************************
** program name: Mars.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: a header file for class Mars. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef MARS_HPP
#define MARS_HPP
#include "Space.hpp"

class Mars : public ::Space {
   public:
    // constructors and destructor
    Mars();           // constructor
    virtual ~Mars();  // destructor

    // member functions
    void arrive(ship*) override;
    void explore(ship*) override;
};

#endif
