// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca	
// Date of completion: 2019-09-10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <cstring>
#include "String.h"


using namespace std;

namespace sdds {

	unsigned int g_maxSize = 3;

	void String::display(std::ostream& os) const
	{

		if (msg != nullptr)
			os << msg;

	}

	String::String()
	{
		msg = nullptr;
	}

	String::String(const String& src) //copies one string from another
	{

		msg = nullptr;
		*this = src; //call copy assignment operator
	}

	String::~String(){


		delete[] msg;
		msg = nullptr;

	}

	String::String(const char* sMsg) : msg(nullptr)
	{

		size_t length = 0; //Used to store size of sMsgc
		
		if (sMsg != nullptr) {

			length = strlen(sMsg); // grab size of msg

			if (length > g_maxSize) {

				msg = new char[g_maxSize + 1];
				strncpy(msg, sMsg, g_maxSize);
				msg[g_maxSize] = '\0';

			}
			else {

				msg = new char[length + 1]; // create  new char array of sMsg length
				strncpy(msg, sMsg, length);
				msg[length] = '\0';
			}

		}

	}

	String& String::operator=(const String& src)
	{


	
		if (this != &src) { //check for self-assignment

			delete[] msg; //delete any msg data that may exist
			msg = nullptr; 

			if (src.msg != nullptr) { //check if src is active

				msg = new char[strlen(src.msg) + 1]; //begin copy process

				strncpy(msg, src.msg, strlen(src.msg));
				msg[strlen(src.msg)] = '\0';
			}


		}
			
		return *this; //return new copy
	
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