#include <fstream>
#include <algorithm>
//#include <execution> //for parrell execution of stl algorithms

#include "LineManager.h"
#include "Utilities.h"



bool LineManager::debug = false;

void LineManager::setToEmpty()
{
	m_cntCustomerOrder = 0;
	firstTask = nullptr;
}

LineManager::LineManager()
{
	setToEmpty();
}

LineManager::LineManager(const std::string& AssemblyLine_File_Name, std::vector<Task*>& AssemblyLine_Task, std::vector<CustomerOrder>& cust_orders)
{
	Utilities extractor;
	std::string line;
	std::string tsk1;
	std::string tsk2;
	
	Task* cur_task;
	

	bool token_found = true;
	size_t cur_pos = 0;


	std::ifstream file(AssemblyLine_File_Name);

	setToEmpty();


	if (file.good()) {

		AssemblyLine.resize(AssemblyLine_Task.size());
		std::copy(std::execution::par, AssemblyLine_Task.begin(), AssemblyLine_Task.end(), AssemblyLine.begin());

		ToBeFilled.resize(cust_orders.size());
		std::move(std::execution::par, cust_orders.begin(), cust_orders.end(), ToBeFilled.begin());


		//std::reverse(ToBeFilled.begin(), ToBeFilled.end());
		m_cntCustomerOrder = ToBeFilled.size();
		
		if (debug) std::cout << "m_cntCustomerOrder : " << m_cntCustomerOrder << std::endl;

		while (std::getline(file, line)) {

			cur_pos = 0;
			token_found = true;

			while (cur_pos != std::string::npos) {

				
					tsk1 = extractor.extractToken(line, cur_pos, token_found);

					if (cur_pos != std::string::npos)
						tsk2 = extractor.extractToken(line, cur_pos, token_found);
			

				auto it1 = std::find_if(std::execution::par, AssemblyLine.begin(), AssemblyLine.end(), [&tsk1](const Task* task) {return task->getName().compare(tsk1) == 0; });
				auto it2 = std::find_if(std::execution::par, AssemblyLine.begin(), AssemblyLine.end(), [&tsk2](const Task* task) {return task->getName().compare(tsk2) == 0; });

				if (firstTask == nullptr && it1 != AssemblyLine.end()) { //if the first task in the assemblyline is not defined then define it
					firstTask = (*it1);
					if (debug) std::cout << "First Task : " << (*it1)->getName();
				}

				if (it1 != AssemblyLine.end() && it2 != AssemblyLine.end()) {
					(*it1)->setNextTask( *(*it2) );
				}
				tsk1.clear();
				tsk2.clear();


			}
		}

		//Find the last task ;)
		if (firstTask != nullptr) { 

			cur_task = firstTask;

			while (cur_task->getNextTask() != nullptr) {
				cur_task = cur_task->getNextTask();
			}

			lastTask = cur_task;

		}
		

	}
	else {
		setToEmpty();
	}


}

bool LineManager::run(std::ostream& os) //this may not work as intended edit later ):
{

	CustomerOrder tmp;
	bool cycleDone = false;
	Task* cur_task = firstTask;



	if (ToBeFilled.size() > 0) {

		*firstTask += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();

	}



	for (auto& obj : AssemblyLine) {
		//os << obj->getName() << std::endl;
		obj->runProcess(os);
	}

	
	do { //each loop iteration represnts a single task's cycle before moving onto the next task

		//cur_task->runProcess(os);

		if (cur_task->moveTask() == true) {

			if (cur_task->getComplete(tmp)) {

				if (!tmp.isEmpty()) {
					//os << tmp.display()
					Completed.push_back(std::move(tmp));
				}
			}
			
		}

	
		
		

		if (cur_task->getNextTask() != nullptr)
			cur_task = cur_task->getNextTask();
		else
			cycleDone = true;



	}
	while (cycleDone == false);




	//if (debug)
		//std::cout << "TASK AFTER WHILE LOOP, AKA LAST TASK : " << cur_task->getName() << std::endl;

	//Cur_Task should always be the final task at this point
	


	return Completed.size() == m_cntCustomerOrder;
	//firstTask->runProcess(os);
	//firstTask->moveTask();

}

void LineManager::displayCompleted(std::ostream& os) const
{

	std::for_each(Completed.begin(), Completed.end(), [&os](const CustomerOrder& cust_order) {
	
		cust_order.display(os);
	
	});
}

void LineManager::validateTasks() const
{

	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [](const Task* task) {

		task->validate(std::cout);

	});
}
