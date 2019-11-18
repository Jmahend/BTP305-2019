// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 10/24/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include "Utilities.h"



	std::string Utilities::m_delimiter = "|";
	bool Utilities::debug = false; //used for debugging reasons


	Utilities::Utilities()
	{
		m_widthField = 1u;

	}

	void Utilities::setFieldWidth(size_t size)
	{

		m_widthField = size;

	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	const std::string Utilities::extractToken(const std::string& line, size_t& cur_pos, bool& token_found)//extracts tokens from the first parameter
	{
		//Line = single line from file, cur_pos = the position past the characters already scanned, more = are we at the end of string?

		if (debug) {
			std::cout << std::endl << "-----Extract Token Called-----" << std::endl;
			std::cout << "Line : $" << line << "$" << std::endl;
			std::cout << "Current Pos : " << cur_pos << std::endl;
			std::cout << "token_found : " << token_found << std::endl << std::endl;
		}

		token_found = false; //Assume no token will be found until proven otherwise (Innocent until proven gulity)

		std::string token; //tmp string object that contains a line of text.  EX: "CPU,123456,5,Central Processing Unit" or "SSD|987654|5|Solid State Drive"
		size_t next_pos = 0;

		//step 1: Check if next_pos is a valid position in string
		if (line.length() > cur_pos) { //returns true if cur_pos is a valid position

				if (debug) std::cout << "step 1 : Cur_Pos is a valid position in Line" << std::endl;

			//Step 2: Find the index where the next delimiter is stored at
			next_pos = line.find(m_delimiter, cur_pos); 

				if (debug) std::cout << "Next_Pos : " << next_pos << std::endl;

	

			//Step 3: Store characters between cur_pos & next_pos a.k.a (characters between 2 delimiters)  
			//EX: "CPU,123456,5,Central Processing Unit" ---> 123456

					//if a 2nd delimiter does not exist a.k.a find returned string::npos then grab charactes between 1st delim and end of string (we assume we are at the end of the string)	
										// EX: "CPU,123456,5,Central Processing Unit" -----> Central Processing Unit

			token = line.substr(cur_pos, (next_pos != std::string::npos ? next_pos-cur_pos : line.length()));

				if (debug) std::cout << "Token : |" << token << "|" << std::endl;


		}

		if (!token.empty()) { 

			token_found = true; //if token is not an empty string then set token_found to true 

			if (next_pos != std::string::npos) {
				cur_pos = next_pos + 1; //change cur_pos to previous next_pos, (The +1 is to account for the delimiter's spot);
			}
			else {
				cur_pos = std::string::npos;
			}

						if (debug) std::cout << "cur_pos : " << cur_pos << std::endl;

			if (token.length() > m_widthField ) { //Check if m_widthField is smaller then token, if so then set width to token length

				m_widthField = token.length();

					if (debug)	std::cout << "m_widthField < token.length = True, new value =  " << token.length() << std::endl;
			}

												
		}
		else //if token is empty then throw a error
			throw "Extract Token Error: NO DATA FOUND BETWEEN DELIMIMTERS/END OF STRING";
			


		if (debug)	std::cout << "-----Extract Token ENDED-----" << std::endl << std::endl;

		return token; //return possible extracted token
	

	}


	void Utilities::setDelimiter(const char c)
	{

		m_delimiter = c;


	}

	const char Utilities::getDelimiter() const
	{
		return *m_delimiter.c_str();
	}




	Utilities::~Utilities()
	{
	}
