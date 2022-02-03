
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds
{
	class Reservation
	{
		//reservation id: an array of characters
		std::string reservationID{};

		//the name on the reservation
		std::string reservationName{};
		
		//the email to be used to send a confirmation that the reservation can be honored or cannot
		std::string reservationEmail{};

		//the number of people in the party
		size_t reservationSize{};

		//the day when the party expects to come 
		size_t reservationDay{};

		//the hour when the party expects to come
		size_t reservationHour{};

	public:
		//a default constructor
		Reservation() {};

		// a modifier that receives as parameters a new day and time for the reservation and updates the attributes with received values.
		void update(int day, int time);

		//a constructor that receives the reservation as a string; this constructor is responsible for extracting information about the reservation from the string and storing the tokens in the instance's attributes. 
		Reservation(const std::string& res);

		// overload the insertion operator to insert the contents of a reservation object into an ostream object
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

		// time result custom function added by student
		std::string timeResult() const;

		
	};

}
#endif 