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
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include"Vehicle.h"


namespace sdds{
	class Autoshop{
		
		std::vector<Vehicle*> m_vehicles;

	public:
		//adds the vehicle received as parameter into the m_vehicles vector.
		Autoshop& operator +=(Vehicle* theVehicle);

		// iterates over the vehicles stored in m_vehicles and prints them into the parameter
		void display(std::ostream& out) const;

		//destructor
		~Autoshop();

		//a template function that iterates over the vehicles stored in the m_vehicles, and adds to the second parameter all vehicles for which the test is true. 
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles){
			for (const auto& vehicle : this->m_vehicles){
				if (test(vehicle)){
					vehicles.push_back(vehicle);
				}
			}
		}
	};

}

#endif