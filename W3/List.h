// Name: Tai-Juan Rennie 
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/22/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_LIST_H
#define SDDS_LIST_H

#include <iostream>



using namespace std;

namespace sdds {



	template<typename  T, unsigned int N>
	class List
	{


		T m_array[N];
		size_t m_array_size;
		const size_t m_Max_Size;



	public:


		List() : m_Max_Size(N) {
			m_array_size = 0u;
		}

		size_t size() const {  //Returns number of elements in the List's m_array

			return m_array_size;

		};


		const T& operator[](int i) const { //Returns element at m_array[i]

			return m_array[i];

		};


		void operator+=(const T& tt) { //: if the list didn't reach the capacity, add a copy of the parameter to the array. Otherwise, do nothing.


			if (m_array_size < m_Max_Size) {

				m_array[m_array_size] = tt;
				m_array_size++;

			}

		}






	};
	 
	//L = type of label, V  = type of summation value, T = type of any element in the collection, N = max num of elements in collection
	template<typename L, typename V, typename T, unsigned int N>
	class LVList : public List<T, N> {

		//No new member attributes

	public:
		V accumulate(const L& label) const { // this function accumulates all the values stored in the list that have the label label into a local object of type V
			
			//temp Holder variable
			V local_label = T::getInitialValue(); //Grabs initialValue to allow for proper initialization
			//std::cout << "test: " << local_label << std::endl;

			for (unsigned int i = 0u; i < this->size(); ++i) {  //change back to size() after

				if (label == (*this)[i].key()) //Check if m_label matches parameter's label
				//	std::cout << "Labels Matching (" << label << " = " << 
					local_label = (*this)[i].sum(label, local_label); //Concat values to holder
	
			}

			return local_label;

		}



	};


}


#endif

