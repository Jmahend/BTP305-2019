
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-09017
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include<fstream>
#include <iostream>

#include "Text.h"


namespace sdds {

	Text::Text()
	{
		m_NumOfRecords = 0;
		m_Text = nullptr;

	}

	Text::Text(const Text& src)
	{
		m_NumOfRecords = 0;
		m_Text = nullptr;

		*this = src;

	}

	Text::Text(Text&& src)
	{

		m_NumOfRecords = 0;
		m_Text = nullptr;

		*this = std::move(src);

	}

	Text& Text::operator=(Text&& src)
	{
	
		if (this != &src) { //check for self assignment

			delete[] m_Text; //empty out array before moving more into it
			m_Text = nullptr; //remove address from object


			m_Text = src.m_Text; //move over pointer address from src object
			m_NumOfRecords = src.m_NumOfRecords; //shallow copy numofrecords from src object

			src.m_Text = nullptr;


		}

		return *this;
	
	}

	Text::Text(const char* fileName)
	{

		m_Text = nullptr;
		m_NumOfRecords = 0;

		size_t NumOfLines = 0; //Used for getting the number of lines in file;

		std::ifstream infile(fileName); //Opens file if valid

		std::string line; //stores a single line of the a file




		if (infile.good()) { //check if the file is valid

			while (!infile.eof()) { //if file is valid then go through the file line by line till it reches end of file
				std::getline(infile, line, ' '); //Grab the next line from the file and copy it to the line string variable
				NumOfLines++;

			}


			m_Text = new std::string[NumOfLines];
			//	std::cout << "lines : " << NumOfLines << std::endl; //used for debugging
			//std::cout << "New string array allocated "<< std::endl; //used for debugging

			infile.clear(); //Reset eof flag
			infile.seekg(0); //set index to begining of file

			while (!infile.eof()) { //if file is valid then go through the file line by line till it reches end of file
				std::getline(infile, line, ' '); //Grab the next line from the file and copy it to the line string variable


				m_Text[m_NumOfRecords++] = line; //if this is the first loop then m_NumOfRecords will be 0;


					//std::cout << "Record : " << m_Text[m_NumOfRecords] << std::endl; //used for debugging

				
			}

			m_NumOfRecords--;





			/*if (m_NumOfRecords > 0) { //due to the way the above is coded I have to add 1 more to the size amount
				m_NumOfRecords++;
			}*/


			//std::cout << "Number of lines in file( " << fileName << ") : " << NumOfLines << std::endl;; //used for debugging






			infile.close(); //close the file once we are done with it






		}
	}

	Text& Text::operator=(const Text& src)
	{

		if (this != &src) {

			delete[] m_Text; //Empty out array
			m_Text = nullptr; 
			m_Text = new std::string[src.m_NumOfRecords];
			
			m_NumOfRecords = src.m_NumOfRecords;

			for ( size_t i = 0; i < src.m_NumOfRecords; ++i)
				m_Text[i] = src.m_Text[i];
		


		}

		return *this;


	}

	size_t Text::size() const
	{
		return m_NumOfRecords;
	}

	Text::~Text()
	{

		delete[] m_Text;
		m_Text = nullptr;

	}






}