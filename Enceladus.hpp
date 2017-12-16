/*****************************************************************************
** program name: Enceladus.hpp
** author: Wu, Ziwei
** date: 2017-11-22
** description: a header file for class Enceladus. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef ENCELADUS_HPP
#define ENCELADUS_HPP
#include "Space.hpp"

class Enceladus : public ::Space {
   private:

   public:
    // constructors and destructor
    Enceladus();           // constructor
    virtual ~Enceladus();  // destructor

    // member functions
    void arrive(ship*) override;
    void explore(ship*) override;
};

#endif
