#include "print_func.h"

void print_word_list(const unsigned int word_count) {
	std::ifstream file;
	file.open("word_list.txt");
	string str;
	if (file.is_open()) {
		for (int i = 0; i <= word_count; i++) {
			getline(file, str);
			std::cout << str << std::endl;
		}
	}
	file.close();
}

void print_cript(const string& cript) {
	for (unsigned int i = 0; i < cript.length(); i++)
		std::cout << " " << cript[i];
}

void print_guessed_letters(const bool* guessed_letters) {
	std::cout << "Used letters: ";
	for (unsigned short int i = 0; i < 26; i++)
		if (guessed_letters[i])
			std::cout << " " << char('A' + i);
}