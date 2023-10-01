#ifndef TBSTRING_H
#define TBSTRING_H

#include <istream>

using namespace std;

class TBString 
{    // You NEED to change the name of the class to reflect your name 
					//   for example Nancy Programmer would use the name NPString 
public:
	TBString();						// default constructor
	TBString(const char* cstr);		// cstring constructor

	int length();
	int capacity();

	char at(int index);
	bool read(istream& inputStrm);
	void write(ostream& outputStrm);

	bool lessThan(const TBString& argStr);
	bool greaterThan(const TBString& argStr);
	bool equals(const TBString& argStr);

	void setEqualTo(const TBString& argStr);
	const char* c_str();

private:
	int compareTo(const char* lstr, const char* rstr)
	{
		if (lstr < rstr)
		{
			return -1;
		}
		else if (lstr > rstr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	char* str;
	int end;
	int cap;
};

#endif
