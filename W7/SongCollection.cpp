// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1
// Date of completion: 2019-11-05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iomanip>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include "SongCollection.h"



namespace sdds {

	bool Song::debug = false;

	void Song::setToEmpty()
	{

		m_artist = "Empty";
		m_title = "empty";
		m_album = "Empty";
		m_release_year = "empty";

		m_price = 0;
		m_song_length = 0u;
		isEmpty = true;

		if (debug) std::cout << "Song Object set to empty state" << std::endl;


	}

	Song::Song()
	{
		setToEmpty();
	}

	Song::Song(const std::string& line) : Song()
	{
		if (debug) std::cout << "----------- Song(str line) Constrcutor called ---------" << std::endl;

		std::string temp_song_length;
	
		
		auto trim = [](std::string str) {
			//if string is not empty or full of only spaces then trim
			if ((!str.empty() && !std::all_of(str.begin(), str.end(), isspace))) {

				while (str.at(0) == ' ')
					str = str.substr(1, str.length() - 1);


				while (str.at(str.length() - 1) == ' ')
					str = str.substr(0, str.length() - 1);
			}
			return str;
		};

		

		if (!line.empty() && line.length() >= 90) {
		

			m_title = trim((line.substr(0, 24)));
		
			m_artist = trim(line.substr(24, 25));
			m_album = trim(line.substr(50, 25));
			m_release_year = trim(line.substr(75, 5));
			m_song_length = stoul(trim(line.substr(80, 5)));
				
			

			try {
				m_price = stod(line.substr(85, 5));
			}
			catch (...) {
				throw "Price grabbed is not a number...";
			}



			
		}

		if (debug) {

			std::cout << "Song Title : |" << m_title << "|" << std::endl
				<< "Song Artist : |" << m_artist << "|" << std::endl
				<< "Song Release : |" << m_release_year << "|" << std::endl
				<< "Song Album : |" << m_album << "|" << std::endl
				<< "Temp_Song_Length : |" << temp_song_length << "|" << std::endl
				<< "m_price : |" << m_price << "|" << std::endl
				<<"----------- Song(str line) finished ---------" << std::endl << std::endl;

		}
	}

	std::ostream& operator<<(std::ostream& os, const Song& song)
	{

		auto SongPlaytime = [](int seconds) {

			std::string Time;
			int minutes;

			minutes = seconds / 60;
			
			Time = std::to_string(int(minutes % 60));
			Time+= ":";
			Time+= int(seconds % 60) < 10 ?  "0" + std::to_string(int(seconds % 60)) : std::to_string(int(seconds % 60));

			return Time;
		};
		
		os << "| ";

		os << std::left << std::setw(20) << song.m_title;

		os << " | ";

		os << std::left << std::setw(15) << song.m_artist;

		os << " | ";

		os << std::left << std::setw(20) << song.m_album;

		os << " | ";

		os << std::right << std::setw(6) << song.m_release_year;

		os << " | ";

		os << SongPlaytime(song.m_song_length);
		
		os << " | ";

		os << std::setprecision(2) << std::fixed << song.m_price;

		os << " |";

		return os;
	}

	SongCollection::SongCollection()
	{
		m_collection_length = 0;
	}

	SongCollection::SongCollection(const char* filename) : SongCollection()//
	{

		std::ifstream file(filename);
		std::string line; //stores a line of the file in a string format : 

		if (std::string(filename) == std::string("songs.txt")) {
			if (file.good()) {

				while (std::getline(file, line))// Line : Bird Set Free            Sia                      This Is Acting           2016 252  1.21

					if (!line.empty()) {
						Song tmp(line);
						m_Songs.push_back(tmp);
						m_collection_length += m_Songs.back().m_song_length;
					}
			}
		}
		else {
			throw std::string("Wrong file name : ") + filename;
		}

		file.close();
	}


	SongCollection::~SongCollection()
	{
		//for (auto& obj : m_Songs) //deallocate memory
			//delete obj;
	}

	void SongCollection::display(std::ostream& os) const
	{
		
		auto FormatTime = [](int seconds) {

			std::string Time;
			
			int hours = 0;
			int minutes = 0;

			minutes = seconds / 60;
			hours = minutes / 60;

			Time = std::to_string(hours);
			Time += ":";
			Time += int(minutes % 60) < 10 ?  std::string("0") + std::to_string(int(minutes % 60)) : std::to_string(int(minutes % 60));
			Time += ":";
			Time += int(seconds % 60) < 10 ? std::string("0") + std::to_string(int(seconds % 60)) : std::to_string(int(seconds % 60));


			return Time;
		
		};
		
		
		std::for_each(m_Songs.begin(), m_Songs.end(), [&](const Song song) { os << song << std::endl; });

		os << "----------------------------------------------------------------------------------------" << std::endl;

		os << "|";
		os << "                                                        Total Listening Time: ";

		os << FormatTime(std::accumulate(m_Songs.begin(), m_Songs.end(), 0, [](int sum, const Song song) { return song.m_song_length + sum;}));

		os << " |" << std::endl;

	
	}

	void SongCollection::sort(const char * field)
	{

		auto Compare = [field](Song song1, Song song2) {

			std::string _field(field);

			if (field == std::string("title"))
				return song1.m_title < song2.m_title;
			else if (_field == std::string("album"))
				return song1.m_album < song2.m_album;
			else if (_field == std::string("length"))
				return song1.m_song_length < song2.m_song_length;
			else
				throw "INVALID FIELD SENT TO SORT HOE";


		};

		std::sort(m_Songs.begin(), m_Songs.end(), Compare);
	}

	void SongCollection::cleanAlbum()
	{

		auto FindNone = [](Song& song) {

			if (song.m_album == std::string("[None]"))
				song.m_album.clear();

		};
		
		std::for_each(m_Songs.begin(), m_Songs.end(), FindNone);



	}

	bool SongCollection::inCollection(const char * artist) const
	{

		return std::any_of(m_Songs.begin(), m_Songs.end(), [artist](const Song& song) {return song.m_artist == std::string(artist); });

	}

	std::list<Song> SongCollection::getSongsForArtist(const char* artist) const
	{
		 std::list<Song> Artist_Collection(m_Songs.size());

		 auto it = std::copy_if(m_Songs.begin(), m_Songs.end(), Artist_Collection.begin(), [artist](const Song& song) {return song.m_artist == std::string(artist); });
		 Artist_Collection.resize(std::distance(Artist_Collection.begin(), it));
		 return Artist_Collection;
	}

}