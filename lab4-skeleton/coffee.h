#ifndef COFFEE_H
#define COFFEE_H 

#include "ingredient.h"

class Coffee
{
public:
  Coffee(Bean *bean, Milk *milk1, Milk *milk2);     // TODO: General constructor, shallow copy the bean and milk objects.
  Coffee(const Coffee &other);            // TODO: Copy constructor, deep copy the bean and milk objects.
  ~Coffee();                              // TODO: Destructor.

private:
  Bean *bean;
  Milk *milk1;
  Milk *milk2;
};

#endif
