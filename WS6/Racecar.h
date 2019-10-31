#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include "Car.h"



namespace sdds {

	class Racecar : public Car {

		double m_booster;

		void setToEmpty();
	public:

		
		Racecar();
		Racecar(std::istream& is);

		void display(std::ostream& os) const;
		double topSpeed() const;

	};


}



#endif