// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/10/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef CUSTOMERORDERS_H
#define CUSTOMERORDERS_H

#include <string>
#include <vector>
#include "Item.h"


	struct ItemInfo
	{
		std::string m_itemName;
		unsigned int m_serialNumber = 0;
		bool m_fillState = false;

		ItemInfo(std::string src) : m_itemName(src) {}; //Request for item
	};

	class CustomerOrder {

		std::string m_name; //Name of customer
		std::string m_product; //Name of the product being assembled
		unsigned int m_cntItem; //numer of items for the customer's order

		ItemInfo** m_lstItem; //All item Request in this customer order

		static size_t m_widthField;
		static bool debug;

		ItemInfo* findFalseItem(std::string item_name) const; //Function exist because code is reused more then once (fillItem && getItemFillstate)
		void setToEmpty(); //set object to a safe empty state
		void Deallocate();
	public:
		
		//CustomerOrder isn't allowed to have copy operations ;3
		CustomerOrder(const CustomerOrder& cust_order);
		CustomerOrder& operator=(const CustomerOrder& cust_order) = delete;
		bool isEmpty() const;
		~CustomerOrder();
		CustomerOrder();
		CustomerOrder(std::string& line);
		CustomerOrder(CustomerOrder&& cust_order) noexcept;

		CustomerOrder& operator=(CustomerOrder&& cust_order);

		bool getItemFillState(std::string item_name) const;
		bool getOrderFillState() const;
		void fillItem(Item& item, std::ostream& os);
		void display(std::ostream& os) const;








	};





#endif