// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/10/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <iomanip>
#include<iterator> //for iteraors
#include <algorithm>
#include <utility>// std::move (objects)
#include "CustomerOrder.h"
#include "Utilities.h"



size_t CustomerOrder::m_widthField = 0;
bool   CustomerOrder::debug = false; //used for debugging reasons


void CustomerOrder::setToEmpty()
{
	
	m_name = "Empty";
	m_product = "Empty";
	m_cntItem = 0;
	//m_lstItem = nullptr;

	if (debug) std::cout << "Customer Order set to empty state" << std::endl;
}

void CustomerOrder::Deallocate()
{

	if (debug) std::cout << this->m_name << "'s Deallocate Called" << std::endl;

	for (auto& obj : m_lstItem)
		delete obj;

	if (debug) std::cout << this->m_name << "'s Deallocation finished" << std::endl;

}


CustomerOrder::~CustomerOrder()
{

	Deallocate();
}

CustomerOrder::CustomerOrder() {
	setToEmpty();
}
CustomerOrder::CustomerOrder(std::string& line)
{

	if (debug) std::cout << "--------------CustomerOrder Constructor : (" << line << ") Called--------------" << std::endl;
	
	
	Utilities extractor; //used for extracting token
	std::string tmp_holder; //

	bool token_found = true;
	size_t cur_pos = 0;


	setToEmpty();
	
	
		m_name = extractor.extractToken(line, cur_pos, token_found);
		m_product = extractor.extractToken(line, cur_pos, token_found);
		
		if (debug) std::cout << "m_name : " << m_name << std::endl << "m_product : " << m_product << std::endl << std::endl;

		while (cur_pos != std::string::npos) {
		
			tmp_holder = extractor.extractToken(line, cur_pos, token_found);

			if (!tmp_holder.empty()) {
				m_lstItem.push_back(new ItemInfo(tmp_holder));
				m_cntItem++;

				if (debug) {
					std::cout << "New ItemInfo obj Added : " << tmp_holder << std::endl << "Item Count(m_cntItem) : " << m_cntItem << std::endl;
				}
			}
			
		}

		if (extractor.getFieldWidth() > m_widthField) { //check if extractor's fieldWidth is greater then Item's fieldWidth

			m_widthField = extractor.getFieldWidth(); //if so then change Item's fieldWidth

		}

		if (debug) std::cout << "m_name : " << m_name << std::endl << "m_product : " << m_product <<  "Item Count(m_cntItem) : " << m_cntItem << std::endl << "--------------CustomerOrder Constructor : (" << line << ") FINISHED--------------" << std::endl << std::endl ;



	}

CustomerOrder::CustomerOrder(CustomerOrder&& cust_order) noexcept
{
	*this = std::move(cust_order);
}

bool CustomerOrder::getItemFillState(std::string item_name) const
{
	auto it = std::find_if(m_lstItem.begin(), m_lstItem.end(), [&item_name](const ItemInfo* item_info_obj) {return item_info_obj->m_itemName.compare(item_name) == 0; });
	return (it != m_lstItem.end() ? (*it)->m_fillState : true);

}

bool CustomerOrder::getOrderFillState() const
{
	auto it =std::find_if_not(m_lstItem.begin(), m_lstItem.end(), [](const ItemInfo* item_info_obj) { return item_info_obj->m_fillState; });
	return it == m_lstItem.end(); //all item fillstates are true if this statement are true
}

void CustomerOrder::fillItem(Item& item, std::ostream& os)
{

	auto it = find_if(m_lstItem.begin(), m_lstItem.end(), [&item](const ItemInfo* item_info_obj) {return item.getName().compare(item_info_obj->m_itemName) == 0; });

	if (it != m_lstItem.end()) {

		if (item.getQuantity() > 0) { //If there is quantity in stock
			item.updateQuantity(); //minus 1 from quantity
			(*it)->m_serialNumber = item.getSerialNumber();
			(*it)->m_fillState = true;

			//print Filled NAME, PRODUCT[ITEM_NAME].
			os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
		}
		else
			os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName()  << std::endl;

	}


}

void CustomerOrder::display(std::ostream& os)
{
	os << m_name << " - " << m_product << std::endl;
	

	std::for_each(m_lstItem.begin(), m_lstItem.end(), [&os](const ItemInfo* obj) {

		os << "[";
		os << std::setfill('0') << std::setw(6) << obj->m_serialNumber << std::setfill(' ');
		os << "] ";
		os << std::setw(m_widthField) << obj->m_itemName;
		os << " - ";
		os << (obj->m_fillState ? "FILLED" : "MISSING");
		os << std::endl;

	});



}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cust_order) 
{

	if (debug) {
		std::cout << "Move Opeartor Called for " << this->m_name << " <----- " << cust_order.m_name << std::endl << std::endl;
		std::cout << "Before move Operations : " << std::endl << "m_name : " << this->m_name << std::endl << "m_product : " << this->m_product << std::endl << "m_cntItem : " << this->m_cntItem << std::endl << std::endl;
	}


	if (this != &cust_order) {
		
		m_name = cust_order.m_name;
		m_product = cust_order.m_product;
		m_cntItem = cust_order.m_cntItem;


		this->Deallocate();
		m_lstItem.resize(cust_order.m_lstItem.size());

		m_lstItem = std::move(cust_order.m_lstItem);

		
		cust_order.m_cntItem = 0;

		cust_order.m_lstItem.resize(0);
		cust_order.m_lstItem.shrink_to_fit();

	}

	if (debug) {
		std::cout << "After move Operations : " << std::endl << "m_name : " << this->m_name << std::endl << "m_product : " << this->m_product << std::endl << "m_cntItem : " << this->m_cntItem << std::endl << std::endl;
		std::cout << "Move Opeartor Called for " << this->m_name << " <----- " << cust_order.m_name << "  FINISHED" << std::endl << std::endl;
	}
	return *this;
}

CustomerOrder::CustomerOrder(const CustomerOrder& cust_order)
{
	throw "Copy operations for CustomerOrder is ILLEGAL";
}







