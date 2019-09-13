// Name: Tai-Juan Rennie	
// Seneca Student ID:  101359172
// Seneca email: trennie1@myseneca.ca	
// Date of completion: 2019-09-10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef STRING_H
#define STRING_H


#include <iostream>


namespace sdds {


	extern unsigned int g_maxSize;

	class String {

		char msg[4];  // holds a C-style null-terminated string of up to 3 characters excluding the null byte terminator



	public:
		
		void display(std::ostream& os) const; //inputs msg into output buffer
		String();//initializes msg property
		String(const char* sMsg); //Copies char array to msg property

	};


	std::ostream& operator<<(std::ostream& os, const String& str); //free helper function for String objects

}












#endif