/*****************************************************************************
** program name: Jupyter.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: a header file for class Jupyter. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef Jupyter_hpp
#define Jupyter_hpp
#include "Space.hpp"

class Jupyter : public ::Space {
   private:

   public:
    // constructors and destructor
    Jupyter();           // constructor
    virtual ~Jupyter();  // destructor

    // member functions
    
    // using to override derived class members
    // source: https://stackoverflow.com/questions/6727087/c-virtual-function-being-hidden
    
    void arrive(ship*);
    void explore(ship*);
};

#endif
