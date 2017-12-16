/*****************************************************************************
** program name: black_hole.hpp
** author: Wu, Ziwei
** date: 2017-11-22
** description: a header file for class Blackhole. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef BLACKHOLE_HPP
#define BLACKHOLE_HPP
#include "Space.hpp"

class Blackhole : public ::Space {
   private:

   public:
    // constructors and destructor
    Blackhole();           // constructor
    virtual ~Blackhole();  // destructor

    // member functions
    void arrive(ship*) override;
    void explore(ship*) override;
};

#endif
