
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-29s
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <functional>
#include "Car.h"


using namespace std;
namespace sdds {


	bool Car::debug = true;
	std::string Car::delim = ",";


	std::string Car::getDelim() const
	{
		return delim;

	}
	bool Car::isAnInt(std::string str) const { //Check if the string only has digits
		return (str.find_first_not_of("0123456789.") == std::string::npos);
		//true if the string only contains digits
	};
	void Car::Trim(std::string& str) {
		if (!str.empty()) {
			while (str.at(0) == ' ')
				str = str.substr(1, str.length() - 1);


			while (str.at(str.length() - 1) == ' ')
				str = str.substr(0, str.length() - 1);
		}
	}

	void Car::SetToSafeEmptyState()
	{


		if (debug) cout << "Car Object set to an empty safe state" << std::endl;

		m_condition = Empty_Safe_State;
		m_manufacture = "EMPTY_STATE";
		m_top_speed = 0;
		isEmpty = true; //car is in an empty state



	}

	

	Car::Car() //Set car object to an empty safe state
	{
		if (debug) cout << "Default Constructor Called on Car Object" << endl;

		SetToSafeEmptyState();

	}

	Car::Car(std::istream& is) //line of is : TAG,MAKER,CONDITION,TOP_SPEED
	{

		if (debug) cout << "----------Car (std::istream& is ) -----------------------------------" << endl;


		*this = Car(); //Set object to an empty safe state :)
		isEmpty = false; //Assume this constructor will produce a valid car until proven otherwise
						//A.k.a the safe empty state function is called.

		std::string line; //used for retriving line 
		std::string token;
		std::string delim(",");

		std::getline(is, line); //line of is : TAG,MAKER,CONDITION,TOP_SPEED
		
		unsigned int cur_pos = 0; //current position of cursor
		unsigned int next_delim_pos = 0; //Position of the next delimiter
		

		auto isConditionValid = [&](char& c) { //Check if char sent is a valid Car_Condition

			if (debug) {

				cout << "Condition char sent : " << c << endl;
				cout << "Possible conditions : " << " " << Brand_New << " " << Used << " " << " " << Broken << endl;
			}

			bool isValid = (c == Brand_New || c == Used || c == Broken);

			if (debug) cout << "Condition is " << (isValid ? "True" : "False") << endl;

			return isValid; //could of just done return (c==brand_new ...) but i wanted the debug statement
		};


		

		//Set car attributes :)
		// TAG,MAKER,CONDITION,TOP_SPEED

		if (debug) cout << "Line : " << line << endl;
		
	  for (int i = 0; i < 4 && isEmpty == false; ++i) {  //if the object goes into a safe empty state then stop the for loop

			next_delim_pos = line.find(delim, cur_pos);  //find delimiter
			token = line.substr(cur_pos, (next_delim_pos != string::npos ? next_delim_pos-cur_pos : line.length() )); //Grab a field from the line   line = TAG,MAKER,CONDITION,TOP_SPEED ---->   token = CONDITION
			
			if (i != 2) { //Trim isn't used for 
				Trim(token);

			}

			if (debug) {
				cout << "i : " << i << endl;
				cout << "isEmpty : " << (isEmpty ? "True" : "False") << endl << endl;
				cout << "Cursor position : " << cur_pos << endl;
				cout << "Next delim pos : " << next_delim_pos << endl;
				cout << "Token : " << token << endl;
			}

		
			switch (i) {


			case 0:  //Grab tag and do nothing  (TAG is used for utitlities class)
				if (debug) cout << "Tag Grabbed: " << token << endl;

			//	if (!(token[0] == 'c' || token[0] == 'C')) { //might cause issues check later
					//SetToSafeEmptyState();
				
				//}

				break;

			case 1:  //Set Manufacture 
				m_manufacture = token;
				if (debug) cout << "Manufacture : |" << m_manufacture << "|" << endl;
				break;
			case 2: //Set Condition

				if (token.find_first_not_of(' ') != std::string::npos) { //if token isn't just a bunch of spaces

					Trim(token);

					if (isConditionValid(token[0])) {
						m_condition = Car_Condition(token[0]);
						if (debug) cout << "Condition : |" << m_condition << "|" << endl;
					}

					else { //if condition is an invalid character


						throw std::string("Invalid record!");

					}
				}
				else { //if token is a bunch of spaces assume condition is new

					m_condition = Brand_New;

				}
					break;

				case 3: //setTopSpeed
					if (isAnInt(token)) {//if token contains only digits then convert it and set it to the top speed attribute
						m_top_speed = stol(token);

						if (debug) cout << "Top speed : " << m_top_speed << endl;

					}
					else { //if token is not a number throw error
						throw std::string("Invalid record!");
					}
					break;

			}

			cur_pos = next_delim_pos + 1; //set new cursor position
			
		
		}

	  if (debug) cout << "----------------Car (std::istream& is) ended------------------------------" << endl << endl;

	}

	Car::~Car()
	{
	}




	double Car::topSpeed() const
	{
		return m_top_speed;
	}

	void Car::display(std::ostream& os) const
	{
	
		os << "| ";

		os << std::right << std::setw(10) << m_manufacture;

		os << " | ";

		os << std::left << std::setw(6) << condition();

		os << " | ";

		os << std::setw(6) << std::setprecision(2) << std::fixed << m_top_speed;

		os << " |";

		os << endl;

	}

	std::string Car::condition() const //return condition
	{
		 
		std::string cond = "Safe Empty State"; //assume empty safe state in till proven otherwise

		if (m_condition == Car_Condition::Brand_New) {
			cond = "new";
		}
		else if (m_condition == Car_Condition::Used) {
			cond = "used";
		}
		else if (m_condition == Car_Condition::Broken) {
			cond = "broken";
		}

		return cond;

	}




}