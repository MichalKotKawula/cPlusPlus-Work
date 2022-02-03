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

#include "SongCollection.h"
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

	//a custom constructor that receives as a parameter the name of the file containing the information about the songs to be added to the collection.
	SongCollection::SongCollection(const char* song){

		auto trim = [](std::string remove){
	
			if ((!remove.empty() && !all_of(remove.begin(), remove.end(), isspace))){
		
				while (remove.at(0) == ' ')
					remove = remove.substr(1, remove.length() - 1);

				while (remove.at(remove.length() - 1) == ' ')
					remove = remove.substr(0, remove.length() - 1);
			}
			return remove;
		};

		std::string song_str = "";

		std::fstream s_song_txt;

		s_song_txt.open(song);

		if (!s_song_txt) {
			throw "File Cannot Be Opened!";
		}

		else
			while (std::getline(s_song_txt, song_str)){
				if (!song_str.empty()){

					Song sng;

					int passLeng = 0;

					sng.m_title = trim(song_str.substr(0, 24));
					sng.m_artist = trim(song_str.substr(24, 25));
					sng.m_album = trim(song_str.substr(50, 25));
					sng.m_releaseYear = trim(song_str.substr(75, 5));
					passLeng = stoi(trim(song_str.substr(80, 5)));
					sng.m_length = passLeng;
					sng.m_price = stod(trim(song_str.substr(85, 5)));
					s_collect.push_back(sng);
				}
			}
	}

	//print the content of the collection into the parameter(one song / line)
	void SongCollection::display(std::ostream& out) const{

		auto showSong = [&](const Song& s_music){
			out << s_music << std::endl;
		};

		auto time = [](int sum, const Song& songs){
			sum += songs.m_length;
			return sum;
		};

		int totalTime = std::accumulate(s_collect.begin(), s_collect.end(), 0, time);

		for_each(s_collect.begin(), s_collect.end(), showSong);

		int hrs = totalTime / 3600;

		totalTime = totalTime % 3600;
		int mins = totalTime / 60;

		totalTime = totalTime % 60;
		int secs = totalTime;

		out << "----------------------------------------------------------------------------------------\n";
		out << "|                                                        " << "Total Listening Time: " << hrs << ":" << mins << ":" << secs << " |" << std::endl;
	}


	//inserts one song into the first parameter
	std::ostream& operator<<(std::ostream& out, const Song& theSong){

		size_t songMin = theSong.m_length / 60;
		size_t songSec = theSong.m_length % 60;
 
		out << "| " << std::setw(20) << std::left << theSong.m_title << " | " << std::setw(15) << std::left << theSong.m_artist << " | " << std::setw(20) << std::left << theSong.m_album << " | " << std::setw(6) << std::right << theSong.m_releaseYear << " | " << songMin << ":";

		if (songSec < 10)
			out << "0" << songSec;
		else
		out << songSec;
		out << " | " << theSong.m_price << " |";
		return out;
	}

	//receives as a parameter the name of the field used to sort the collection of songs in ascending order. The parameter can have one of the values title, album, or length
	void SongCollection::sort(std::string pas){
	
		if (pas == "title"){
			std::sort(s_collect.begin(), s_collect.end(), [](const Song& first, const Song& second){	return first.m_title < second.m_title;	});
		}

		else if (pas == "album"){
			std::sort(s_collect.begin(), s_collect.end(), [](const Song& first, const Song& second){	return first.m_album < second.m_album;	});
		}
	
		else{
			std::sort(s_collect.begin(), s_collect.end(), [](const Song& first, const Song& second){	return first.m_length < second.m_length;	});
		}
	}

	//removes the token [None] from the album field of the songs that do not have a valid album. 
	void SongCollection::cleanAlbum(){

		auto cleanAlb = [](Song& alb){

			if (alb.m_album == "[None]"){	alb.m_album.clear();}
		};

		std::for_each(s_collect.begin(), s_collect.end(), cleanAlb);
	}

	//receives the name of an artist as a parameter, and returns true if the collection contains any song by that artist.
	bool SongCollection::inCollection(std::string artist) const{

		int holder = 0;

		auto artCheck = [&](const Song& collection){

			if (artist == collection.m_artist){	holder++;}
		};

		std::for_each(s_collect.begin(), s_collect.end(), artCheck);

		return holder;
	}

	//receives the name of an artist as a parameter, and returns the list of songs of that artist available in the collection. 
	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const{
		
		std::list<Song> songsInColl(s_collect.size());
	
		auto compare = [&](const Song& artistCmp){	return (artistCmp.m_artist == artist)	;};

		auto songs = std::copy_if(s_collect.begin(), s_collect.end(), songsInColl.begin(), compare);
		songsInColl.resize(std::distance(songsInColl.begin(), songs));
		return songsInColl;
	}
}