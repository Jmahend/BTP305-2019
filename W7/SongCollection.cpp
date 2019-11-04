#include <iomanip>

#include "SongCollection.h"


namespace sdds {



	void Song::setToEmpty()
	{
		m_artist = "Empty";
		m_title = "empty";
		m_album = "Empty";
		m_release_year = "empty";

		m_price = 0;
		m_song_length_mins = 0;
		m_song_length_secs = 0;
		isEmpty = true;

	}

	Song::Song()
	{
		setToEmpty();
	}

	Song::Song(std::string& line) : Song()
	{

		if (!line.empty() && line.length >= 90) {
			std::string temp_song_length;
			std::string temp_price;

			m_title = line.substr(0, 25);
			m_artist = line.substr(25, 50);
			m_album = line.substr(50, 75);
			m_release_year = line.substr(75, 80);

			temp_song_length = line.substr(80, 85);
			temp_price = line.substr(85, 90);
		}
	}

	std::ostream& operator<<(std::ostream& os, const Song& song)
	{
		
		os << "| ";

		os << std::right << std::setw(20) << song.m_title;

		os << " | ";

		os << std::left << std::setw(15) << song.m_artist;

		os << " | ";

		os << std::left << std::setw(20) << song.m_album;

		os << " | ";

		os << std::left << std::setw(6) << song.m_release_year;

		os << " |";

		os << std::setw(6) << std::setprecision(2) << std::fixed << m_top_speed;

		os << " |";


	}

	void SongCollection::display(std::ostream& os) const
	{


		d
	}

}