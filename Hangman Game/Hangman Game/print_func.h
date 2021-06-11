#ifndef PRINT_FUNC
#define PRINT_FUNC
#include <iostream>
#include <string>
#include <fstream>
using std::string;

void print_cript(const string& cript);
void print_guessed_letters(const bool* guessed_letters);
void print_word_list(const unsigned int word_count);

#endif // !PRINT_FUNC