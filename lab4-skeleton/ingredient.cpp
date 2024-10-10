#include "ingredient.h"

#include <iostream>

using namespace std;

// Bean

Bean::Bean()
{
    cout << "Bean is Constructed!" << endl;
}

Bean::Bean(const Bean &other)
{
    cout << "Bean is Copied!" << endl;
}

Bean::~Bean()
{
    cout << "Bean is Destructed." << endl;
}

// Milk

Milk::Milk()
{
    cout << "Milk is Constructed!" << endl;
}

Milk::Milk(const Milk &other)
{
    cout << "Milk is Copied!" << endl;
}

Milk::~Milk()
{
    cout << "Milk is Destructed." << endl;
}
