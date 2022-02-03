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
#include <iomanip>
#include "Vehicle.h"

using namespace std;

namespace sdds{
	//This function should extract data from the parameter; if the first non-blank character is c or C, 
	//this function should dynamically create an instance of type Car passing the stream to the constructor, and return it to the client.
	Vehicle* createInstance(std::istream& in);
}