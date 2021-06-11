#ifndef HELPER_FUNK_H
#define HELPER_FUNK_H
#include <iostream>
#include <string>
#include <fstream>

using std::string;

void printHangman(unsigned short int x);
void to_up(char& x);
void Press_anyKey_to_continue(const string& str);
void UP_letter(char& g);
bool is_it_won(const string& str);
void reveal_Letter_by_index(string& str, string& word, unsigned int q);
const unsigned int getword_count();

#endif // _HELPER_FUNK_H
