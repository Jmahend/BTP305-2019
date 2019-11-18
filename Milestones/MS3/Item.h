// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 10/24/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H

#include <string>


	class Item
	{

		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		size_t m_quantity; //the number of current items left in stock

		static  bool debug;
		static size_t m_widthField; //All Item objects share the same m_widthField

		void setToEmpty();

	public:
		Item(const std::string& str);
		Item();
		~Item();

		const std::string& getName() const;
		const unsigned int getSerialNumber();
		const unsigned int getQuantity() const;

		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};



#endif