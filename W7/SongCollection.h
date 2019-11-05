#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <list>
namespace sdds {


	struct Song {

		std::string m_artist;
		std::string m_title;
		std::string m_album;
		std::string m_release_year;

		double m_price;

		unsigned int m_song_length;


		static bool debug;
		
		bool isEmpty;
		void setToEmpty();
		Song();
		Song(const std::string& line);

	};
	class SongCollection {

		std::vector<Song> m_Songs;
		unsigned int m_collection_length;

	public:
		SongCollection();
		SongCollection(const char * filename);
		~SongCollection();
	public:

		void  display(std::ostream& os) const;
		void sort(const char *);
		void cleanAlbum();
		bool inCollection(const char * artist) const;
		std::list<Song> getSongsForArtist(const char * artist) const;
	};
	std::ostream& operator<<(std::ostream& os, const Song& theSong);





}






#endif