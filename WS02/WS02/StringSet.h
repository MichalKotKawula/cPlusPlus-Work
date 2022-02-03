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
#ifndef _SDDS_STRINGSET_H
#define _SDDS_STRINGSET_H
#include <iostream>
#include <string> 

namespace sdds
{

	class StringSet
	{
		// dynamically allocated array 
		std::string* dynamicString;

		// number of strings currently stored 
		int numOfstrings;

	public:
		// a no-argument default constructor
		StringSet();

		// destructor 
		~StringSet();

		// a 1-argument constructor that receives the address of a C-style null terminated string
		StringSet(const char*);

		//  a query that returns the number of strings stored in the current object.
		size_t size() const;
		
		// a query that returns a copy of the string at the index received as the function parameter.
		std::string operator [] (size_t) const;

		// copy constructor
		StringSet(const StringSet&);

		// copy assignment operator 
		StringSet& operator=(const StringSet&);




		// move constructor 
		StringSet(StringSet&&)noexcept;

		// move assignment operator  
		StringSet& operator=(StringSet&&)noexcept;
	};
}
#endif