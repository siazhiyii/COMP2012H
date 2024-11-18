#include <iostream>
#include "order.h"

int main () {
	Order order;
	std::cout << "1. Please place an order:" << std::endl;
	order.place_order();
	std::cout << std::endl;
	if (!order.is_empty()) {
		std::cout << "2. View the order:" << std::endl;
		order.view();
		std::cout << std::endl;
		std::cout << "3. Submit the order:" << std::endl;
		order.submit();
		std::cout << std::endl;
	} else {
		std::cout << "No order created!" << std::endl;
	}
	return 0;
}
