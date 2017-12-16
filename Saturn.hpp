/*****************************************************************************
** program name: Saturn.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: a header file for class Saturn. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef SATURN_HPP
#define SATURN_HPP
#include "Space.hpp"

class Saturn : public ::Space {
   private:

   public:
    // constructors and destructor
    Saturn();           // constructor
    virtual ~Saturn();  // destructor

    // member functions
    void arrive(ship*) override;
    void explore(ship*) override;
};

#endif
