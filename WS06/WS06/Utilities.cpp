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
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds{
	
	//This function should extract data from the parameter; if the first non-blank character is c or C, 
	//this function should dynamically create an instance of type Car passing the stream to the constructor, and return it to the client.
	Vehicle* createInstance(std::istream& in){
		std::string n;
		std::getline(in, n);

		std::stringstream obj(n);
		string c_type;		
		std::getline(obj, c_type, ',');
		
		c_type.erase(0, c_type.find_first_not_of("\n "));
		c_type.erase(c_type.find_last_not_of("\n ") + 1);

		if (c_type == "c" || c_type == "C")		{return new Car(obj);}

		else if (c_type == "r" || c_type == "R")	{return new Racecar(obj);}

		else if (c_type == "")	 {return nullptr;}

		else{
			std::string strr = "Unrecognized record type: [" + c_type + "]";
			throw strr;
		}

	}
}