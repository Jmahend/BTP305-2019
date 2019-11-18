#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include "CustomerOrder.h"
#include "Task.h"



class LineManager {

	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	
	Task* firstTask;
	Task* lastTask;
	static bool debug;
	unsigned int m_cntCustomerOrder;

	void setToEmpty();

public:

	LineManager();
	LineManager(const std::string& AssemblyLine_File_Name, std::vector<Task*>& AssemblyLine_Task, std::vector<CustomerOrder>& cust_orders);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;




};





#endif