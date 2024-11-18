/**
 * @file order_item.cpp
 * @brief Definitions of member and helper functions for OrderItem and derived classes.
 *
 * This file defines member functions of OrderItem, Food, Burger, Fries, Combo, and
 * corresponding helper factory functions for ordering them.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "order_item.h"

/**
 * Prepare this item.
 */
void OrderItem::prepare()
{
	std::cout << "Preparing " << get_name() << "..." << std::endl;
}

/**
 * Protected function for derived classes to modify name.
 */
void Food::set_name(std::string name)
{
	this->name = name;
}

/**
 * Override get_name to return name field.
 */
std::string Food::get_name() const
{
	return this->name;
}

/**
 * Override get_price to return price field.
 */
int Food::get_price() const
{
	return this->price;
}

/**
 * Constructor of Burger.
 * TODO:
 *   Set name and price of the inherited Food class.
 */
//=========== TODO ===================================================
Burger::Burger(std::string name, int price, std::string modifier) : Food(name, price), modifier(modifier)
{
	if (!modifier.empty())
	{
		set_name(name + " (" + modifier + ")");
	}
}

//--------------------------------------------------------------------

/**
 * Factory function for a burger order.
 * TODO:
 *   Create a instance and return its address of burger order based on selection.
 *   A Beef Burger has name "Beef Burger" and price is 21.
 *   A Chicken Burger has name "Chicken Burger" and price is 24.
 *   If None is selected, or selection is not in range, return nullptr.
 *   Otherwise, a second selection is prompted for additional request, which is put into modifier.
 */
Burger *Burger::order_burger()
{
	std::cout << "================ Burger =================" << std::endl;
	const std::vector<std::string> options = {
		"Beef Burger",
		"Chicken Burger",
		"None",
	};

	for (int i = 0; i < options.size(); i++)
	{
		std::cout << std::setw(3) << i + 1 << ". " << options[i] << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Please input the index of your selection: ";
	int index;
	std::cin >> index;
	std::cout << std::endl;

	std::string modifier = "";
	if (index >= 1 && index < options.size())
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Any special request for your burger? If not, type 'None': ";
		std::getline(std::cin, modifier); // This is intentional due to leftover '\n'
		std::getline(std::cin, modifier);
		if (modifier == "None")
			modifier = "";
		std::cout << std::endl;
	}

	//=========== TODO ===================================================

	if (index == 1)
	{
		return new Burger("Beef Burger", 21, modifier);
	}
	else if (index == 2)
	{
		return new Burger("Chicken Burger", 24, modifier);
	}
	else
	{
		return nullptr;
	}

	//--------------------------------------------------------------------
}

/**
 * Constructor of Fries.
 * TODO:
 *   Set name and price of the inherited Food class.
 *   If the size is Small, modify name to add " (Small)" after the name.
 * 	 If the size is Large, modify name to add " (Large)" after the name.
 */
//=========== TODO ===================================================
Fries::Fries(std::string name, int price, FriesSize size) : Food(name, price), size(size)
{
	if (size == FriesSize::Small)
	{
		set_name(name + " (Small)");
	}
	else if (size == FriesSize::Large)
	{
		set_name(name + " (Large)");
	}
}

//--------------------------------------------------------------------

/**
 * Override get_price to return price field of a fries order.
 * TODO:
 *   If the size is Small, the price should be decreased by 3.
 * 	 If the size is Large, the price should be increased by 5.
 */
//=========== TODO ===================================================

int Fries::get_price() const
{
	int price = Food::get_price();
	if (size == FriesSize::Small)
	{
		price -= 3;
	}
	else if (size == FriesSize::Large)
	{
		price += 5;
	}
	return price;
}

//--------------------------------------------------------------------

/**
 * Factory function for a fries order.
 * TODO:
 *   Create a instance and return its address of fries order based on selection.
 * 	 Regular Fries has name "Regular Fries" and price is 10.
 *   Twisted Fries has name "Twisted Fries" and price is 15.
 *   If None is selected, or selection is not in range, return nullptr.
 *   Otherwise, a second selection is prompted to choose size. sizeIndex contains the selection.
 */
Fries *Fries::order_fries()
{
	std::cout << "================= Fries =================" << std::endl;
	const std::vector<std::string> options = {
		"Regular Fries",
		"Twisted Fries",
		"None",
	};

	for (int i = 0; i < options.size(); i++)
	{
		std::cout << std::setw(3) << i + 1 << ". " << options[i] << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Please input the index of your selection: ";
	int index;
	std::cin >> index;
	std::cout << std::endl;

	int sizeIndex = 2;
	if (index >= 1 && index < options.size())
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Select the size of your fries: " << std::endl;

		const std::vector<std::string> options = {
			"Small",
			"Regular",
			"Large",
		};

		for (int i = 0; i < options.size(); i++)
		{
			std::cout << std::setw(3) << i + 1 << ". " << options[i] << std::endl;
		}

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Please input the index of your selection: ";
		std::cin >> sizeIndex;
		if (sizeIndex < 1 || sizeIndex > 3)
			sizeIndex = 2;
		std::cout << std::endl;
	}

	//=========== TODO ===================================================

	if (index == 1)
	{
		return new Fries("Regular Fries", 10, (FriesSize)sizeIndex);
	}
	else if (index == 2)
	{
		return new Fries("Twisted Fries", 15, (FriesSize)sizeIndex);
	}
	else
	{
		return nullptr;
	}

	//--------------------------------------------------------------------
}

/**
 * Constructor of Drink.
 * TODO:
 *   Set name and price of the inherited Food class.
 *   If the drink is iced, add "Iced " to the beginning of name.
 */
//=========== TODO ===================================================
Drink::Drink(std::string name, int price, bool iced) : Food(name, price), iced(iced)
{
	if (iced)
	{
		set_name("Iced " + name);
	}
}

//--------------------------------------------------------------------

/**
 * Override get_price to return price field of a drink order.
 * TODO:
 *   If the drink is iced, the price should be increased by 4.
 */
//=========== TODO ===================================================
int Drink::get_price() const
{
	int price = Food::get_price();
	if (iced)
	{
		price += 4;
	}
	return price;
}

//--------------------------------------------------------------------

/**
 * Factory function for a drink order.
 * TODO:
 *   Create a instance and return its address of drink order based on selection.
 *   Coca-Cola has name "Coca-Cola" and price is 5.
 *   Cappuccino has name "Cappuccino" and price is 13.
 *   If None is selected, or selection is not in range, return nullptr.
 *   Otherwise, a second selection is prompted to choose whether the drink is iced.
 *   It is put into the boolean iced.
 */
Drink *Drink::order_drink()
{
	std::cout << "================= Drink =================" << std::endl;
	const std::vector<std::string> options = {
		"Coca-Cola",
		"Cappuccino",
		"None",
	};

	for (int i = 0; i < options.size(); i++)
	{
		std::cout << std::setw(3) << i + 1 << ". " << options[i] << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Please input the index of your selection: ";
	int index;
	std::cin >> index;
	std::cout << std::endl;

	bool iced = false;
	if (index >= 1 && index < options.size())
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Would you like your drink iced? " << std::endl;

		const std::vector<std::string> options = {
			"Yes",
			"No",
		};

		for (int i = 0; i < options.size(); i++)
		{
			std::cout << std::setw(3) << i + 1 << ". " << options[i] << std::endl;
		}

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Please input the index of your selection: ";
		int icedIndex;
		std::cin >> icedIndex;
		iced = (icedIndex == 1);
		std::cout << std::endl;
	}

	//=========== TODO ===================================================

	if (index == 1)
	{
		return new Drink("Coca-Cola", 5, iced);
	}
	else if (index == 2)
	{
		return new Drink("Cappuccino", 13, iced);
	}
	else
	{
		return nullptr;
	}

	//--------------------------------------------------------------------
}

/**
 * Member functions for the Combo class.
 */
//=========== TODO ===================================================

Combo::Combo(Burger *burger, Fries *fries, Drink *drink) : burger(burger), fries(fries), drink(drink) {}

Combo::~Combo()
{
	delete burger;
	delete fries;
	delete drink;
}

std::string Combo::get_name() const
{
	std::string name = "Combo ";
	if (burger != nullptr)
	{
		name += burger->get_name();
	}
	if (fries != nullptr)
	{
		if (burger != nullptr)
		{
			name += " & ";
		}
		name += fries->get_name();
	}
	if (drink != nullptr)
	{
		if (burger != nullptr || fries != nullptr)
		{
			name += " & ";
		}
		name += drink->get_name();
	}
	return name;
}

int Combo::get_price() const
{
	int price = 0;
	if (burger != nullptr)
	{
		price += burger->get_price();
	}
	if (fries != nullptr)
	{
		price += fries->get_price();
	}
	if (drink != nullptr)
	{
		price += drink->get_price();
	}

	price = price - (int)(0.1 * price);
	return price;
}

//--------------------------------------------------------------------

/**
 * Factory function for a combo order.
 * TODO:
 *   If at least than 2 items are selected, return a new Combo instance with the selected items.
 *   (otherwise, someone could order a single item and get a discount!)
 */
Combo *Combo::order_combo()
{
	std::cout << "Ordering a combo..." << std::endl;
	std::cout << "Select a burger" << std::endl;
	Burger *burger = Burger::order_burger();

	std::cout << "Select fries" << std::endl;
	Fries *fries = Fries::order_fries();

	std::cout << "Select a drink" << std::endl;
	Drink *drink = Drink::order_drink();

	//=========== TODO ===================================================

	if (burger != nullptr && (fries != nullptr || drink != nullptr) || (fries != nullptr && drink != nullptr))
	{
		return new Combo(burger, fries, drink);
	}
	//--------------------------------------------------------------------

	std::cout << "Insufficient number of items. Order cancelled." << std::endl;
	delete burger;
	delete fries;
	delete drink;
	return nullptr;
}

/**
 * Factory function for an order item.
 *   Create an order item and return its address based on selection,
 *   by calling corresponding factory function.
 *   Make sure if no order is made in sub-factory function, go back to
 *   selection part.
 *   If None is selected, or selection is not in range, return nullptr.
 */
OrderItem *OrderItem::order_item()
{
	std::cout << "================= Menu ==================" << std::endl;
	const std::vector<std::string> options = {
		"Combo",
		"Burger",
		"Fries",
		"Drink",
		"None",
	};

	for (int i = 0; i < options.size(); i++)
	{
		std::cout << std::setw(3) << i + 1 << ". " << options[i] << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Please input the index of your selection: ";
	int index;
	std::cin >> index;
	std::cout << std::endl;

	OrderItem *item;
	switch (index)
	{
	case 1:
		item = Combo::order_combo();
		break;
	case 2:
		item = Burger::order_burger();
		break;
	case 3:
		item = Fries::order_fries();
		break;
	case 4:
		item = Drink::order_drink();
		break;
	default:
		return nullptr;
	}
	if (item == nullptr)
	{
		return OrderItem::order_item();
	}
	return item;
}
