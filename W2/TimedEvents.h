
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-09017
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H


#include <ostream>
#include <chrono>
#include <string>



namespace sdds {
	class TimedEvents
	{


		size_t m_Num_Records;  //The number of records stored

		std::chrono::steady_clock::time_point m_Event_Start_Time; //The start time of the current event
		std::chrono::steady_clock::time_point m_Event_End_Time; //The  end time of the current event


		struct {

			std::string Event_Name; 
			std::string Predefined_Units_Of_Time;

			std::chrono::steady_clock::duration dur; //duration of event


		} m_Records[7];



	public:


		TimedEvents(); 

		void startClock();
		void stopClock();


		void recordEvent(const char * name);


		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& te);

	};




}
#endif