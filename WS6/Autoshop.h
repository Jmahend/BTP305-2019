// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-29s
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Car.h"
namespace sdds {



	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		//Autoshop();
		
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			for (auto& obj : m_vehicles)
			  vehicles.push_back(obj);


		}

		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& os) const;
		~Autoshop();
	};

}

#endif