/*****************************************************************************
** program name: Saturn.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: a header file for class Saturn. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef Saturn_hpp
#define Saturn_hpp
#include "Space.hpp"

class Saturn : public ::Space {
   private:

   public:
    // constructors and destructor
    Saturn();           // constructor
    virtual ~Saturn();  // destructor

    // member functions
    
    // using to override derived class members
    // source: https://stackoverflow.com/questions/6727087/c-virtual-function-being-hidden
    
    void arrive(ship*);
    void explore(ship*);
};

#endif
