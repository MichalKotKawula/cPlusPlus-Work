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
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iomanip>
#include <iostream>
#include"Pair.h"


namespace sdds
{
	template<typename V, typename K>

	// deriving class template 
	class PairSummable : public Pair<V, K>{
		
		//the type of the value
		static V initialValue ;

		//the type of the key
		static size_t minimWidth ;

	public:

		// default consturctor 
		PairSummable() {}

		// calls the base class constructor passing the two parameters to it, and updates the field width if necessary.
		PairSummable(  const K& key, const V& value = initialValue) : Pair<V, K>(key, value){
			if (minimWidth < key.size())  {minimWidth = key.size();}
		}

		//returns true if the parameter has the same key as the current object, false otherwise.
		bool isCompatibleWith(const PairSummable<V, K>& b) const {

			if (this != &b && this->key() == b.key())  {return true;}
			else  {return false;}

		}

		// receive a reference to an unmodifiable PairSummable object. This function adds the value of the parameter object to the value of the current object and returns a reference to the current object.
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& src){

				*this = PairSummable(this->key(), this->value() + src.value());

			return *this;
		}

		// query to set the alignment to left and the field width to the value of the static attribute
		void display(std::ostream& os) const{
			os << std::left <<std::setw(minimWidth);
			this->Pair<V, K>::display(os);
			os << std::right;
		}
	};

	//Specializations

	template<typename V, typename K>
	V PairSummable<V, K>::initialValue{};

	template<typename V, typename K>
	size_t PairSummable<V, K>::minimWidth{};

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src){

			if (value() == "") {*this = PairSummable(this->key(), this->value() + src.value());}

			else {*this = PairSummable(this->key(), this->value() + ", " + src.value());}

		return *this;

	}
}
#endif