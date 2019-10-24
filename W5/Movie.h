// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 2019-10-17
//
// I confirm that the content of this file is created by me,
//with the exception of the parts provided to me by my professor.
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include <iostream>

namespace sdds {

	class Movie
	{

		std::string m_title;
		std::string m_year;
		std::string m_summary;


	public:
		void Trim(std::string& str);
		Movie();
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker) {

			spellChecker(m_title);
			spellChecker(m_summary);

				
		}
		const std::string& title() const;
		friend std::ostream& operator<< (std::ostream& os, const Movie& movie);

	};

}

#endif
