// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-01
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {

	class Reservation
	{

		std::string m_reserve_Type;

		std::string m_reserv_ID;

		std::string m_reserv_name;

		std::string m_reserv_email;

		unsigned int m_Num_Of_People;

		unsigned int m_reserv_day;
		unsigned int m_reserv_hour;

	public:
		Reservation();
		Reservation(const std::string& m_res);

		void SetToEmptyState();


		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

		Reservation& operator=(const Reservation& src); //copy operator
		bool operator==(const Reservation& src) const; //copy operator


	};

}



#endif