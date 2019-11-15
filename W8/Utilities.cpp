// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172	
// Seneca email: trennie1@myseneca.ca	
// Date of completion: 2019-11-12
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include <algorithm>

#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		Product* tmp = nullptr;
		for (auto i = 0u; i < desc.size(); ++i)
			for(auto j = 0u; j< price.size(); ++j)
				if (desc[i].code == price[j].code) {
					tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += (tmp);
					
					delete tmp;
					tmp = nullptr;
				}

		return priceList;
	}
}