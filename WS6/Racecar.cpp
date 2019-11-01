#include <iostream>
#include <iomanip>
#include <sstream>
#include "Racecar.h"


namespace sdds {


	bool Racecar::debug = false;

	void Racecar::setToEmpty()
	{
		if (debug) std::cout << "Race car set to safe empty state" << std::endl;
		m_booster = 0;

	}

	Racecar::Racecar() : Car()
	{
		setToEmpty();
	}

	Racecar::Racecar(std::istream& is) : Car(is)
	{

		
		if (debug) std::cout << "-------------- Racecar Constructor (istream&) Called -------------------" << std::endl;

		//setToEmpty();
		

		std::string line;
		std::string token;
		unsigned int last_delim_pos; //Postion/index of last 

		std::getline(is, line); // should return TAG,MAKER,CONDITION,TOP_SPEED,BOOSTER
		Car::Trim(line); //remove spaces from line


		last_delim_pos = line.find_last_of(Car::getDelim());

		if (debug) std::cout << "Line after TRIM : " << std::endl << "Last delimiter position : " << last_delim_pos << std::endl;

		
		if (last_delim_pos != std::string::npos && !line.empty()) {
			token = line.substr(last_delim_pos + 1);
		
			if (debug) std::cout << "m_booster Token : " << token << std::endl;

			if (Car::isAnInt(token))
				m_booster = stod(token);

		}
			
			
			
			



		if (debug) std::cout << "-------------- Racecar Constructor (istream&) Called -------------------" << std::endl << std::endl;

	}

	void Racecar::display(std::ostream& os) const
	{

		std::string line;
		std::stringstream ss;
		unsigned int TopSpeed_pos;
		

		
		Car::display(ss); //returns car data + \n (a.k.a endl)
		

	
		line = ss.str();
	
		line = line.substr(0,23);

	
	

		
		os << line;
		os << std::setw(6) << std::setprecision(2) << std::fixed << this->topSpeed();

		os << " |" << std::endl;
		
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}

}