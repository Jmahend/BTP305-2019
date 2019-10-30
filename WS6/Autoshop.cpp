// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-29s
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Autoshop.h"


namespace sdds {
	
	Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& os) const
	{

		os << "--------------------------------" <<std::endl;
		os  << "| Cars in the autoshop!        |" << std::endl;
		os << "--------------------------------" << std::endl;

		for (auto& obj : m_vehicles)
		obj->display(os);

		os << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop()
	{

		m_vehicles.clear();
	}
}

