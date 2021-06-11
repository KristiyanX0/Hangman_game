#include "repl.h"

void repl::run() {
	string str;
	analyse_command(str);
}

void repl::analyse_command(string &str) {
	while (true)
	{
		std::cout << "Enter your profile:" << std::endl;
		std::cin >> str;
		UserInfo user;
		if (str[0] == '$') {
			std::cin >> str;
			if (str == "register") {
				std::cin >> user.user_name;
				std::cin >> user.email;
				std::cin >> user.password;
				if (!regest_login_system::is_it_registered(user)) {
					regest_login_system::regest(user);
					Press_anyKey_to_continue("[ Successful registration! ]");
					Ranklist::add_to_ranklist(user);
				}
				else
					Press_anyKey_to_continue("[ This user already exists! ]");
			}
			else if (str == "login") {
				std::cin >> user.user_name;
				std::cin >> user.password;
				if (regest_login_system::login(user)) {
					Press_anyKey_to_continue("[ Successful login! ]");
					while (str != "logout") {
						system("cls");
						std::cout << "Enter a command:" << std::endl;
						std::cin >> str;
						if (str == "$") {
							std::cin >> str;
							if (str == "logout")
								break;
							login_command(user.user_name, str);
						}
						else
							Press_anyKey_to_continue("Invalid command!");
					}
				}
				else
					Press_anyKey_to_continue("[ Wrong username or password! ]");
			}
			else if (str == "forgotpass") {
				std::cin >> user.user_name;
				std::cin >> user.email;
				if (regest_login_system::forgot_pass(user.user_name, user.email)) {
					std::cout << "Enter new password: ";
					std::cin >> user.password;
					regest_login_system::change_password(user);
				}
				else
					Press_anyKey_to_continue("[ That's, not " + user.user_name + "'s email! ]");
			}
			else if (str == "exit")
				std::exit(0);
			else
				Press_anyKey_to_continue("Invalid command!");
		}
		else
			Press_anyKey_to_continue("Invalid command!");
		system("cls");
	}
}

void repl::login_command(string &name, string &str) {
	if (str == "addword") {
		std::cin >> str;
		addword(str);
		Press_anyKey_to_continue("[ You successfully added a new word! ]");
	}
	else if (str == "exit")
		std::exit(0);
	else if (str == "printword") {
		Print::print_word_list(word_count);
		Press_anyKey_to_continue("[ The list has " + std::to_string(word_count) + " words! ]");
	}
	else if (str == "ranklist") {
		Ranklist::ranklist_print();
		Press_anyKey_to_continue(" ");
	}
	else if (str == "playSaved")
		open_saved_game(name);
	else if (str == "playNew")
		game(name);
	else
		Press_anyKey_to_continue("Invalid command!");
}

void repl::game(const string& name, unsigned v, bool saved, string cripted, string word) {
	system("CLS");
	char g;
	if (saved) {
		word = randomWord::random_word(word_count);
		mark_containing_letters(word);
		cripted = cript(word);
		reveal_Letter_by_index(cripted, word, 0);
	}
	bool guessed_letters[26] = { false };
	while (true) {
		if (is_it_won(cripted)) {
			Press_anyKey_to_continue("[ GOOD JOB! ]");
			Press_anyKey_to_continue("[ You guessed the word " + word + " ]");
			Ranklist::ranklist(name);
			break;
		}
		Print::print_cript(cripted);	std::cout << std::endl << std::endl;
		printHangman(v);	std::cout << std::endl;
		Print::print_guessed_letters(guessed_letters);		std::cout << std::endl;
		std::cout << "Guess letter -> ";	std::cin >> g;
		if (g == '#') {
			safeTo_file(name, cripted, word, v);
			break;
		}
		std::cout << std::endl;
		UP_letter(g);
		guessed_letters[g - 'A'] = true;
		if (is_it_in(g)) {
			cript_swap_letter(g, cripted, word);
		}
		else {
			if (++v == 10) {
				std::cout << std::endl << "Sorry, you struck out" << std::endl;
				Press_anyKey_to_continue("The word is: " + word);
				break;
			}
		}
		system("CLS");
	}
}

void repl::addword(string& str) {
	std::ofstream word;
	word.open("word_list.txt", std::ios::app);
	for (int i = 0; i < str.length(); ++i)
		UP_letter(str[i]);
	word << str << std::endl;
	word.close();
	word_count = getword_count();
}

const string repl::cript(const string& word) {
	string cript_word;
	unsigned int len = word.length();
	for (unsigned int i = 0; i < len; i++)
		cript_word += "_";
	return cript_word;
}

void repl::cript_swap_letter(char l, string& cript, const string& word) {
	unsigned int len = word.length();
	for (unsigned int i = 0; i < len; i++)
		if (word[i] == l)
			cript[i] = l;
}

void repl::mark_containing_letters(const string& str) {
	for (int i = 0; i < str.length(); i++)
		letters[str[i] - 'A'] = true;
}

bool repl::is_it_in(char x) {
	return letters[x - 'A'];
}

void repl::safeTo_file(const string& name, const string& cripted, const string& word, unsigned int v) {
	unsigned int p = 0;
	for (int i = 0; i < word.length(); i++)
		p += word[i];
	std::ofstream file_save;
	file_save.open(name + std::to_string(p) + ".txt", std::ios::binary);
	p = cripted.length();
	file_save.write((char*)&p, sizeof(int));
	file_save.write(&cripted[0], p);

	p = word.length();
	file_save.write((char*)&p, sizeof(int));
	file_save.write(&word[0], p);

	file_save.write((char*)&v, sizeof(int));
	file_save.close();
}

void repl::open_saved_game(const string& name) {
	string cripted = "";
	string word = "";
	unsigned int v = 0;

	std::ifstream file_save;
	string str;
	std::cin >> str;
	size_t size;
	file_save.open(str + ".txt");

	file_save.read((char*)&size, sizeof(int));
	cripted.resize(size);
	file_save.read(&cripted[0], size);

	file_save.read((char*)&size, sizeof(int));
	word.resize(size);
	file_save.read(&word[0], size);

	file_save.read((char*)&v, sizeof(int));
	game(name, v, false, cripted, word);
	file_save.close();
}