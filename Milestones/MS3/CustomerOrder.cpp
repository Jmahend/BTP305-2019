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
#include <numeric>
#include "CustomerOrder.h"
#include "Utilities.h"



size_t CustomerOrder::m_widthField = 0;
bool   CustomerOrder::debug = false; //used for debugging reasons


ItemInfo* CustomerOrder::findFalseItem(std::string item_name) const
{
	ItemInfo* p_itemInfo = nullptr; //Assume there is no itemInfo with the name item_name with a false fillstate

	for (auto i = 0u; i < m_cntItem; ++i) //Scan itemInfo Array for itemInfo with item_name and a false fillstate
		if (m_lstItem[i]->m_itemName == item_name && m_lstItem[i]->m_fillState == false) {
			p_itemInfo = m_lstItem[i]; //if one is found then set the function's itemInfo pointer to it
			break; //break for loop for optimization purposes
		}

	return p_itemInfo;
}

void CustomerOrder::setToEmpty()
{
	
	m_name = "Empty";
	m_product = "Empty";
	m_cntItem = 0;
	m_lstItem = nullptr;

	if (debug) std::cout << "Customer Order set to empty state" << std::endl;
}

void CustomerOrder::Deallocate()
{

	if (debug) std::cout << this->m_name << "'s Deallocate Called" << std::endl;


	//for (auto& obj : m_lstItem)
	if (m_cntItem > 1) {
		for (auto i = 0u; i < m_cntItem; ++i) {
			if(m_lstItem != nullptr)
				delete m_lstItem[i];
		}

		delete[] m_lstItem;
	}
	else
		delete m_lstItem;

	m_cntItem = 0;

	if (debug) std::cout << this->m_name << "'s Deallocation finished" << std::endl;

}


bool CustomerOrder::isEmpty() const
{
	/*m_name = "Empty";
	m_product = "Empty";
	m_cntItem = 0;*/

	return (m_name.compare("Empty") == 0);

}

CustomerOrder::~CustomerOrder()
{
	Deallocate();
}

CustomerOrder::CustomerOrder() {
	setToEmpty();
}
CustomerOrder::CustomerOrder(std::string& line) : CustomerOrder()
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

		

		m_cntItem = std::count(line.begin(), line.end(), extractor.getDelimiter()) - 1;


		if (m_cntItem > 1 && m_cntItem != 0) {

			m_lstItem = new ItemInfo * [m_cntItem];

			for (auto i = 0u; i < m_cntItem; ++i) {

				tmp_holder = extractor.extractToken(line, cur_pos, token_found);

				if (!tmp_holder.empty())
					m_lstItem[i] = new ItemInfo(tmp_holder);
				else
					throw "Empty string inserted into ItemInfo Constructor in CustomerOrder Constructor";
			}

		}
		else if (m_cntItem == 1) {

			tmp_holder = extractor.extractToken(line, cur_pos, token_found);

			if (!tmp_holder.empty()) {
				m_lstItem = new ItemInfo*;

				*m_lstItem = new ItemInfo(tmp_holder);
			}
			else
				throw "Empty string inserted into ItemInfo Constructor in CustomerOrder Constructor";

			if (debug) {
				std::cout << "New ItemInfo obj Added : " << tmp_holder << std::endl << "Item Count(m_cntItem) : " << m_cntItem << std::endl;
			}
		}
		else
			throw "EMPTY NUMBER OF REQUESTED ITEMS THUS INVALID ORDER!!!!!!";



		if (extractor.getFieldWidth() > m_widthField) { //check if extractor's fieldWidth is greater then Item's fieldWidth

			m_widthField = extractor.getFieldWidth(); //if so then change Item's fieldWidth

		}

		if (debug) std::cout << "m_name : " << m_name << std::endl << "m_product : " << m_product <<  "Item Count(m_cntItem) : " << m_cntItem << std::endl << "--------------CustomerOrder Constructor : (" << line << ") FINISHED--------------" << std::endl << std::endl ;



	}

CustomerOrder::CustomerOrder(CustomerOrder&& cust_order) noexcept : CustomerOrder()
{
	*this = std::move(cust_order);
}

bool CustomerOrder::getItemFillState(std::string item_name) const 
{	
	ItemInfo* p_itemInfo = findFalseItem(item_name); //findFalseItem function exist because the logic is reused more then once. (Check fillItem)
	
	return (p_itemInfo != nullptr ? p_itemInfo->m_fillState : true); //if p_itemInfo is nullptr then no false ItemInfo was found

}


bool CustomerOrder::getOrderFillState() const
{

	//A order is filled when all itemInfo's have a fillstate of true; 
	bool isOrderFilled = true;  //Assume that all itemInfo's have a fillstate of true a.k.a the order is filled.

	for (auto i = 0u; i < m_cntItem; ++i) //Scan itemInfo Array for itemInfo with a false fillstate
		if (m_lstItem[i]->m_fillState == false) {
			isOrderFilled = false; //if a false item is found then the order is automatically declared NOT FILLED;
			break; //break for optimization purposes
		}
	
	return isOrderFilled; //all item fillstates are true if isorderfilled is true
}

void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
	//This line may have to move ):
	ItemInfo* p_itemInfo = findFalseItem(item.getName());

	if (p_itemInfo != nullptr) {

		if (item.getQuantity() > 0) { //If there is quantity in stock
			item.updateQuantity(); //minus 1 from quantity
			p_itemInfo->m_serialNumber = item.getSerialNumber();
			p_itemInfo->m_fillState = true;

			//print Filled NAME, PRODUCT[ITEM_NAME].
			os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
		}
		else
			os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName()  << std::endl;

	}


}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	

	for (auto i = 0u; i < m_cntItem; ++i){

		os << "[";
		os <<  std::right << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << std::setfill(' ');
		os << "] " << std::left;
		os << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
		os << " - ";
		os << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING");
		os << std::endl;

	};



}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cust_order) 
{

	if (debug) {
		std::cout << "Move Opeartor Called for " << this->m_name << " <----- " << cust_order.m_name << std::endl << std::endl;
		std::cout << "Before move Operations : " << std::endl << "m_name : " << this->m_name << std::endl << "m_product : " << this->m_product << std::endl << "m_cntItem : " << this->m_cntItem << std::endl << std::endl;
	}


	if (this != &cust_order) {
		
		//Shallow copy static memory (might be possible to move this for optimization purposes)
		m_name = cust_order.m_name;
		m_product = cust_order.m_product;
		


		this->Deallocate(); //Deallocate this object
		//Once deallocation is done we can begin adding dynamic array ownership
		m_cntItem = cust_order.m_cntItem;
		//add ownership of dynamic memory to this object
		m_lstItem = cust_order.m_lstItem;

		//Remove ownership of dynamic memory from previous owner
		cust_order.m_lstItem = nullptr;
		cust_order.m_cntItem = 0; 

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







