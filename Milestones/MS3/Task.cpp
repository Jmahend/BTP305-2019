#include <numeric>
#include "Task.h"


bool Task::debug = false; //for debugging reasons
bool Task::m_multipleItemsJustFilled = false;

void Task::setToEmpty()
{
	m_multipleItemsToBeFilled = false;
	m_pNextTask = nullptr;
	if (debug) std::cout << "Task set to empty state" << std::endl;
}

Task::Task(const std::string line) : Item(line)
{
	setToEmpty();
}

void Task::runProcess(std::ostream& os)
{


	if (m_orders.size() > 0) { //if we have customer orders in queue

		//If there are multiple items to be filled then hold off on filling them to the next cycle... Why cornel?????

		//this statement can be simplified but do it later
	

			//then grab the last customer order in the queue and check it's item fillstate using this task(item's) name
			while (m_orders.back().getItemFillState(Item::getName()) == false) {

				//Check if there are multiple items
				m_orders.back().fillItem(*this, os); //if fillstate is false then fill that that item in the customers order
				

			}




		}
	

	

}

bool Task::moveTask()
{
	if (m_orders.size() > 0) {

		if (m_orders.back().getItemFillState(Item::getName()) == true) {

			if (m_pNextTask != nullptr) {

				*m_pNextTask += std::move(m_orders.back());
				m_orders.pop_back();

			}

		}
	}

	return !(m_orders.size() == 0); //if Task queue is empty return false

}

 Task* Task::getNextTask()
{
	return m_pNextTask;
}

void Task::setNextTask(Task& task)
{
	
		m_pNextTask = &task;
	
}

bool Task::getComplete(CustomerOrder& cust_order)
{

	bool filled = false;

	if (m_orders.size() != 0) {

		if (m_orders.back().getOrderFillState() == true) {
			cust_order = std::move(m_orders.back());
			m_orders.pop_back();
			filled = true;
		}
	}
	
	return filled;
}

void Task::validate(std::ostream& os) const
{


	os << Item::getName() << " --> " << (m_pNextTask == nullptr ? "END OF LINE" :  m_pNextTask->getName()) << std::endl;

}

Task& Task::operator+=(CustomerOrder&& cust_order)
{
	m_orders.push_front(std::move(cust_order));
	return *this;
}

