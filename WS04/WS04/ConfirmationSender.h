
#ifndef SDDS_CONFIRMATION_SENDER_H
#define SDDS_CONFIRMATION_SENDER_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{

		// a dynamically allocated array of pointers to objects of type Reservation
		const Reservation** reservations{};

		//the size of array
		size_t mySize{};

	public:

		// a default constructor
		ConfirmationSender() {};

		// destructor
		~ConfirmationSender();

		//adds the reservation res to the array by adding its address.
		ConfirmationSender& operator+=(const Reservation& res);

		//removes the reservation res from the array by removing its address
		ConfirmationSender& operator-=(const Reservation& res);
		
		// copy constructor
		ConfirmationSender(const ConfirmationSender& src);
		
		//copy-assignment operator
		ConfirmationSender& operator=(const ConfirmationSender& src);
	
		// move constructor
		ConfirmationSender(ConfirmationSender&& src) noexcept;

		// move-assignment operator
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;

		//overload the insertion operator to insert the content of a ConfirmationSender object into an ostream object
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src);
	};
}
#endif