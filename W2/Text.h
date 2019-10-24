
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-09017
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_TEXT_H
#define _SDDS_TEXT_H

#include <string>
#include <vector>



namespace sdds {

	class Text
	{
		size_t m_NumOfRecords;
		std::string *  m_Text ;


		

	public:

		Text(); // default constructor
		Text(const Text& src);   //copy constructor
		Text(Text&& src);

		Text& operator=(Text&& src);

		Text(const char* str); // constructor used for storing text from a file into object

		Text& operator=(const Text& src); //copy assignment operator

		size_t size() const;

		~Text();
	};

}

#endif
