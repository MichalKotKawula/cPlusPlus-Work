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
#include <sstream>
#include <iomanip>
#include <vector>
#include "Car.h"

using namespace std;

namespace sdds{


	//a custom constructor that receives an object of type std::istream& as parameter. 
	Car::Car(std::istream& is){
		std::getline(is, c_maker, ',');
		c_maker = customTrim(c_maker);

		std::getline(is, c_condition, ',');
		c_condition = customTrim(c_condition);


		if (c_condition == "n" || c_condition == "N" || c_condition == "" || c_condition == " ")	{c_condition = "new";}
		
		else if (c_condition == "b" || c_condition == "B")	{c_condition = "broken";}

		else if (c_condition == "u" || c_condition == "U")	{c_condition = "used";}
		
		else	{throw string("Invalid record!");}

		string speed;
		std::getline(is, speed, ',');
		speed = customTrim(speed);
		try {
			c_topSpeed = std::stod(speed);
		}
		catch (...) {
			throw string("Invalid record!");
		}
	}

	//a query that returns new, used or broken, representing the condition of the car
	std::string Car::condition() const {return c_condition;}

	//returns top speed
	double Car::topSpeed() const{return c_topSpeed;}

	//a query that inserts in the first parameter the content of the car object in the format | MAKER | CONDITION | TOP_SPEED |
	void Car::display(std::ostream& out) const{
		out << "| ";
		out << setw(10) << right << c_maker << " | ";
		out << setw(6) << left << c_condition << " | ";
		out << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
	}

	//student defined function to help with word trimming
	std::string Car::customTrim(std::string str){
		str.erase(0, str.find_first_not_of("\n "));
		str.erase(str.find_last_not_of("\n ") + 1);
		return str;
	}



}