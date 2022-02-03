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
#include <iostream> 
#include <string> 
#include "TimedEvents.h" 

using namespace std;

namespace sdds
{
	// a default constructor
	TimedEvents::TimedEvents(){

		count[0].eventName = "";
		count[0].unitsOftime = "";
	}

	//  a modifier that starts the timer for an event
	void TimedEvents::startClock(){
		time_start = std::chrono::steady_clock::now();
	}

	// a modifier that stops the timer for an event
	void TimedEvents::stopClock(){
		time_end = std::chrono::steady_clock::now();
	}

	//  a modifier that receives the address of a C-style null-terminated string that holds the name of the event.
	void TimedEvents::addEvent(const char* name)
	{
		count[numRec].eventName = name;
		count[numRec].unitsOftime = "nanoseconds";
		count[numRec].durationOfEvent = std::chrono::duration_cast <std::chrono::nanoseconds>(time_end - time_start);
		numRec++;
	}

	// a friend insertion operator that receives a reference to an std::ostream object and a TimedEvents object.
	std::ostream& operator<<(std::ostream& os, TimedEvents& pass)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;

		for (int i = 0; i < pass.numRec; i++){
			os.setf(std::ios::left);
			os.width(21);
			os << pass.count[i].eventName << " ";
			os.setf(std::ios::right);
			os.width(13);
			os << pass.count[i].durationOfEvent.count() << " " << pass.count[i].unitsOftime << std::endl;
			os.unsetf(std::ios::right);
		}
		os << "--------------------------" << endl;
		return os;
	}
}