#ifndef TASK_H
#define TASK_H

#include <deque>
#include <string>
#include <iostream>
#include "CustomerOrder.h"
#include "Item.h"



class Task : public Item {

	std::deque<CustomerOrder> m_orders;
	Task * m_pNextTask;
	static bool debug; //for debugging reasons
	bool m_multipleItemsToBeFilled;

	static bool m_multipleItemsJustFilled;

	void setToEmpty();
public:

	Task(const Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;
	Task& operator=(const Task&) = delete;
	

	Task();
	Task(const std::string line);
	

	void runProcess(std::ostream& os);
	bool moveTask();

	Task* getNextTask();
	void setNextTask(Task& task);
	bool getComplete(CustomerOrder& cust_order);
	void validate(std::ostream& os) const;

	Task& operator+=(CustomerOrder&& cust_order);


};



#endif