//*************************************************//
//
// Michal Kot-Kawula
// Seneca email: mkot-kawula@myseneca.ca
// Seneca Student ID: 128945193
// Date: 11/14/2021
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
//*************************************************//
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <numeric>

namespace sdds{

	struct Song{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_releaseYear;
		int m_length;
	};

	class SongCollection{

		std::vector<Song> s_collect;

	public:

		//a custom constructor that receives as a parameter the name of the file containing the information about the songs to be added to the collection.
		SongCollection(const char* song);

		//print the content of the collection into the parameter(one song / line)
		void display(std::ostream& out) const;

		//receives as a parameter the name of the field used to sort the collection of songs in ascending order. The parameter can have one of the values title, album, or length
		void sort(std::string s);

		//removes the token [None] from the album field of the songs that do not have a valid album. 
		void cleanAlbum();

		//receives the name of an artist as a parameter, and returns true if the collection contains any song by that artist.
		bool inCollection(std::string n_artist) const;

		//receives the name of an artist as a parameter, and returns the list of songs of that artist available in the collection. 
		std::list<Song> getSongsForArtist(std::string n_artist) const;
	};

	//inserts one song into the first parameter
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif 