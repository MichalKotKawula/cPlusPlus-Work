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
#include <iostream>
#include <string>
#include "Racecar.h"
#include "Car.h"


namespace sdds {

	Racecar::Racecar(std::istream& in) : Car::Car(in) {

		std::string field{};
		std::getline(in, field, '\n');

		try{
			this->m_booster = std::stod(field);
		}
		catch (const std::invalid_argument&){}

	}


	void Racecar::display(std::ostream& out) const{
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const{
		return (1 + this->m_booster) * Car::topSpeed();
	}
}