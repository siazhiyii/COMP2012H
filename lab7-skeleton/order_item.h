/**
 * @file order_item.h
 * @brief The abstract OrderItem class and derived classes.
 *
 * This file declares and defines a OrderItem class and its derived classes including:
 *   1. Food class - abstract class for a food order. There are two derived classes of it for now:
 *       1. Burger class - class for an order of burger.
 *       2. Fries class - class for an order of fries.
 *   2. Combo class - class for a order of a combo set made of an order of burger and an order of fries.
 */

#ifndef __ORDER_ITEM_H__
#define __ORDER_ITEM_H__
#include <iostream>
#include <iomanip>
#include <string>

//======================================//
//				OrderItem				//
//======================================//

/**
 * The Abstract class OrderItem for general order items including a single food or a combo set.
 * It supports getting name and price, and preparing.
 */
class OrderItem {
	public:
		//The default virtual destructor.
		virtual ~OrderItem() = default;

		//Return the name for this item.
		//To be overridden.
		virtual std::string get_name() const = 0;

		//Return the price for this item.
		//To be overridden.
		virtual int get_price() const = 0;

		//Prepare this item.
		void prepare();

		/**
		 * A factory function for making a concrete order item.
		 * Return nullptr if cancelled.
		 */
		static OrderItem* order_item();
};


//======================================//
//				   Food	    			//
//======================================//

/**
 * The Abstract Food class for general food orders including burgers and fries.
 * It inherits the OrderItem class.
 * It keeps the name and price directly as they are known on creation.
 */
class Food: public OrderItem {
	//CANNOT be accessed by derived classes.
	private:
		std::string name;
		int price = 0;

	//CAN be accessed by derived classes.
	protected:
		void set_name(std::string name);

	public:
		//Constructor
		Food(std::string name, int price): name(name), price(price) {}

		//Override get_name to return name field.
		virtual std::string get_name() const override;

		//Override get_price to return price field.
		virtual int get_price() const override;
};


//======================================//
//				  Burger				//
//======================================//

/**
 * The Burger class for burger orders.
 * It inherits the Food class.
 */
class Burger: public Food {
	private:
		std::string modifier;

	public:
		//Constructor, create a burger order.
		Burger(std::string name, int price, std::string modifier = "");

		/**
		 * A factory function for making an order of burger.
		 * Return nullptr if cancelled.
		 */
		static Burger* order_burger();
};




//======================================//
//				   Fries				//
//======================================//

//Supported fries size.
enum class FriesSize {
	Small = 1, //Small size.
	Regular, //Regular size.
	Large, //Enlarged size.
};

/**
 * The Fries class for fries orders.
 * It inherits the Food class.
 * It keeps the size for this order of fries.
 */
class Fries: public Food {
	private:
		//size
		FriesSize size;

	public:
		//Constructor, create a fries order with size.
		Fries(std::string name, int price, FriesSize size = FriesSize::Regular);

		//Override get_price for custom drink price.
		virtual int get_price() const override final;

		/**
		 * A factory function for making an order of fries.
		 * Return nullptr if cancelled.
		 */
		static Fries* order_fries();
};




//======================================//
//				   Drink				//
//======================================//

/**
 * The Drink class for drink orders.
 * It inherits the Food class.
 * It keeps the type for this order of drink.
 * The drink can either be hot or iced.
 */
class Drink: public Food {
	private:
		//iced
		bool iced;

	public:
		//Constructor, create a hot or iced drink order with type.
		Drink(std::string name, int price, bool iced = false);

		//Override get_price for custom drink price.
		virtual int get_price() const override final;

		/**
		 * A factory function for making an order of drink.
		 * Return nullptr if cancelled.
		 */
		static Drink* order_drink();
};




//======================================//
//				   Combo				//
//======================================//

/**
 * The Combo class for combo set orders.
 * TODO:
 *   Define a Combo class directly inherits OrderItem here.
 *   A combo set is made of a burger order, a fries order and a drink order.
 * 	 If an item is nullptr, it means the combo does not contain said item (e.g. combo of only burger and fries)
 *
 *   Requirements:
 *     There must be constructor of type Combo(Burger* burger, Fries* fries, Drink* drink).
 *
 *     The name for a combo of burger a, fries b and drink c is 
 *     "Combo " followed by names of a, b and c separated by " & ".
 *     For example, the name of the combo of the burger named "Beef Burger" and the fries named "Twisted Fries"
 *     is "Combo Beef Burger & Twisted Fries".
 *
 *     The price for a combo of burger a, fries b and drink c is the total price of a, b and c with 10% discount (the discount is floored). 
 *     For example, the price of the combo of a 30 HKD burger and a 18 HKD fries
 *     is 30 + 18 - floor(0.1*(30 + 18)) = 44HKD.
 */
//=========== TODO ===================================================

class Combo: public OrderItem {
	private:
		Burger* burger;
		Fries* fries;
		Drink* drink;

	public:
		
		Combo(Burger* burger, Fries* fries, Drink* drink);

		virtual ~Combo();

		virtual std::string get_name() const override;

		virtual int get_price() const override;

		static Combo* order_combo();
};








//--------------------------------------------------------------------

#endif //__ORDER_ITEM_H__
