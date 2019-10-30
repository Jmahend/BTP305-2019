// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-29s
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include <istream>
#include "Vehicle.h"


namespace sdds {

	enum  Car_Condition : char { Brand_New = 'n', Used = 'u', Broken = 'b', Empty_Safe_State = 's' };

	class Car : public Vehicle
	{
		
			std::string m_manufacture;
			Car_Condition m_condition;
			double m_top_speed;
			bool isEmpty;

			static bool debug; //used for debugging reasons :)


			void SetToSafeEmptyState();
	

		public:

			Car();
			Car(std::istream& is);
			~Car();


			double topSpeed() const;
			void display(std::ostream& os) const;
			std::string condition() const;
	};

}

#endif