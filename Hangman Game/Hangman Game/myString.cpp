#include "myString.h"
#pragma warning(disable : 4996)

myString::myString() : text(nullptr) {
}


myString::myString(const char* text) {
	int length = strlen(text);
	this->text = new char[length + 1];
	strcpy(this->text, text);
	this->text[length] = '\0';
}

myString::myString(const myString& other) {
	copy_from(other);
}

myString::~myString() {
	free();
}

void myString::free() {
	if (text != nullptr)
		delete[] text;
}

void myString::copy_from(const myString& other) {
	int length = strlen(other.text);
	text = new char[length + 1];
	strcpy(text, other.text);
	text[length] = '\0';
}

myString& myString::operator=(const myString& other) {
	if (this != &other) {
		free();
		copy_from(other);
	}
	return *this;
}

char& myString::operator[](size_t t) {
	return text[t];
}

myString& myString::operator+=(const myString& other) {
	size_t length = strlen(text);
	char* text_copy = new char[length + 1];
	strcpy(text_copy, text);
	delete[] text;
	text_copy[length] = '\0';
	size_t other_len = length + strlen(other.text);
	text = new char[other_len + 1];
	strcpy(text, text_copy);
	strcat(text, other.text);
	text[other_len] = '\0';
	delete[] text_copy;
	return *this;
}

myString& myString::operator+=(const char other) {
	size_t length = strlen(text);
	char* text_copy = new char[length + 1];
	strcpy(text_copy, text);
	text_copy[length] = '\0';
	delete[] text;
	text = new char[length + 2];
	strcpy(text, text_copy);
	text[length] = other;
	text[length + 1] = '\0';
	delete[] text_copy;
	return *this;
}

myString& myString::operator*=(size_t scalar) {
	if (scalar > 0) {
		size_t j = strlen(text);
		char* copy_text = new char[j + 1];
		strcpy(copy_text, text);
		copy_text[j] = '\0';
		delete[] text;
		text = new char[scalar * j + 1];
		strcpy(text, copy_text);
		for (size_t i = 0; i < scalar - 1; i++)
			strcat(text, copy_text);
		text[scalar * j] = '\0';
		delete[] copy_text;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const myString& v) {
	int n = strlen(v.text);
	for (size_t i = 0; i < n; i++)
		os << v.text[i];
	return os;
}

std::istream& operator>>(std::istream& is, myString& str) {
	char* copy = new char[256];
	std::cin.getline(copy, 256);
	delete[] str.text;
	size_t t = strlen(copy);
	str.text = new char[t + 1];
	strcpy(str.text, copy);
	str.text[t] = '\0';
	delete[] copy;
	return is;
}

const myString operator+(const myString& lhs, const myString& rhs) {
	myString lhsCopy(lhs);
	lhsCopy += rhs;
	return lhsCopy;
}

const myString operator+(const myString& lhs, const char rhs) {
	myString lhsCopy(lhs);
	lhsCopy += rhs;
	return lhsCopy;
}

const myString operator*(const myString& lhs, size_t scalar) {
	myString copy(lhs);
	copy *= scalar;
	return copy;
}

bool operator>(const myString& lhs, const myString& rhs) {
	return lhs.size() > rhs.size();
}

bool operator<(const myString& lhs, const myString& rhs) {
	return lhs.size() < rhs.size();
}

bool operator<=(const myString& lhs, const myString& rhs) {
	return lhs.size() <= rhs.size();
}

bool operator>=(const myString& lhs, const myString& rhs) {
	return lhs.size() >= rhs.size();
}

bool operator==(const myString& lhs, const myString& rhs) {
	return lhs.size() == rhs.size();
}

bool operator!=(const myString& lhs, const myString& rhs) {
	return lhs.size() != rhs.size();
}

bool myString::is_substr(const char* text) const {
	return strstr(this->text, text);
}

myString myString::substr(size_t position1) const {
	return text + position1;
}

myString myString::substr(size_t position1, size_t position2) const {
	char* copy_text = new char[position2 - position1 + 1];
	for (size_t i = position1, j = 0; i < position2; i++, j++)
		copy_text[j] = text[i];
	myString newText(copy_text);
	delete[] copy_text;
	return newText;
}

const size_t myString::size() const {
	return strlen(text);
}

const char* myString::return_char_ptr() const {
	return text;
}