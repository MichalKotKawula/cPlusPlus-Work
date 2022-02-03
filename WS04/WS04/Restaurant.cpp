
#include <iomanip>
#include <iostream>
#include "Restaurant.h"
using namespace std;

namespace sdds
{
	//a constructor that receives as a parameter an array of pointers to objects of type Reservation
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
		myCount = cnt;
		resReso = new Reservation[myCount];
		for (auto i = 0u; i < myCount; ++i){
			resReso[i] = *reservations[i];
		}
	}

	// copy constructor
	Restaurant::Restaurant(const Restaurant& src){
		resReso = nullptr;
		myCount = 0;
		*this = src;
	}

	// copy-assignment operator
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			myCount = src.myCount;
			delete[] resReso;
			resReso = new Reservation[myCount];
			for (auto i = 0u; i <myCount; ++i) {
				resReso[i] = src.resReso[i];
			}
		}
		return *this;
	}

	// move constructor
	Restaurant::Restaurant(Restaurant&& src) noexcept{
		resReso = nullptr;
		myCount = 0;
		*this = std::move(src);
	}

	
	// move-assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept{
		if (this != &src){
			myCount = src.myCount;
			delete[] resReso;
			resReso = src.resReso;	
			src.resReso = nullptr;
			src.myCount = 0;
		}
		return *this;
	}

	//a query that returns the number of reservations in the system.
	size_t Restaurant::size() const {return myCount;}

	// destructor
	Restaurant::~Restaurant()	{delete[] resReso;}

	// inserts the content of a Restaurnt object into an ostream object
	std::ostream& operator<<(std::ostream& os, const Restaurant& res){
		static size_t numCount = 0;
		++numCount;
		auto size = res.size();

		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << numCount << ")" << std::endl;
		os << "--------------------------" << std::endl;

		if (size == 0){
			os << "This restaurant is empty!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		else{
			for (auto i = 0u; i < size; ++i){
				os << res.resReso[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}
}