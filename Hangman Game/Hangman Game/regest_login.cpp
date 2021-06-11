#include "regest_login.h"

bool is_it_registered(const UserInfo& user) {
	string pass;
	std::ifstream user_info_read;
	user_info_read.open(user.user_name + ".txt");
	user_info_read >> pass;
	user_info_read.close();
	if (pass.length() == 0)
		return false;
	return pass == user.password;
}

void regest(const UserInfo& user) {
	std::ofstream user_info_write;
	user_info_write.open(user.user_name + ".txt");
	user_info_write << user.password << std::endl;
	user_info_write << user.email << std::endl;
	user_info_write.close();
}

bool login(const UserInfo& user) {
	string pass;
	std::ifstream user_info_read;
	user_info_read.open(user.user_name + ".txt");
	user_info_read >> pass;
	user_info_read.close();
	return pass == user.password;
}

void change_password(const UserInfo& user) {
	std::ofstream file;
	file.open(user.user_name + ".txt");
	file << user.password << std::endl;
	file << user.email << std::endl;
	file.close();
}

bool forgot_pass(string user_name, string email) {
	std::ifstream user_info_read;
	string pass;
	string real_email;
	user_info_read.open(user_name + ".txt", std::ios::in);
	user_info_read >> pass;
	user_info_read >> real_email;
	user_info_read.close();
	return real_email == email;
}

void input_UserInfo(string& name, string& password, string& email) {
	std::cin >> name;
	std::cin >> password;
	std::cin >> email;
}

/*void input_UserInfo() {
	std::cin >> user.user_name;
	std::cin >> user.password;
	std::cin >> user.email;
}*/