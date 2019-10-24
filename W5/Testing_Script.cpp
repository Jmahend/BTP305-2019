#include "Book.h"

using namespace sdds;

int main(void) {


	std::cout << "TEST" << std::endl;
	std::string tmp = "Miguel de Cervantes, Don Quixote, Spain, 9.99, 1612, The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.";
		Book test(tmp);


	std::cout << test  << std::endl;
		return 0;

}