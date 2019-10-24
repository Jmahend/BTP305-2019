// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 2019-10-17
//
// I confirm that the content of this file is created by me,
//with the exception of the parts provided to me by my professor.

#include <sstream>
#include <iomanip>
#include "Movie.h"


using namespace std;
namespace sdds {


	void Movie::Trim(std::string& str) {

		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);


		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);

	}

	Movie::Movie()
	{
		m_title = "EMPTY";
		m_year = "EMPTY";
		m_summary = "EMPTY";

	}

	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{

		std::string tmp = strMovie; //tmp object used to delete white lines

		stringstream tmp2; //2nd tmp object for parsing through using getline


		tmp2.str(tmp);


		//Grab author Name
		std::getline(tmp2, m_title, ',');
		Trim(m_title);

		//grab year
		std::getline(tmp2, tmp, ',');
		Trim(tmp);
		std::stringstream sstream(tmp); //so i can convert year string to size_t
		sstream >> m_year;
		//std::cout << "YEAR: " << tmp << std::endl;

		//grab m_summary
		std::getline(tmp2, tmp);
		Trim(tmp);
		m_summary = tmp;
	}




	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{

		os << setw(40) << movie.m_title << " | ";
		os << setw(4) << movie.m_year << " | ";
		os << movie.m_summary <<std::endl;
		os << setw(0);


		return os;
	}

}