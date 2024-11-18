/**
 * @file order.cpp
 * @brief Definitions of member functions for Order.
 * 
 * This file defines member functions for the Order class.
 */

#include <iostream>
#include "order.h"

/**
 * Destructor for Order
 */
Order::~Order() {
	for (OrderItem* item : this->items)
		delete item;
}

/**
 * Repeatedly make order item till order_item returns nullptr or user selects n.
 */
void Order::place_order() {
	while (true) {
		OrderItem* item = OrderItem::order_item();
		if (item == nullptr) {
			break;
		}
		this->items.push_back(item);

		std::cout << "Add more item? [y/n]: ";
		char input;
		std::cin >> input;
		if (input == 'n') {
			break;
		}
	}
}

/**
 * If there is any order item.
 */
bool Order::is_empty() const {
	return this->items.empty();
}

/**
 * Display order information.
 */
void Order::view() const {
	int total_price = 0;
	std::cout << "The Order:" << std::endl;
	std::cout << "################### Order ###################" << std::endl;
	for (int i = 0; i < this->items.size(); i++) {
		std::string name = this->items[i]->get_name();
		int price = this->items[i]->get_price();
		std::cout << std::setw(3) << i+1 << "- " << name << std::endl;
		std::cout << std::setw(40) << price << "HKD" << std::endl;
		total_price += price;
	}
	std::cout << std::endl;
	std::cout << "#############################################" << std::endl;
	std::cout << "Total: " << total_price << "HKD" << std::endl;
}

/**
 * Submit the order. After submit, the order would be prepared and cannot be cancelled.
 */
void Order::submit() {
	this->submitted = true;
	std::cout << "Prepare the order:" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->items.size(); i++) {
		this->items[i]->prepare();
	}
}

/**
 * Cancel the order. After submit, the order cannot be cancelled.
 */
void Order::cancel() {
	if (this->submitted) {
		std::cout << "The order cannot be cancelled after submit." << std::endl;
		return;
	}
	std::cout << "Clear the order" << std::endl;
	while (!this->items.empty()) {
		delete this->items.back();
		this->items.pop_back();
	}
}
