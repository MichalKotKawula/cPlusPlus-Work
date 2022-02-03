//*************************************************//
//
// Michal Kot-Kawula
// Seneca email: mkot-kawula@myseneca.ca
// Seneca Student ID: 128945193
// Date: 11/21/2021
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
//*************************************************//
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	//This function compares the elements in the two received lists for common product codes and builds the user-friendly list from the matching pairs.
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		
		for (size_t i = 0; i < desc.size(); i++){

		
			for (size_t b = 0; b < price.size(); b++){
		
				// For each successful comparison, your function allocates dynamic memory of Product type using that description and the price. 
				//Your function then validates the Product object and adds it to its list. Your function returns a copy of this list.
				if (desc[i].code == price[b].code){

					Product* my_point = new Product(desc[i].desc, price[b].price);				
					my_point->validate();
					priceList += my_point;
					delete my_point;
					my_point = nullptr;
				}

			}

		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++){

			for (size_t b = 0; b < price.size(); b++){

				//same logic as MergeRaw but smart pointers in use
				if (price[b].code == desc[i].code){
					std::unique_ptr<Product> uqPtr(new Product(desc[i].desc, price[b].price));
					uqPtr->validate();
					priceList += uqPtr;
				}
			}
		}

		return priceList;
	}
}