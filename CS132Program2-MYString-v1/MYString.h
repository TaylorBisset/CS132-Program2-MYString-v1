#ifndef MYSTRING_H
#define MYSTRING_H

#include <istream>

using namespace std;

class MYString {    // You NEED to change the name of the class to reflect your name 
	//   for example Nancy Programmer would use the name NPString 
public:
	MYString();						// default constructor
	MYString(const char* cstr);		// cstring constructor

	int length();
	int capacity();

	char at(int index);
	bool read(istream& inputStrm);
	void write(ostream& outputStrm);

	bool lessThan(const MYString& argStr);
	bool greaterThan(const MYString& argStr);
	bool equals(const MYString& argStr);

	void setEqualTo(const MYString& argStr);
	const char* c_str();

private:
	char* str;
	int end;
	int cap;
};

#endif
