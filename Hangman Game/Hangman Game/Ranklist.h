#ifndef RANKLIST_H
#define RANKLIST_H

#include "regest_login.h"
#include <iostream>
#include <string>
#include <fstream>
class Ranklist {
public:
	static void ranklist_print();
	static void ranklist(const string& name);
	static void add_to_ranklist(const UserInfo& user);
};

#endif // !RANKLIST_H