#include <algorithm>  //Used for remove_if std function
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Reservation.h"


using namespace std;

namespace sdds {


	Reservation::Reservation() {

		SetToEmptyState(); //Set object to a safe empty state
	}


	Reservation::Reservation(const std::string& m_res) {

		SetToEmptyState(); //Set object to a safe empty state

		std::string tmp(m_res); //tmp object used to delete white lines
		stringstream tmp2; //2nd tmp object for parsing through using getline

		//Step 1: Remove white spaces from data line;
		//Remove_If looks for all the whitespaces and moves them to the right side of the string.
		//because remove_if does not actually remove them from the string, we call the erase function
		tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());


		//Copy over converted string that no longer has whitespaces to a stringstream obj to allow for easier parsing
		tmp2.str(tmp);

		//Grab Reservation ID
		std::getline(tmp2, m_reserv_ID, ':');

		//Grab Reservation Name
		std::getline(tmp2, m_reserv_name, ',');

		//Grab Reservation Email
		std::getline(tmp2, m_reserv_email, ',');
		m_reserv_email = "<" + m_reserv_email + ">";

		//Grab # of people
		std::getline(tmp2, tmp, ',');
		m_Num_Of_People = size_t(stoul(tmp));

		//Grab reservation day
		std::getline(tmp2, tmp, ',');
		m_reserv_day = stoi(tmp);

		//Grab reservation time
		std::getline(tmp2, tmp, ',');
		m_reserv_hour = stoi(tmp);


		//Define reservertation type after all info has been entered

		if (m_reserv_hour >= 6 && m_reserv_hour <= 9) {
			m_reserve_Type = "Breakfast";
		}
		else if (m_reserv_hour >= 11 && m_reserv_hour <= 15) {
			m_reserve_Type = "Lunch";
		}
		else if (m_reserv_hour >= 17 && m_reserv_hour <= 21) {
			m_reserve_Type = "Dinner";
		}
		else
		{
			m_reserve_Type = "Drinks";
		}




		//cout << "String Line has now been converted from : " << m_res << std::endl << "To : " << tmp << std::endl;



	}

	void Reservation::SetToEmptyState()
	{

		m_reserve_Type = "NULL";
		 m_reserv_ID = "0";

		 m_reserv_name = "NULL";

		 m_reserv_email = "NULL";

		 m_Num_Of_People = 0u;

		 m_reserv_day = 0u;
		 m_reserv_hour = 0u;
	}

	std::string Reservation::getType() const
	{
		return m_reserve_Type;
	}

	std::string Reservation::getID() const
	{
		return m_reserv_ID;
	}

	std::string Reservation::getName() const
	{
		return m_reserv_name;
	}

	std::string Reservation::getEmail() const
	{
		return m_reserv_email;
	}

	size_t Reservation::getPeople() const
	{
		return m_Num_Of_People;
	}

	unsigned int Reservation::getDay() const
	{
		return m_reserv_day;
	}

	unsigned int Reservation::getHour() const
	{
		return m_reserv_hour;
	}


	
	ostream& operator<<(ostream& os, const Reservation& res)
	{

		//Reservation ID: NAME  <email>    Breakfast on day DAY @ HOUR:00 for #PARTY_SIZE people.
		//std::cout << "TEST : " << res.getEmail() << std::endl;
		
		os << "Reservation " << res.getID() << ": ";
		os << setw(10) << std::right << res.getName() << " ";
		os << setw(20) << std::left << res.getEmail();
		os << res.getType() << " on day " << res.getDay() <<" @ " << res.getHour() <<":00 for " << res.getPeople() << " people.";
		os << std::endl;
	
		return os;

	}

}