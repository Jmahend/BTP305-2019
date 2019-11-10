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

		ItemInfo(std::string src) : m_itemName(src) {};
	};

	class CustomerOrder {

		std::string m_name; //Name of customer
		std::string m_product; //Name of the product being assembled
		unsigned int m_cntItem; //numer of items for the customer's order
		std::vector<ItemInfo*> m_lstItem; //

		static size_t m_widthField;
		static bool debug;

		void setToEmpty(); //set object to a safe empty state
		void Deallocate();
	public:
		
		//CustomerOrder isn't allowed to have copy operations ;3
		CustomerOrder(const CustomerOrder& cust_order);
		CustomerOrder& operator=(const CustomerOrder& cust_order) = delete;

		~CustomerOrder();
		CustomerOrder();
		CustomerOrder(std::string& line);
		CustomerOrder(CustomerOrder&& cust_order) noexcept;

		CustomerOrder& operator=(CustomerOrder&& cust_order);

		bool getItemFillState(std::string item_name) const;
		bool getOrderFillState() const;
		void fillItem(Item& item, std::ostream& os);
		void display(std::ostream& os);








	};





#endif