#ifndef REPL_H
#define REPL_H
#include "Helper_funk.h"
#include "regest_login.h"
#include "random_word.h"
#include "print_func.h"
#include "Ranklist.h"
#include <stdio.h>

using std::string;

class repl {
public:
	void run();
private:
	unsigned int v;
	unsigned int word_count = getword_count();
	bool guessed_letters[26];
	bool letters[26] = {false};

	void mark_containing_letters(const string& str);
	void cript_swap_letter(char l, string& cript, const string& word);

	void safeTo_file(const string&, const string& crtipted, const string& word, unsigned int v);
	void open_saved_game(const string& name);


	const string cript(const string& word);
	void addword(string& str);
	void analyse_command(string &command);
	void game(const string& name, unsigned v = 0, bool saved = true, string cripted = "", string word = "");
	void login_command(string& name, string& str);
	
	bool is_it_in(char x);
	
};

#endif // !REPL_H