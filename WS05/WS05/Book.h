
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string> 
#include <iostream>
#include <algorithm> 
#include <iomanip>

namespace sdds{

	class Book{
		// author
		std::string bookAuthor;

		//title
		std::string bookTitle;

		// the country of publication
		std::string bookCountry;

		// the year of publication
		size_t bookYear;

		// the price of the book
		double bookPrice;

		// a short summary of the book
		std::string bookDescription;

	public:

		// a default constructor 
		Book();

		//  a query that returns the title of the book
		const std::string& title() const;

		// a query that returns the publication country
		const std::string& country() const;

		// a query that returns the publication year
		const size_t& year() const;

		// a function that returns the price by reference, allowing the client code to update the price
		double& price();

		// trim function
		std::string trim(std::string s);

		// a constructor that receives a reference to an unmodifiable string that contains information about the book
		Book(const std::string& strBook);

		// overload the insertion operator to insert the content of a book object into an ostream object,
		friend std::ostream& operator<<(std::ostream& os, const Book& s);

		template <typename T>

		// this function calls the overloaded operator() on the instance spellChecker
		void fixSpelling(T &spellChecker)
		{
			spellChecker(bookDescription); 
		}
	};
}
#endif 
