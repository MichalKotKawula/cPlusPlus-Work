
#include "Book.h"
using namespace std;


namespace sdds
{
	// default constructor 
	Book::Book(){
		bookAuthor = "";
		bookTitle = "";
		bookCountry = "";
		bookPrice = 0.0;
		bookDescription = "";
		bookYear = 0;
	
	}

	// return title of book (query)
	const std::string& Book::title() const{return bookTitle;}

	// return country of where book was published (query)
	const std::string& Book::country() const{return bookCountry;}

	// return which year book was published (query)
	const size_t& Book::year() const{return bookYear;}

	// return price by reference  
	double& Book::price(){return bookPrice;}

	// trim function
	std::string Book::trim(std::string s)	{
		while (s.front() == ' '){
			s = s.substr(1, s.length() - 1);
		}

		while (s.back() == ' '){
			s = s.substr(0, s.length() - 1);
		}
		return s;
	}

	// constructor that receives a reference to an unmodifiable string 
	Book::Book(const std::string& strBook){

		std::string temp = strBook;

		// author 
		bookAuthor = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		// title 
		bookTitle = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		// country  
		bookCountry = trim(temp.substr(0, temp.find(",")));
		temp.erase(0, temp.find_first_of(",") + 1);

		// price 
		bookPrice = stod(trim(temp.substr(0, temp.find(","))));
		temp.erase(0, temp.find_first_of(",") + 1);

		// year 
		bookYear = stoi(trim(temp.substr(0, temp.find(","))));
		temp.erase(0, temp.find_first_of(",") + 1);

		// description 
		bookDescription = trim(temp);
	}

	// friend insertion operator 
	std::ostream& operator<<(std::ostream& os, const Book& src)
	{
		os << setw(20) << src.bookAuthor << " | " << setw(22) << src.bookTitle << " | " << setw(5) << src.bookCountry << " | " << setw(4) << src.bookYear << " | " << setw(6) << fixed << setprecision(2) << src.bookPrice << " | " << src.bookDescription << endl;
		return os;
	}
}
