/*****************************************************************************
** program name: Enceladus.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: a header file for class Enceladus. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef Enceladus_hpp
#define Enceladus_hpp
#include "Space.hpp"

class Enceladus : public ::Space {
   private:

   public:
    // constructors and destructor
    Enceladus();           // constructor
    virtual ~Enceladus();  // destructor

    // member functions
    void arrive(ship*);
    void explore(ship*);
};

#endif
