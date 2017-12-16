/*****************************************************************************
** program name: Jupiter.hpp
** author: Wu, Ziwei
** date: 2017-11-25
** description: a header file for class Jupiter. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef JUPITER_HPP
#define JUPITER_HPP
#include "Space.hpp"

class Jupiter : public ::Space {
   private:

   public:
    // constructors and destructor
    Jupiter();           // constructor
    virtual ~Jupiter();  // destructor

    // member functions
    void arrive(ship*) override;
    void explore(ship*) override;
};

#endif
