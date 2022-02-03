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
#include "Autoshop.h"

using namespace std;

namespace sdds{

	//adds the vehicle received as parameter into the m_vehicles vector.
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle){
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	// iterates over the vehicles stored in m_vehicles and prints them into the parameter
	void Autoshop::display(std::ostream& out) const{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";

		for (const auto& vehicle : this->m_vehicles){
			vehicle->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
	//destructor
	Autoshop::~Autoshop(){
		for (const auto& vehicle : this->m_vehicles) {
			delete vehicle;
		}
	}
}