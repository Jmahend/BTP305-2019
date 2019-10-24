
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 2019-10-01
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"
namespace sdds {






	int ConfirmationSender::findRes(const Reservation& res) const
	{
		
		int index = -1; //assume res does not exist

		for (auto i = 0u; i < m_size; ++i) {  
			
			if (res == Reservation(*m_reservations[i])) { //if Res does exist in array then set index & stop for loop

				index = i;
				break; //stop for loop

			}

		}
		
		return index;
	}

	ConfirmationSender::ConfirmationSender()
	{
		m_reservations = nullptr;
		m_size = 0u;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = ConfirmationSender();

		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{

		*this = ConfirmationSender();

		*this = std::move(src);


	}

	ConfirmationSender::~ConfirmationSender()
	{

		m_reservations = nullptr;
		m_size = 0u;

	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		
		if (this != &src) {
			m_reservations = new Reservation const* [src.m_size];

			for (auto i = 0u; i < (src.m_size); ++i)  //copy over old info to tmp obj
				m_reservations[i] = src.m_reservations[i];

			m_size = src.m_size;

		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src) {

			m_reservations = src.m_reservations;
			src.m_reservations = nullptr;
			
			m_size = src.m_size;
			src.m_size = 0;

		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{

		//search array for function
		int index = findRes(res);
		const Reservation** tmp = nullptr;



		if (index == -1) { //if  the res does not exist in obj then 

			tmp = new Reservation const* [m_size + 1]; //allocate memory for new res

			for (auto i = 0u; i < m_size; ++i)  //copy over old info to tmp obj
				tmp[i] = m_reservations[i];


			tmp[m_size] =  &res; //dereference
			m_size++; //increase size to reflect change;

			m_reservations = tmp; //transfer over address
			tmp = nullptr; //untether address from tmp

		}


		return *this;

	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int index = findRes(res);
		const Reservation** tmp = nullptr;


		if (index != -1) { // if res exist in object

			//step 1: Position found res obj at the end of array so it doesn't get moved over
			if (index != static_cast<int>(m_size - 1u)) { //if res is not the final obj in array then

				//swap indexed res with final res obj
				m_reservations[index] = nullptr;

				m_reservations[index] = m_reservations[m_size - 1];

				//m_reservations[m_size - 1] = tmp2;

				//tmp2 = nullptr;

			}


			//step 2: move over everything but the final obj in the m_array(index obj)
			tmp = new Reservation const* [m_size - 1u]; //allocate memory for new array
			
			for (auto i = 0u; i < (m_size-1u); ++i)  //copy over old info to tmp obj
				tmp[i] = m_reservations[i];


			m_reservations = tmp; //transfer over addresss
			m_size--;

			tmp = nullptr; //untether tmp to address 
			
		}

		return *this;



	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
	{


		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		
		if (src.m_size != 0) {
			for (auto i = 0u; i < src.m_size; ++i)
				os << *src.m_reservations[i];
		}
		else {
			os << "The object is empty!" << std::endl;
		}

		os << "--------------------------" << std::endl;

		return os;
	}

}