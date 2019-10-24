
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-01
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>

#include "Restaurant.h"

namespace sdds {



	void Restaurant::setToEmpty()
	{
		m_reservations = nullptr;
		m_restaurant_reserv_size = 0;

	}

	Restaurant::Restaurant()
	{
		setToEmpty();
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		setToEmpty();

		if (reservations) {//check if a nullpointer was sent

			m_reservations = new Reservation[cnt]; //if not nullpointer then allocate memory for a copy
			m_restaurant_reserv_size = cnt; //set size of m_reservations
			 
			for (auto i = 0u; i < size(); ++i) { //for every index create a clone
				//std::cout << "TEST : " << Reservation(*reservations[i]) <<std::endl;
				m_reservations[i] = Reservation(*reservations[i]);
			}
		}
	}

	Restaurant::Restaurant(const Restaurant& src)
	{
		setToEmpty();
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		setToEmpty();
		*this = std::move(src);

	}

	Restaurant::~Restaurant()
	{

		if (m_reservations) {
			delete[] m_reservations;
			m_reservations = nullptr;
		}

	}

	size_t Restaurant::size() const
	{
		return m_restaurant_reserv_size;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{

		if (&src != this) {

			if (m_reservations) {
				delete[] m_reservations;
				m_reservations = nullptr;
			}


			m_restaurant_reserv_size = src.m_restaurant_reserv_size;
			m_reservations = new Reservation[m_restaurant_reserv_size];


			for (auto i = 0u; i < m_restaurant_reserv_size; ++i) {

				m_reservations[i] = src.m_reservations[i];

			}
		}
		
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (&src != this) {

			if (m_reservations) {
				delete[] m_reservations;
				m_reservations = nullptr;
			}


			m_reservations = src.m_reservations;
			m_restaurant_reserv_size = src.m_restaurant_reserv_size;

			src.m_reservations = nullptr;
			src.m_restaurant_reserv_size = 0;



		}

		return *this;

	}




	std::ostream& operator<<(std::ostream& os, const Restaurant& src)
	{
	
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;
		

		if (src.size() == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {

			for (auto i = 0u; i < src.size(); ++i)
				os << src.m_reservations[i];

		}
		
		os << "--------------------------" << std::endl;
		
		return os;



	}

}
