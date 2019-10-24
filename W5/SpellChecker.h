// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-01
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
#include <vector>
namespace sdds {

	class SpellChecker
	{

		std::string	m_badWords[5];
		std::string m_goodWords[5];

		

	public:

		void Trim(std::string& str);
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;

	};

}

#endif
