// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 10/24/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>



	class Utilities
	{
		size_t m_widthField; //specifying the length of the token extracted; used for display purpose later; default value is
		static std::string m_delimiter; //separates the tokens from a given std::string. All Utilities objects share the same delimiter.
		static bool debug; //used for debugging reasons

	public:

		Utilities();
		~Utilities();

		void setFieldWidth(size_t num); // sets the field width of the current object to the value of the parameter
		size_t getFieldWidth() const; //returns the field width of the current object
		const std::string extractToken(const std::string& line, size_t& cur_pos, bool& more); //extracts tokens from the first parameter
		static void setDelimiter(const char delim); //sets the delimiter for this class to the character received
		const char getDelimiter() const; //returns the delimiter character of the current object.

	};




#endif


