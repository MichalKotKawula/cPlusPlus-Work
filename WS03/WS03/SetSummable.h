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
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <iostream>
#include"Set.h"


namespace sdds
{
	template<unsigned int N, typename T >

	// deriving class template 
	class SetSummable : public Set< N, T>{

	public:
		//this query accumulates into a local object of type T the subset of all the elements in the collection that satisfy filter.
		T accumulate(const std::string& filter) const;
	};

	template<unsigned int N, typename T >
	T SetSummable<N, T>::accumulate(const std::string& filter) const {
		T localT(filter);
		int mySize = this->size();
		for (auto i = 0; i <= mySize; ++i) {
	
			if (this->get(i).isCompatibleWith(localT)) {
				localT += this->get(i);
			}
		}
		return localT;
	}
}
#endif