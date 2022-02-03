//*************************************************//
//
// Michal Kot-Kawula
// Seneca email: mkot-kawula@myseneca.ca
// Seneca Student ID: 128945193
// Date: 11/7/2021
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
//*************************************************//
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include"Car.h"

namespace sdds {
	class Racecar : public Car{
		double m_booster = 0.0;

	public:
		//calls the constructor from Car to build the subobject, and then it extracts the last field from the stream containing the booster bonus. 
		Racecar(std::istream& in);

		//calls Car::display() to print the information about the car, and adds * at the end.
		void display(std::ostream& out) const;

		//returns the top speed of the car, including any booster effects.
		double topSpeed() const;
	};
}

#endif