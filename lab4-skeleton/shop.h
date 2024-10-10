#ifndef SHOP_H
#define SHOP_H

#include "ingredient.h"
#include "coffee.h"

class Shop
{
public:
  Shop(int n_storage);                                // TODO: Type conversion constructor
  Shop(int n_Bean, int n_Milkes, int n_Coffeees);     // TODO: General constructor.
  Shop(const Shop &other);                            // TODO: Copy constructor.
  ~Shop();                                            // TODO: Destructor.

  void storeBean();     // TODO: Store a new unit of coffee bean by allocating a Bean object.
  void storeMilk();     // TODO: Store a new unit of milk by allocating a Milk object.
  void cookCoffee();    // TODO: Cook a new unit of coffee by allocating a Coffee object,
                        // Since the production of latte requires both coffee bean and milkes,
                        // it will consume one unit of coffee bean and two unit of milk at the top of both storages for each latte.
                        // The ownership of the top bean and top two milk is then transferred to the dish object,
                        // which means the Bean object and the Milk object are now pointed by the new Coffee object instead.
  
  void serveCoffee();   // TODO: Serve all coffee in storage by deleting each of the Coffee objects in dishStorage

  void print() const;   // print the Shop summary

private:
  Bean **beanStorage;
  Milk **milkStorage;
  Coffee **coffeeStorage;

  int numBean;          // Current number of bean.
  int numMilk;          // Current number of milk.
  int numCoffee;        // Current number of coffee.

  int maxNumBean;       // Maximum number of bean.
  int maxNumMilk;       // Maximum number of milk.
  int maxNumCoffee;     // Maximum number of coffee.
};

#endif
