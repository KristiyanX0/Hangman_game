#ifndef PRINT_FUNC
#define PRINT_FUNC
#include <iostream>
#include <string>
#include <fstream>
using std::string;

class Print {
public:
	static void print_cript(const string& cript);
	static void print_guessed_letters(const bool* guessed_letters);
	static void print_word_list(const unsigned int word_count);
};
#endif // !PRINT_FUNC