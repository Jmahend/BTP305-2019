// Name: Tai-Juan Rennie 
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/22/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_LVPAIR_H
#define _SDDS_LVPAIR_H


using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


namespace sdds {



	template<typename L, typename V>

	class LVPair {

		L m_key;
		V m_value;


	public:

		LVPair() : m_key{}, m_value{} { //initates values to a safe empty state

		}

		LVPair(const L& aa, const V& bb) { //Constructor for setting default values

			m_key = aa;
			m_value = bb;

		}

		const L& key() const {


			return m_key;

		}


		const V& value() const {


			return m_value;

		}

		virtual void display(std::ostream& os) const { //adds  "KEY : VALUE<endl>"  to ostream
			 
			
			os << m_key << " : " << m_value << std::endl;

		}

	};

	template<typename L, typename V> //<< operator that calls the display function
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {

		pair.display(os);
		return os;

	}


	template<typename L, typename V>

	class SummableLVPair : public LVPair<L, V> { //dervied class of LVPair that handles summation and formatted values for the display

		static V m_InitVal; // STATIC - Holds the inital vlue for starting a summation
		static size_t m_MinFieldWidth; // STATIC - size_T variable used for formatting. Updated every time a new pair is added
		

	public:
		SummableLVPair(){} //empty default constructor
	
		SummableLVPair(const L& lbl, const V& val) : sdds::LVPair<L, V>(lbl,val) //Constructor used to set member attributes
		{
				//m_InitVal = val;
			if (lbl.size() > m_MinFieldWidth) //check if lbl requires a larger field then the one already stated
				m_MinFieldWidth = lbl.size();

		}

	


		static const V& getInitialValue(){ //returns the initial value stored;
			return m_InitVal;
		}

		
		V sum(const L& lbl, const V& val) const {
		
			//If m_label matches param_lalebl then return the sum of param & member values else just return param_values
			return this->key() == lbl ? val + this->value() : this->value();

		}

		void display(std::ostream& os) const { //Function that formats the os to display LV values

			os << left << setw(m_MinFieldWidth);
			LVPair<L,V>::display(os);
			os << right;

		}

	};

	template<typename L, typename V> //self-explaintory
	size_t SummableLVPair<L,V>::m_MinFieldWidth = 0;



	template<>//Specialization(Expection) for when SummableLVPair object is <String,string>
	std::string SummableLVPair<std::string, std::string>::m_InitVal = "";

	//Specialization(Expection) for when SummableLVPair object is <String,int>
	template<>
	int SummableLVPair<std::string, int>::m_InitVal = 0;




	//Sum specialization for sum function.
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val) const {

	
		//If parameter's label matches class's label AND the param val sent is not in a safe empty state then return concated string : Else return empty string
		return lbl.compare(this->key()) == 0 && val.compare(m_InitVal) != 0 ? val + ", " + this->value() : this->value();


	}

}




#endif
