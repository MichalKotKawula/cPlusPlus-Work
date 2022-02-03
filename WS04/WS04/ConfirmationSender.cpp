
#include <iostream>
#include "ConfirmationSender.h"
using namespace std;


namespace sdds
{

	//destructor
	ConfirmationSender::~ConfirmationSender() {delete[] reservations;}

	// copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {*this = src;}

	//copy-assignment operator
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src) {
			mySize = src.mySize;
			delete[] reservations;
			reservations = new const Reservation * [mySize];
			for (size_t i = 0; i < mySize; ++i) {
				reservations[i] = src.reservations[i];
			}
		}
		return *this;
	}

	// move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept {*this = std::move(src);}

	// move-assignment operator
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept{
		if (this != &src){
			mySize = src.mySize;
			delete[] reservations;
			reservations = src.reservations;
			src.mySize = 0;
			src.reservations = nullptr;
		}
		return *this;
	}

	// removes the reservation res from the array by skipping copying it into resized
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {

		bool found = false;
		for (auto i = 0u; i < mySize && !found; ++i) {
			found = (reservations[i] == &res);
		}

		if (found) {

			const Reservation** resized = new const Reservation * [mySize - 1];
			auto myCounter = 0;
			for (auto i = 0u; i < mySize; ++i) {
				if (reservations[i] != &res) {
					resized[myCounter] = reservations[i];
					++myCounter;
				}
			}
			delete[] reservations;
			reservations = resized;
			--mySize;
		}
		return *this;
	}

	//adds the reservation res to the array by adding its address.
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
		bool found = false;
		for (auto i = 0u; i < mySize && !found; ++i){
			found = (reservations[i] == &res);
		}

		if (!found){
		
			const Reservation** resized = new const Reservation * [mySize + 1];

			for (auto i = 0u; i < mySize; ++i){
				resized[i] = reservations[i];
			}
			
			delete[] reservations;
			reservations = resized;
			reservations[mySize] = &res;
			++mySize;
		}
		return *this;
	}

	// inserts the content of a ConfirmationSender into an ostream object
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src){
			os << "--------------------------" << std::endl;
			os << "Confirmations to Send" << std::endl;
			os << "--------------------------" << std::endl;
		
		if (src.mySize == 0){
			os << "There are no confirmations to send!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		else{
			for (auto i = 0u; i < src.mySize; ++i){
				os << *src.reservations[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

}