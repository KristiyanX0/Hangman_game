#ifndef _REGEST_LOGIN_
#define _REGEST_LOGIN_
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#define MAX_SIZE_PASS_NAME 30
using std::string;

struct UserInfo {
	string user_name;
	string password = "";
	string email = ""; 
	int score = 0;
};

class regest_login_system {
public:
	static void input_UserInfo(string& name, string& password, string& emails);
	static bool forgot_pass(string user_name, string email);
	static bool is_it_registered(const UserInfo& user);
	static void regest(const UserInfo& user);
	static bool login(const UserInfo& user);
	static void change_password(const UserInfo& user);
};
#endif // _REGEST_LOGIN_