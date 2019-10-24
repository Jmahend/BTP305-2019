// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-01
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>
namespace sdds {


	class ConfirmationSender
	{

		const Reservation** m_reservations;
		size_t m_size;

		int findRes(const Reservation& res) const; //looks to see if res exist in m_reservation

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);


		~ConfirmationSender();

		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);

		ConfirmationSender& operator +=(const Reservation& res);
		ConfirmationSender& operator -=(const Reservation& res);

		friend std::ostream& operator<< (std::ostream&, const ConfirmationSender& src);
	};



}



#endif