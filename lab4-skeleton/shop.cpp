#include "shop.h"

#include <iostream>
#include <iomanip>
using namespace std;

/* ===================================================
    TODO: Complete the type conversion constructor.
          Here we assume to allocate same storage of size *n_storage* for bean, Milk and coffeees.
          Try to add only one extra line of code!
    HINT: Reuse the general constuctor we define below.
   =================================================== */ 
Shop::Shop(int n_storage)
    : Shop(n_storage, n_storage, n_storage)
{
    // Finish constructing with printing.
    cout << "By using the conversion constructor!" << endl;
}


/* ===================================================
    TODO: Complete the general constructor
          numBean, numMilk, numCoffee should be initialized to be 0
          maxNumBean, maxNumMilk, maxNumCoffee should be initialized to their assigned values
   =================================================== */ 
Shop::Shop(int n_Beanes, int n_Milk, int n_Coffee)
{
    this->numBean = 0;
    this->numMilk = 0;
    this->numCoffee = 0;
    this->maxNumBean = n_Beanes;
    this->maxNumMilk = n_Milk;
    this->maxNumCoffee = n_Coffee;
    this->beanStorage = new Bean*[n_Beanes];
    this->milkStorage = new Milk*[n_Milk];
    this->coffeeStorage = new Coffee*[n_Coffee];
    // Finish constructing with printing.
    cout << "Shop is Constructed!" << endl;
}


/* ===================================================
    TODO: Complete the copy constructor
          Deep copy all data members of another shop
   =================================================== */ 
Shop::Shop(const Shop &other)
{
    this->numBean = other.numBean;
    this->numMilk = other.numMilk;
    this->numCoffee = other.numCoffee;
    this->maxNumBean = other.maxNumBean;
    this->maxNumMilk = other.maxNumMilk;
    this->maxNumCoffee = other.maxNumCoffee;
    this->beanStorage = new Bean*[maxNumBean];
    this->milkStorage = new Milk*[maxNumMilk];
    this->coffeeStorage = new Coffee*[maxNumCoffee];
    for (int i = 0; i < numBean; i++)
    {
        beanStorage[i] = new Bean(*other.beanStorage[i]);
    }
    for (int i = 0; i < numMilk; i++)
    {
        milkStorage[i] = new Milk(*other.milkStorage[i]);
    }
    for (int i = 0; i < numCoffee; i++)
    {
        coffeeStorage[i] = new Coffee(*other.coffeeStorage[i]);
    }
    // Finish copying with printing.
    cout << "Shop is Copied!" << endl;
}


/* ===================================================
    TODO: Complete the destructor
   =================================================== */ 
Shop::~Shop()
{
    for (int i = 0; i < numBean; i++)
    {
        delete beanStorage[i];
    }
    for (int i = 0; i < numMilk; i++)
    {
        delete milkStorage[i];
    }
    for (int i = 0; i < numCoffee; i++)
    {
        delete coffeeStorage[i];
    }
    delete[] beanStorage;
    delete[] milkStorage;
    delete[] coffeeStorage;
    // Finish destructing with printing.
    cout << "Shop is Destructed." << endl;
}


void Shop::storeBean()
{
    if (numBean >= maxNumBean)
    {
        cout << "Error: Bean storage is full, store failed." << endl;
    }
    else
    {
        // TODO: Store a unit of bean by allocating a Bean object.
        Bean* newBean = new Bean();
        beanStorage[numBean] = newBean;
        numBean++;
    }
}


void Shop::storeMilk()
{
    if (numMilk >= maxNumMilk)
    {
        cout << "Error: Milk storage is full, store failed." << endl;
    }
    else
    {
        // TODO: store a unit of milk by allocating a Milk object.
        Milk* newMilk = new Milk();
        milkStorage[numMilk] = newMilk;
        numMilk++;
    }
}


void Shop::cookCoffee()
{
    if (numCoffee >= maxNumCoffee)
    {
        cout << "Error: Coffee storage is full, cook failed." << endl;
    }
    else if (numMilk < 2 || numBean < 1)
    {
        cout << "Error: Not enough ingredient for cooking a Coffee" << endl;
    }
    else
    {
        /* ===================================================
            TODO: Cook a unit of coffee by using bean and milk objects.
            Since the production of latte requires both bean and Milk,
            it will consume one unit of bean and two unit of milk at the top of both storages for each coffee.
            The ownership of the top bean and top two milk is then transferred to the coffee object,
            which means the Bean object and the Milk object are now pointed by the new Coffee object instead.
           =================================================== */ 
        Coffee* newCoffee = new Coffee(beanStorage[numBean - 1], milkStorage[numMilk - 1], milkStorage[numMilk - 2]);
        numBean--;
        numMilk -= 2;
        coffeeStorage[numCoffee] = newCoffee;
        numCoffee++;
    }
}

void Shop::serveCoffee()
{
	// TODO: Serve all Coffee by deleting each of them in the coffeeStorage
    for (int i = 0; i < numCoffee; i++)
    {
        delete coffeeStorage[i];
    }
    numCoffee = 0;
}


void Shop::print() const
{
    cout << "----------------------" << endl;
    cout << "|    Shop Summary    |" << endl;
    cout << "----------------------" << endl;
    cout << "|" << setw(8) << "Bean"   << setw(7) << "(" << numBean   << "/" << maxNumBean   << ") |" << endl;
    cout << "|" << setw(8) << "Milk" << setw(7) << "(" << numMilk << "/" << maxNumMilk << ") |" << endl;
    cout << "|" << setw(8) << "Coffee"   << setw(7) << "(" << numCoffee   << "/" << maxNumCoffee   << ") |" << endl;
    cout << "----------------------" << endl;
}
