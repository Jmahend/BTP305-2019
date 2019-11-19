// Workshop 9 - Multi-Threading
// SecureData.cpp

// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2019
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include "SecureData.h"


using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO: rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
	
		
		//auto opposite = [&](bool ec) { ec = !ec; };  //This doesn't work for some reason... idk why

		auto convert = std::bind(converter, text, key, nbytes, Cryptor());


		std::thread t1(convert);
		std::thread t2([this]() { encoded = !encoded; });

	;
		t1.join();
		t2.join();

		//encoded = !encoded;
	

	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			ofstream _file(file, std::ios::binary);

			if (!_file.is_open()) {
				throw std::string("\n***Failed to open file***\n");
			}
			else {
				// TODO: write data into the binary file
				//         and close the file

				for (size_t i = 0U; i <= strlen(text); ++i) {
					_file << text[i];
				}
				_file.close();

			}


			


		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		ifstream _file(file, std::ios::binary);


		// TODO: - allocate memory here for the file content
		std::vector<char> file_contents;


		// TODO: - read the content of the binary file
		while (_file.good()) {
			file_contents.push_back(_file.get());
		}


		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
