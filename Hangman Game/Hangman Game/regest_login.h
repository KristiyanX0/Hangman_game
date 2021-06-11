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

void input_UserInfo(string& name, string& password, string& emails);
bool forgot_pass(string user_name, string email);
bool is_it_registered(const UserInfo& user);
void regest(const UserInfo& user);
bool login(const UserInfo& user);
void change_password(const UserInfo& user);

#endif // _REGEST_LOGIN_