//*************************************************//
//
// Michal Kot-Kawula
// Seneca email: mkot-kawula@myseneca.ca
// Seneca Student ID: 128945193
// Date: 9/26/2021
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
//*************************************************//
#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H
#include <iostream> 
#include <chrono> 


namespace sdds{

	// maximum number of objects 
	const int maxObj = 10;


	class TimedEvents{

		// the number of records currently stored
		int numRec = 0;

		// the start time for the current event
		std::chrono::time_point<std::chrono::steady_clock> time_start;
		// the end time for the current event
		std::chrono::time_point<std::chrono::steady_clock> time_end;

		// an array of Events of structure type
		struct{
			// a string with the event name.
			std::string eventName;

			// a string with the predefined units of time
			std::string unitsOftime;

			// the duration of the event
			std::chrono::steady_clock::duration durationOfEvent;

		} count[maxObj]; 

	public:
		// a default constructor
		TimedEvents();

		//  a modifier that starts the timer for an event
		void startClock();

		// a modifier that stops the timer for an event
		void stopClock();

		//  a modifier that receives the address of a C-style null-terminated string that holds the name of the event.
		void addEvent(const char*);

		// a friend insertion operator that receives a reference to an std::ostream object and a TimedEvents object.
		friend std::ostream& operator<<(std::ostream&, TimedEvents&);
	};
}
#endif