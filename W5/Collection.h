#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 2019-10-17
//
// I confirm that the content of this file is created by me,
//with the exception of the parts provided to me by my professor.

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

namespace sdds {
	

	template< class T>
	class Collection {

		std::string m_name;
		T* m_collection;

		size_t m_size;

		void (*func)(const Collection<T>&, const T&);


		void AddItem(const T& item) {


			if (m_collection) {
				//std::cout << "m_collection is NOT a nullptr" << std::endl;
				//std::cout << "m_col Size: " << m_size << std::endl;

				T* tmp = new T[m_size + 1];


				for (auto i = 0u; i < m_size; i++) {
					tmp[i] = T( m_collection[i]);
				}
				
				delete[] m_collection;
				m_collection = tmp;
				tmp = nullptr;

				m_collection[m_size] = item;

				m_size++;

			}
			else {
				//std::cout << "m_collection IS a nullptr" << std::endl;

				m_collection = new T[1];

				//std::cout << "New T Created :)" << std::endl;
				m_collection[0] = item;
				//std::cout << "New Item finally added :)" << std::endl;
				m_size = 1;

			}




		}

	public:
		~Collection() {

		}


		Collection() {

			m_name = "Empty";
			m_collection = nullptr;
			m_size = 0u;
			func = nullptr;
		}


		int findItem(const std::string& Title) const {

			int index = -1;

			for (auto i = 0u; i < m_size; ++i) {

				if (m_collection[i].title().compare(Title) == 0) {
					index = i;
					break;
				}
			}

			return index;


		}


		Collection(const Collection& src) = delete;  //copy constructor
		Collection& operator=(const Collection& src) = delete; //copy operator

		Collection(std::string name) {	

			m_name = name;
			m_size = 0u;
			func = nullptr;
			m_collection = nullptr;
			
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>& col, const T& item)) {
			func = observer;
		}

		const std::string& name() const {
			return m_name;
		}

		Collection& operator+=(const T& item) {

			//std::cout << "Collection operator+= : " << std::endl;

			int index = findItem(item.title());

		


			if (index == -1) {
				//std::cout << "unique item being added" << std::endl;
				AddItem(item);
				
				if (func != nullptr) {
					func(*this, item);
				}

			}

			return *this;

		}


		T& operator[](size_t index) const {

			//T& tmp;
			std::string msg;
			msg = "Bad index [" + std::to_string(index) + "]. Collection has [" + std::to_string(m_size) + "] items.";

			if (index > (m_size-1u)) {
				throw std::out_of_range(msg);
			}

			return m_collection[index];
		}


		T* operator[](std::string title)  {

			int index = findItem(title);
			 T* tmp = nullptr;


			return index != -1 ? &m_collection[index] : tmp;

		}

		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& col) {
		


			for (auto i = 0u; i <col.m_size; ++i){
			
				os << col.m_collection[i];
			
			}

			return os;
		
		}

	};


	
}

#endif