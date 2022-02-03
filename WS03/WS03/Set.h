//*************************************************//
//
// Michal Kot-Kawula
// Seneca email: mkot-kawula@myseneca.ca
// Seneca Student ID: 128945193
// Date: 10/3/2021
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
//*************************************************//
#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {

template < int N, class T>

class Set {

	T templArr[N];
	size_t currentNumElem = 0;

public:
	//returns the current number of elements in the collection
	size_t size() const {return currentNumElem;}

	//returns a reference to the element at index idx of the statically allocated array (assume that the parameter is valid).
	const T& get(size_t idx) const	 {return templArr[idx];}

	// if the collection has capacity for another element, adds a copy of item to the collection. Otherwise, does nothing.
	void operator+=(const T& item) {

		if (currentNumElem < N) {
			templArr[currentNumElem] = item;
			currentNumElem++;
		}
		}
};
}
#endif 