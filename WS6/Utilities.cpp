// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-29s
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <sstream>
#include <string>
#include "Car.h"
#include "Racecar.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	

	Vehicle* createInstance(std::istream& is)
	{
		
		bool debug = false; //used for debugging

		auto Trim = [](std::string& str) { //remove spaces at the end
			while (str.at(0) == ' ')
				str = str.substr(1, str.length() - 1);


			while (str.at(str.length() - 1) == ' ')
				str = str.substr(0, str.length() - 1);
		};


		std::string line;

		stringstream sstream;
		Vehicle* tmp = nullptr;

		getline(is, line);

		if (debug) cout << "----Utilities createInstance--------" << endl << "line : " << line << endl << "------------------------------------------------" << endl << endl;

		if (!line.empty()) {

			Trim(line); //remove spaces from ends

			sstream << line; //insert line to sstream


			if (sstream.str().at(0) == 'c' || sstream.str().at(0) == 'C') {

			
				tmp = new Car(sstream);

			}
			else if (sstream.str().at(0) == 'r' || sstream.str().at(0) == 'R') {

				tmp = new Racecar(sstream);

			}
			else {
				throw std::string("Unrecognized record type: [") + sstream.str().at(0) + "]";
			}


		}
		

			
		return tmp;


	}

}