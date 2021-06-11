#include "Ranklist.h"

void Ranklist::add_to_ranklist(const UserInfo& user) {
	std::ofstream file;;
	file.open("ranklist.txt", std::ios::app | std::ios::binary);
	unsigned int size = user.user_name.length();
	file.write((char*)&size, sizeof(int));
	file.write(&user.user_name[0], size);
	file.write((char*)&user.score, sizeof(int));
	file.close();
}

void Ranklist::ranklist(const string& name) {
	string str;
	unsigned int i = 0;
	//	std::ofstream file_names;
	//	file_names.open("ranklist.txt");
	std::ifstream file;
	std::ofstream file_swap;
	file.open("ranklist.txt", std::ios::binary);
	file_swap.open("ranklist_swap.txt", std::ios::binary);
	if (!file.is_open() || !file_swap.is_open())
		std::cerr << "Error opening files!" << std::endl;

	string strTemp;
	unsigned int x;
	size_t size;

	while (file.read((char*)&size, sizeof(int))) {
		strTemp.resize(size);
		file.read(&strTemp[0], size);
		file.read((char*)&x, sizeof(unsigned int));

		if (strTemp == name)
			++x;

		file_swap.write((char*)&size, sizeof(int));
		file_swap.write(&strTemp[0], size);
		file_swap.write((char*)&x, sizeof(unsigned int));
	}

	file.close();
	file_swap.close();

	std::ofstream file1;
	std::ifstream file_swap1;
	file1.open("ranklist.txt", std::ios::binary);
	file_swap1.open("ranklist_swap.txt", std::ios::binary);

	while (file_swap1.read((char*)&size, sizeof(int))) {
		strTemp.resize(size);
		file_swap1.read(&strTemp[0], size);
		file_swap1.read((char*)&x, sizeof(unsigned int));

		file1.write((char*)&size, sizeof(int));
		file1.write(&strTemp[0], size);
		file1.write((char*)&x, sizeof(unsigned int));
	}
}

void Ranklist::ranklist_print() {
	std::ifstream file;
	file.open("ranklist.txt", std::ios::binary);
	string str;
	unsigned int x;
	size_t size;
	while (file.read((char*)&size, sizeof(int))) {
		str.resize(size);
		file.read(&str[0], size);

		file.read((char*)&x, sizeof(unsigned int));
		std::cout << str << " " << x << std::endl;
	}
	file.close();
}