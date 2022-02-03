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
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include"Vehicle.h"

namespace sdds{
	class Car : public Vehicle{
		std::string c_maker;
		std::string c_condition;
		double c_topSpeed;

	public:
		//a custom constructor that receives an object of type std::istream& as parameter. 
		Car(std::istream& is);

		//a query that returns new, used or broken, representing the condition of the car
		std::string condition() const;

		//returns top speed
		double topSpeed() const;

		//a query that inserts in the first parameter the content of the car object in the format | MAKER | CONDITION | TOP_SPEED |
		void display(std::ostream& out) const;

		//student defined function to help with word trimming
		std::string customTrim(std::string str); 
	};
}

#endif