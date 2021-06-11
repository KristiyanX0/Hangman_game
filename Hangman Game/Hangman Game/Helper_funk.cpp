#include "Helper_funk.h"

void printHangman(unsigned short int x) {
	std::ifstream hanged_man;
	std::string str;
	hanged_man.open(std::to_string(x) + ".txt");
	while (getline(hanged_man, str, '\n'))
		std::cout << str << std::endl;
}

void to_up(char& x) {
	x = (x - 'a') + 'A';
}

void Press_anyKey_to_continue(const string& str) {
	std::cout << std::endl << str << std::endl;
	system("pause");
}

void UP_letter(char& g) {
	if ('a' <= g && g <= 'z')
		to_up(g);
	else if ('A' <= g && g <= 'Z') {}
	else
		throw "Invalid letter";
}

bool is_it_won(const string& str) {
	for (int i = 0; i < str.length(); ++i)
		if (str[i] == '_')
			return false;
	return true;
}

void reveal_Letter_by_index(string& str, string& word, unsigned int q) {
	char x = word[q];
	for (int i = 0; i < str.length(); ++i) {
		if (word[i] == x) {
			UP_letter(x);
			str[i] = x;
		}
	}
}

const unsigned int getword_count() {
	unsigned int x = 0;
	std::ifstream word_list;
	word_list.open("word_list.txt");
	string str;
	if (word_list.is_open())
		while (word_list >> str) { x++; }
	return x;
}
