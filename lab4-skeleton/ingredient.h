#ifndef INGREDIENT_H
#define INGREDIENT_H

class Bean
{
public:
  Bean();                       // Default constructor.
  Bean(const Bean &other);      // Copy constructor.
  ~Bean();                      // Destructor.
};

class Milk
{
public:
  Milk();                     // Default constructor.
  Milk(const Milk &other);  // Copy constructor.
  ~Milk();                    // Destructor.
};

#endif
