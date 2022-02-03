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
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds {

	template< typename V, typename K>

	class Pair {

		//the type of the value
		V typeValue;

		//the type of the key
		K typeKey;

	public:

		//default constructor
		Pair() : typeValue{}, typeKey{}{}

		//copies the values referred to by the parameters into the instance variables
		Pair(const K& key, const V& value) {
			typeValue = value;
			typeKey = key;
		}

		//returns the value component of the pair
		const V& value() const	 {return typeValue;}

		//returns the key component of the pair
		const K& key() const	 {return typeKey;}

		//inserts into stream os the key and the value of the pair in the following format
		virtual void display(std::ostream& os) const {
			os << typeKey << " : " << typeValue << std::endl;
		}
	};


	//calls the member function display() on pair to insert a pair into stream os.
	template <typename V, typename K>

	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}
#endif 
