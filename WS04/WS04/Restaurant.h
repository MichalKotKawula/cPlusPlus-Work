
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{

		//a dynamically allocated array of objects of type Reservation
		Reservation* resReso{};

		//the size of array
		size_t myCount{};

	public:

		//a default constructor
		Restaurant() {};

		//a constructor that receives as a parameter an array of pointers to objects of type Reservation
		Restaurant(const Reservation* reservations[], size_t cnt);

		//overload the insertion operator to insert the content of a Restaurant object into an ostream object.
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest);

		//a query that returns the number of reservations in the system.
		size_t size() const;

		//destructor
		~Restaurant();

		// copy constructor
		Restaurant(const Restaurant& src);

		// copy-assignment operator
		Restaurant& operator=(const Restaurant& src);

		// move constructor
		Restaurant(Restaurant&& src) noexcept;

		// move-assignment operator
		Restaurant& operator=(Restaurant&& src) noexcept;	
	};
}

#endif