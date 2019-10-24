#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 2019-10-17
//
// I confirm that the content of this file is created by me,
//with the exception of the parts provided to me by my professor.
#include "SpellChecker.h"
#include <string>
#include<iostream>
namespace sdds {

	class Book {


		std::string m_author;
		std::string m_title;
		std::string m_pub_country;
		std::string m_summary;


		size_t m_pub_year;
		double m_price;


	public:
		void Trim(std::string& str);
		Book();
		Book(const std::string strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t year() const;
		double& price();


		template <class T>
		void fixSpelling(T spellChecker) {

			spellChecker(m_summary);

		}


		template <class T>
		void fixSpelling(T spellChecker, std::string& str) {

			spellChecker(str);

		}

		
		
		friend std::ostream& operator<<(std::ostream& os, const Book& strBook);
	};


	void Trim(std::string& str);



}


#endif