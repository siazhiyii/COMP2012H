/**
 * @file order.h
 * @brief The Order class.
 *
 * This file declares and defines a Order class.
 */

#ifndef __ORDER_H__
#define __ORDER_H__
#include <vector>
#include "order_item.h"

/**
 * The Order class for making, viewing, and preparing
 * a order.
 */
class Order {
	private:
		//Ordered items;
		std::vector<OrderItem*> items;

		//If submitted, after submit cannot be cancelled.
		bool submitted = false;

	public:
		// Destructor for Order
		~Order();

		//If there is any item ordered.
		bool is_empty() const;

		//Making a order.
		void place_order();

		//View current order.
		void view() const;

		//Submit the order, it will automatically prepare all items.
		void submit();

		//Cancel this order, only available if not submitted.
		void cancel();
};

#endif //__ORDER_H__
