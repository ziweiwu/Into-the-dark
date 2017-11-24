/*****************************************************************************
** program name: black_hole.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: a header file for class Blackhole. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef Blackhole_hpp
#define Blackhole_hpp
#include "Space.hpp"

class Blackhole : public ::Space {
   private:

   public:
    // constructors and destructor
    Blackhole();           // constructor
    virtual ~Blackhole();  // destructor

    // member functions
    
    // using to override derived class members
    // source: https://stackoverflow.com/questions/6727087/c-virtual-function-being-hidden
    
    void arrive(ship*);
    void explore(ship*);
};

#endif
