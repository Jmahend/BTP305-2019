// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 2019-10-17
//
// I confirm that the content of this file is created by me,
//with the exception of the parts provided to me by my professor.
#include <fstream>
#include <iostream>
#include "SpellChecker.h"


using namespace std;
namespace sdds {


	void SpellChecker::Trim(std::string& str) {

		while (str.at(0) == ' ')
			str = str.substr(1, str.length() - 1);


		while (str.at(str.length() - 1) == ' ')
			str = str.substr(0, str.length() - 1);


	}


	SpellChecker::SpellChecker(const char* filename)
	{ 
		/*
			file format (bad word, good word): 

			modiffied    modified
			begim        begin
			famillies    families
			Dork         Dark
			hibrid       hybrid
		*/




		unsigned int firstSpace;

		std::string tmp; 

		ifstream aFile(filename);

		if (aFile.good()) {

			

			for (int i = 0; i < 5; ++i) {

				std::getline(aFile, tmp);

				firstSpace = tmp.find(' '); // Find first space 

				m_badWords[i] = tmp.substr(0, firstSpace); // Anything before the first space represents the bad_word
				m_goodWords[i] = tmp.substr(firstSpace, tmp.length() - 1); //anything after the fist space represents the good word

				/*
				std::cout << "String Before Trim |" << tmp << "|" << std::endl;
				std::cout << "badWord Before Trim |" << m_badWords[i] << "|" << std::endl; //for debugging purposes
				std::cout << "goodWord Before Trim |" << m_goodWords[i] << "|" << std::endl; //for debugging purposes
				*/

				Trim(m_badWords[i]); //Trim for any preceeding or succeeding spaces for safety purposes
				Trim(m_goodWords[i]); //Trim for any preceeding or succeeding spaces for safety purposes
				
				/*
				std::cout << "badWord After Trim |" << m_badWords[i] << "|" << std::endl; //for debugging purposes
				std::cout << "goodWord After Trim |" << m_goodWords[i] << "|" << std::endl; //for debugging purposes
				std::cout << "String After Trim |" << tmp <<  "|" <<  std::endl;
				*/
			}


		}
		else {
			throw "Bad file name!";
		}


	}

	void SpellChecker::operator()(std::string& text) const
	{

		//std::cout << "String |" << text << "|" << std::endl << std::endl;
		for (int i = 0; i < 5; ++i) { // go through m_badwords array 

			
			while (text.find(m_badWords[i]) != string::npos) { // If a bad word exist then replace it, then loop and check again
				//std::cout << "Bad Word Found |" << m_badWords[i] << "|" << std::endl << std::endl;


				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]); //replace the bad word with a good word ;3

				//std::cout << "String After Replace |" << text << "|" << std::endl << std::endl;

			}

		}



	}

}