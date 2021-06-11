#include "random_word.h"

unsigned int randomWord::random_num(unsigned int word_count) {
	srand(time(NULL));
	return rand() % word_count;
}

const string randomWord::random_word(unsigned int word_count) {
	std::ifstream guessed_word;
	guessed_word.open("word_list.txt");
	unsigned int random_N = randomWord::random_num(word_count);
	string str;
	if (guessed_word.is_open()) {
		for (int i = 0; i <= random_N; i++)
			getline(guessed_word, str);
	}
	guessed_word.close();
	return str;
}