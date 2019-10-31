
#include <sstream>
#include <string>
#include "Racecar.h"
namespace sdds {



	void Racecar::setToEmpty()
	{
		m_booster = 0;
	}



	Racecar::Racecar()
	{
		setToEmpty();
	}

	Racecar::Racecar(std::istream& is) : Car(is)
	{
		setToEmpty();

	

		std::string line;

		unsigned int last_delim_pos = 0;

		std::stringstream ss;

		std::getline(is, line);
		
		Car::Trim(line);

		last_delim_pos = line.find_last_of(',');

		if (last_delim_pos != std::string::npos) {
			m_booster = std::stod(line.substr(last_delim_pos + 1));
		}
		

		
	}

	void Racecar::display(std::ostream& os) const
	{

		Car::display(os);
		os << "*";
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed()  + (Car::topSpeed() * m_booster);
	}

}