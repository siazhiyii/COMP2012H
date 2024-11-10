#include "coffee.h"

#include <iostream>

using namespace std;

// Coffee

/* ===================================================
    TODO: Complete the general constructor.
          Initialize the Coffee object by shallow copying the bean and milk objects.
   =================================================== */ 
Coffee::Coffee(Bean *bean, Milk *milk1, Milk *milk2)
{
    this->bean = bean;
    this->milk1 = milk1;
    this->milk2 = milk2;

    // Finish constructing with printing.
    cout << "Coffee is Constructed!" << endl;
}


/* ===================================================
    TODO: Complete the copy constructor.
          Deep copy the data members of the "other" coffee
    HINT: Usage of a Ternary operator:
          (condition) ? (value_if_true) : (value_if_false);
   =================================================== */ 
Coffee::Coffee(const Coffee &other)
{
    this->bean = (other.bean != nullptr) ? new Bean(*other.bean) : nullptr;
    this->milk1 = (other.milk1 != nullptr) ? new Milk(*other.milk1) : nullptr;
    this->milk2 = (other.milk2 != nullptr) ? new Milk(*other.milk2) : nullptr;

    // Finish constructing with printing.
    cout << "Coffee is Copied!" << endl;
}

/* ===================================================
    TODO: Complete the destructor.
          Destruct all the data members
   =================================================== */ 
Coffee::~Coffee()
{
    delete bean;
    delete milk1;
    delete milk2;
    // Finish constructing with printing.
    cout << "Coffee is Destructed." << endl;
}
