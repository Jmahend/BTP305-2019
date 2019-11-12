// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


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
		for (auto i = 0; i < desc.size(); ++i)
			for(auto j = 0; j< price.size(); ++j)
				if (desc[i].code == price[j].code) {
					tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += (tmp);
					
					tmp = nullptr;
				}

		return priceList;
	}
}