

// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-01
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_RESTARURANT_H
#define _SDDS_RESTARURANT_H

#include <ostream>
#include "Reservation.h"

namespace sdds{

	class Restaurant
	{
		Reservation* m_reservations; //Dynamically allocated array of reservations
		size_t m_restaurant_reserv_size;

		void setToEmpty(); //sets object to an empty safe state

	public :
		Restaurant(); //default constructor

		Restaurant(Reservation* reservations[], size_t cnt); //custom constructor that inserts reservations

		Restaurant(const Restaurant& src); //copy constructor

		Restaurant(Restaurant&& src); //move constructor

		~Restaurant();

		size_t size() const;
		

		Restaurant& operator=(const Restaurant& src);
		Restaurant& operator=(Restaurant&& res);

		friend std::ostream& operator<<(std::ostream&, const Restaurant& src);
	};


}

#endif