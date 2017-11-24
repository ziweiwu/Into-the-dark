/*****************************************************************************
** program name: Mars.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: a header file for class Mars. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef Mars_hpp
#define Mars_hpp
#include "Space.hpp"

class Mars : public ::Space {
   private:

   public:
    // constructors and destructor
    Mars();           // constructor
    virtual ~Mars();  // destructor

    // member functions
    void arrive(ship*);
    void explore(ship*);
};

#endif
