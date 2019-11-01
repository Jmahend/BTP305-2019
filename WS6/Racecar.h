#include <iostream>
#include "Car.h"



namespace sdds {


	class Racecar : public Car {

		double m_booster;
		static bool debug; //for debugging purposes
		void setToEmpty();

	public:
		Racecar();
		Racecar(std::istream& is);

		void display(std::ostream& os) const;
		double topSpeed() const;
	};

}
