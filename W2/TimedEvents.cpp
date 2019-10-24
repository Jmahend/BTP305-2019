
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-09017
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "TimedEvents.h"
#include <iomanip>
#include <iostream>

namespace sdds {
	TimedEvents::TimedEvents()
	{


		m_Num_Records = 0;

		m_Event_Start_Time = std::chrono::steady_clock::now();
		m_Event_End_Time = std::chrono::steady_clock::now();

		for (auto& x : m_Records) {

			x.Event_Name = "EMPTY_EVENT";
			x.Predefined_Units_Of_Time = "EMPTY";
		}



	}

	void sdds::TimedEvents::startClock()
	{

			m_Event_Start_Time = std::chrono::steady_clock::now();
		


	}

	void TimedEvents::stopClock()
	{


		m_Event_End_Time = std::chrono::steady_clock::now();


	}

	void TimedEvents::recordEvent(const char* name)
	{


		if (name != nullptr) {

			if (m_Num_Records >= 0 && m_Num_Records < 7) {

				m_Records[m_Num_Records].Event_Name = name;
				m_Records[m_Num_Records].Predefined_Units_Of_Time = "nanoseconds";
				m_Records[m_Num_Records].dur = std::chrono::duration_cast<std::chrono::nanoseconds>(m_Event_End_Time - m_Event_Start_Time);
				
				//std::cout << "m_Records[" << m_Num_Records << "] : " << m_Records[m_Num_Records].Event_Name << ", " << m_Records[m_Num_Records].dur.count() << std::endl;

				m_Num_Records++;




			}

		}


	}


	std::ostream& operator<<(std::ostream& os, const TimedEvents& te)
	{



		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;


		for (unsigned int i = 0; i < te.m_Num_Records; ++i) {

			os << std::setw(20) << std::left << te.m_Records[i].Event_Name;
			os << std::setw(12) << std::right << std::chrono::nanoseconds(te.m_Records[i].dur).count() << " " << te.m_Records[i].Predefined_Units_Of_Time;
			os << std::endl;


		}


		os << "--------------------------" << std::endl;

		return os;
	}
	
}


