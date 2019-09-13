// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca	
// Date of completion: 2019-09-10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "String.h"
namespace sdds {

	unsigned int g_maxSize = 3;
	void String::display(std::ostream& os) const
	{

		os << msg;

	}
	String::String()
	{
		msg[0] = '\0';
	}

	String::String(const char* sMsg)
	{
		if (sMsg != nullptr) { //if sMsg is not empty then copy sMsg to String::msg

			for (int i = 0; i < 3; ++i)
				msg[i] = sMsg[i];

			msg[3] = '\0';

		}
		else {
			msg[0] = '\0';
		}
	}
	std::ostream& operator<<(std::ostream& os, const String& str) //Add String::msg to output stream
	{
		
		static int timesCalled = 0;
		++timesCalled;
		os << timesCalled << ": ";
		str.display(os);
	
		return os;
	}
}