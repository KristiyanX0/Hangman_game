#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <cstring>
#include <sstream>

class myString {
private:
	char* text;
	void free();
	void copy_from(const myString&);
public:
	myString();
	myString(const char*);
	myString(const myString&);
	myString& operator=(const myString&);
	~myString();

	const char* return_char_ptr() const;
	bool is_substr(const char*) const;
	myString substr(size_t) const;
	myString substr(size_t, size_t) const;
	const size_t size() const;

	char& operator[](size_t);
	myString& operator+=(const myString& other);
	myString& operator+=(const char other);
	myString& operator*=(size_t scalar);

	friend std::ostream& operator<<(std::ostream& os, const myString& v);
	friend std::istream& operator>>(std::istream& is, myString& v);
};

const myString operator+(const myString& lhs, const myString& rhs);
const myString operator+(const myString& lhs, const char rhs);
const myString operator*(const myString& lhs, size_t scalar);

bool operator>(const myString& lhs, const myString& rhs);
bool operator<(const myString& lhs, const myString& rhs);
bool operator<=(const myString& lhs, const myString& rhs);
bool operator>=(const myString& lhs, const myString& rhs);
bool operator==(const myString& lhs, const myString& rhs);
bool operator!=(const myString& lhs, const myString& rhs);

#endif // !_MYSTRING_H