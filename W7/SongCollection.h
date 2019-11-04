#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>

namespace sdds {


	struct Song {

		std::string m_artist;
		std::string m_title;
		std::string m_album;
		std::string m_release_year;

		double m_price;

		unsigned int m_song_length_mins;
		unsigned int m_song_length_secs;

		bool isEmpty;
		void setToEmpty();
		Song();
		Song(std::string& line);

	};
	class SongCollection {

		std::vector<Song*> Songs;
		
		void setToEmpty();

	public:
		SongCollection();
		SongCollection(std::istream& is);
		~SongCollection();
	public:

		void  display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const Song& theSong);

	};





}






#endif