// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 10/24/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>

#include "Item.h"
#include "Utilities.h"

using namespace std;

namespace sdds {



	size_t Item::m_widthField = 1;
	bool Item::debug = true;



	Item::Item(const std::string& str)
	{
		setToEmpty();

		Utilities exractor;

		bool more = true;
		size_t cur_pos = 0;

		for (int i = 0; i < 4; ++i) { //For each attribute in Item extract a token. (Initialize each attribute in Item with a Utilities object

			if (debug)
				cout << endl << "For Loop i = " << i << endl;

			if (more) {

				if (debug)
					cout << "more = " << more << std::endl;

				//Self-Explaintory
				switch (i) {

				case 0 : m_name = exractor.extractToken(str, cur_pos, more);
						if (debug)
							std::cout << "m_Name : |" << m_name <<"|" << std::endl;
					break;
				case 1 : m_serialNumber = std::stoi(exractor.extractToken(str, cur_pos, more));
						if (debug)
							std::cout << "m_serialNumber : |" << m_serialNumber << "|" << std::endl;
					break;

				case 2: m_quantity = std::stoul(exractor.extractToken(str, cur_pos, more));
						if (debug)
							std::cout << "m_quantity : |" << m_quantity << "|" << std::endl;
					break;

				case 3 : m_description = exractor.extractToken(str, cur_pos, more);
							if (debug)
								std::cout << "m_description : |" << m_description << "|" << std::endl;
					break;
				}
				
			}
			else {
				break; //breaks for loops
			}
		}

		if (exractor.getFieldWidth() > m_widthField) { //check if extractor's fieldWidth is greater then Item's fieldWidth

			m_widthField = exractor.getFieldWidth(); //if so then change Item's fieldWidth
		}



	}

	void Item::display(std::ostream& os, bool full) const
	{
		
		os << std::setw(m_widthField) << std::left << getName();
		os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ');

		//if a full display is wanted then add Quantity and description to ostream 
		full ? os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity <<
			" Description: " << m_description << std::endl : os << std::endl;


	}



	void Item::setToEmpty()
	{

		m_name = "EMPTY";
		m_description = "EMPTY";
		m_quantity = 0;
		m_serialNumber = 0;
	}

	Item::Item()
	{
		setToEmpty();
	}
	Item::~Item()
	{
	}
	const std::string& Item::getName() const
	{
		return m_name;
	}

	const unsigned int Item::getSerialNumber()
		//returns the next serial number to be used on the assembly line and increments m_serialNumber
	{
		return m_serialNumber++;
	}

	const unsigned int Item::getQuantity() const
	{
		return m_quantity;
	}

	void Item::updateQuantity()
	{
		--m_quantity;
	}
}