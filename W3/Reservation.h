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

		std::string getType() const;
		std::string getID() const;
		std::string getName() const;
		std::string getEmail()const;
		unsigned int getPeople() const;
		unsigned int getDay() const;
		unsigned int getHour() const;


		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	
	};

}
	


#endif