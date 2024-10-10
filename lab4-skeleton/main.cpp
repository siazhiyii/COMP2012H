#include <iostream>

#include "shop.h"

using namespace std;

int main()
{
    cout << "1. Open the Shop!" << endl;
    Shop shop(5);
    shop.print();
    cout << endl;

    cout << "2. Try to store too many coffee beans, leading to a store failure." << endl;
    shop.storeBean();
    shop.storeBean();
    shop.storeBean();
    shop.storeBean();
    shop.storeBean();
    shop.storeBean();
    shop.print();
    cout << endl;

    cout << "3. Try to make a latte with 5 units of coffee beans without any milk, failed." << endl;
    shop.cookCoffee();
    shop.print();
    cout << endl;

    cout << "4. Make a latte with 1 unit of coffee beans and 2 units of milk, succeed." << endl;
    shop.storeMilk();
    shop.storeMilk();
    shop.print();
    shop.cookCoffee();
    shop.print();
    cout << endl;

    cout << "5. Peak hours! Clone the shop." << endl;
    {
        Shop clonedshop = shop;
        clonedshop.print();
        cout << endl;

        cout << "6. Make a latte in the cloned shop." << endl;
        clonedshop.storeMilk();
        clonedshop.storeMilk();
        clonedshop.print();
        clonedshop.cookCoffee();
        clonedshop.print();
        cout << endl;

        cout << "7. End of peak hours! Destroy the cloned shop." << endl;
    } // "clonedshop" is destructed once the program runs out of this scope.
    cout << endl;

    cout << "8. Serve all the stored lattes." << endl;
    cout << "(State of the original shop)" << endl;
    shop.print();
    shop.serveCoffee();
    shop.print();
    cout << endl;

    cout << "9. End of the day! Close the shop." << endl;
    cout << "(State of the shop just before destruction)" << endl;
    shop.print();

    return 0;
} // "shop" is destructed once the program runs out of this scope.