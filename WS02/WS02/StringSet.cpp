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
#include <iostream> 
#include <string>
#include <fstream>
#include "StringSet.h" 
using namespace std;

namespace sdds
{
	// a no-argument default constructor
	StringSet::StringSet(){
		dynamicString = nullptr;
		 numOfstrings = 0;
	}

	// a 1-argument constructor that receives the address of a C-style null terminated string
	StringSet::StringSet(const char* theString){

		dynamicString = nullptr;
		 numOfstrings = 0;
		unsigned int MyCount = 0;


		ifstream gutenShakespeare(theString);
		string myShakespeareLine;

		if (gutenShakespeare.good()){
			while (!gutenShakespeare.eof()){
				getline(gutenShakespeare, myShakespeareLine, ' ');
				 numOfstrings++;}

			dynamicString = new string[ numOfstrings];
			 numOfstrings++;

			 gutenShakespeare.clear();
			 gutenShakespeare.seekg(0);

			while (getline(gutenShakespeare, myShakespeareLine, ' ')){
				dynamicString[MyCount] = myShakespeareLine;
				MyCount++;
			}

			 numOfstrings--;
			 gutenShakespeare.close();
		}	}

	// destructor 
	StringSet::~StringSet() {delete[] dynamicString;}

	//  a query that returns the number of strings stored in the current object.
	size_t StringSet::size() const {return  numOfstrings;}

	// a query that returns a copy of the string at the index received as the function parameter.
	string StringSet::operator[](size_t mySize) const {

		if (dynamicString == nullptr || mySize > size() )
		{return "\0";}
		
		else {return dynamicString[mySize];}
	 
		
	}

	// copy constructor
	StringSet::StringSet(const StringSet& pass) {
		dynamicString = nullptr;
		*this = pass;
	}

	// copy assignment operator 
	StringSet& StringSet:: operator=(const StringSet& s)
	{
		if (this != &s) {

			delete[] dynamicString;
			numOfstrings = s.numOfstrings;

			dynamicString = new string[numOfstrings];

			for (int i = 0; i < numOfstrings; i++) {
				dynamicString[i] = s.dynamicString[i];
			}
		}
		return *this;
	}

	// move constructor 
	StringSet::StringSet(StringSet&& pass) noexcept {
		dynamicString = nullptr;
		 numOfstrings = 0;
		*this = std::move(pass);
	}


	// move assignment operator 
	StringSet& StringSet::operator=(StringSet&& pass) noexcept  {
		if (this != &pass){
		
			delete[] dynamicString;		
			dynamicString = pass.dynamicString;

			 numOfstrings = pass. numOfstrings;

			 pass. numOfstrings = 0;
			 pass.dynamicString = nullptr;
		}
		return *this;
	}
}