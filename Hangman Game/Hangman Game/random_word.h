#ifndef RANDOM_WORD
#define RANDOM_WORD
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
using std::string;

class randomWord {
public:
	static unsigned int random_num(unsigned int word_count);
	static const string random_word(unsigned int word_count);
};
#endif // !RANDOM_WORD