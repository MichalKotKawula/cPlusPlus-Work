

#include <string>
#include <iomanip>
#include "Reservation.h"
using namespace std;


namespace sdds
{
	//a constructor that receives the reservation as a string; this constructor is responsible for extracting information about the reservation from the string and storing the tokens in the instance's attributes. 
	sdds::Reservation::Reservation(const std::string& res){
	
		std::string temp = res;
		size_t tempIdx = 0u;

		// Reservation ID
		temp.erase(0, temp.find_first_not_of(' '));
		tempIdx = temp.find(':');
		reservationID = temp.substr(0, tempIdx);
		reservationID.erase(reservationID.find_last_not_of(' ') + 1);
		temp.erase(0, tempIdx + 1);

		// Reservation Name
		temp.erase(0, temp.find_first_not_of(' '));
		tempIdx = temp.find(',');
		reservationName = temp.substr(0, tempIdx);
		reservationName.erase(reservationName.find_last_not_of(' ') + 1);
		temp.erase(0, tempIdx + 1);

		// Reservation Email
		temp.erase(0, temp.find_first_not_of(' '));
		tempIdx = temp.find(',');
		reservationEmail = temp.substr(0, tempIdx);
		reservationEmail.erase(reservationEmail.find_last_not_of(' ') + 1);
		temp.erase(0, tempIdx + 1);

		// Reservation Part Size
		temp.erase(0, temp.find_first_not_of(' '));
		tempIdx = temp.find(',');
		reservationSize = std::stoi(temp.substr(0, tempIdx));
		temp.erase(0, tempIdx + 1);

		// Reservation Day
		temp.erase(0, temp.find_first_not_of(' '));
		tempIdx = temp.find(',');
		reservationDay = std::stoi(temp.substr(0, tempIdx));
		temp.erase(0, tempIdx + 1);

		// Reservation Hour
		temp.erase(0, temp.find_first_not_of(' '));
		tempIdx = temp.find(',');
		reservationHour = std::stoi(temp.substr(0, tempIdx));
		temp.erase(0, tempIdx + 1);
	}

	// a modifier that receives as parameters a new day and time for the reservation and updates the attributes with received values.
	void Reservation::update(int day, int time){
		this->reservationDay = day;
		this->reservationHour = time;
	}

	// time result custom function added by student returns a string depending on time of the day
	 std::string Reservation::timeResult() const{

		std::string resoType{};
		if (reservationHour >= 6 && reservationHour <= 9)
		{resoType = "Breakfast";}

		else if (reservationHour >= 11 && reservationHour <= 15)
		{resoType = "Lunch";}

		else if (reservationHour >= 17 && reservationHour <= 21)
		{resoType = "Dinner";}

		else {resoType = "Drinks";}

		return resoType;
	}

	// insertion operator to insert the contents of a reservation object into an ostream object
	std::ostream& operator<<(std::ostream& os, const Reservation& res){
		os << "Reservation " << std::setw(10) << std::right << res.reservationID << ":   ";
		os << std::setw(20) << res.reservationName + "  ";
		os << std::setw(20) << std::left << "<" + res.reservationEmail + ">" << "    ";
		os << res.timeResult() << " on day " << res.reservationDay << " @ ";
		os << res.reservationHour << ":00 for ";
		os << res.reservationSize << ((res.reservationSize == 1) ? " person." : " people.") << std::endl;
			
		return os;
	}

}