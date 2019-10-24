// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 2019-10-17
//
// I confirm that the content of this file is created by me,
//with the exception of the parts provided to me by my professor.

#include <algorithm>  //Used for remove_if std function
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Book.h"
using namespace std;

namespace sdds {





	Book::Book()
	{

		m_author = "empty";
		m_title = "empty";
		m_pub_country = "empty";
		m_summary = "empty";
		m_pub_year = 0u;
		m_price = 0;


	}

	void Book::Trim(std::string& str) {

		while (str.at(0) == ' ') 
			str = str.substr(1, str.length() - 1);
		

		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);

	}

	Book::Book(const std::string strBook)
	{
		
		std::string tmp = strBook; //tmp object used to delete white lines

		stringstream tmp2; //2nd tmp object for parsing through using getline


		tmp2.str(tmp);


		//Grab author Name
		std::getline(tmp2, m_author, ',');
		Trim(m_author);

		//Grab title
		std::getline(tmp2, m_title, ',');
		Trim(m_title);

		//Grab country
		std::getline(tmp2, m_pub_country, ',');
		Trim(m_pub_country);

		//grab price
		std::getline(tmp2, tmp, ',');
		Trim(tmp);
		m_price = atof(tmp.c_str());

		//grab year
		std::getline(tmp2, tmp, ',');
		Trim(tmp);
		m_pub_year = size_t(stoul(tmp));

		//grab m_summary
		std::getline(tmp2, tmp);
		Trim(tmp);
		m_summary = tmp;
	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		
		return m_pub_country;

	}

	const size_t Book::year() const
	{
		return m_pub_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	std::ostream& operator<<(std::ostream& os, const Book& strBook)
	{


		os << setw(20) << strBook.m_author << " | ";
		os << setw(22) << strBook.m_title << " | ";
		os << setw(5) << strBook.m_pub_country << " | ";
		os << setw(4) << strBook.m_pub_year << " | ";
		os << setw(6) <<fixed << setprecision(2) << strBook.m_price << " | ";
		os << setw(6) << strBook.m_summary <<std::endl;



		return os;
	}

}