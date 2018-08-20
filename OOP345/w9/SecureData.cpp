// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "SecureData.h"

namespace w10 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") +
			std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		std::cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
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

	void SecureData::code(char key) {
		std::thread first(converter, text, key, nbytes, Cryptor());
		auto task2 = [&]() {encoded = !encoded; };
		std::thread second(task2);
		first.join();
		second.join();
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			// open binary file
			std::fstream ifs(file, std::ios::out);
			// write binary file here
			for (int i = 0; i < nbytes; i++)
			{
				ifs << text[i];
			}

		}
	}

	void SecureData::restore(const char* file, char key) {
		// open binary file
		std::fstream fs(file, std::ios::in);
		nbytes = 0;
		char temp;
		while (fs.good())
		{
			fs >> temp;
			nbytes++;
		}
		if (text)
		{
			delete[] text;
			text = nullptr;
		}
		text = new char[nbytes + 1];

		fs.clear();
		fs.seekg(0, std::ios::beg);
		nbytes--;
		for (int i = 0; i < nbytes; i++)
			{
				fs >> text[i];
			}
		text[nbytes + 1] = '\0';
		//// allocate memory here
		//nbytes = 0;
		//if (text)
		//{
		//	delete[] text;
		//	text = nullptr;
		//}
		//while (fs.get())
		//{
		//	nbytes++;
		//}
		//text = new char[nbytes + 1];

		//// read binary file here
		//nbytes--;
		//for (int i = 0; i < nbytes; i++)
		//{
		//	fs >> text[i];
		//}
		//text[nbytes + 1] = '\0';

		std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}