#include "MYString.h"

MYString::MYString() {
	cap = 20;
	end = 0;
	str = new char[cap];
	str[end] = '\0';
}

MYString::MYString(const char* cstr) {
	for (end = 0; cstr[end] != '\0'; ++end);
	//empty loop

	cap = 20;						//TODO: needs to potentially grow for prog3
	str = new char[cap];

	for (int i = 0; i <= end; ++i) {
		str[i] = cstr[i];
	}
}

int MYString::length() {
	return end;
}

int MYString::capacity() {
	return cap;
}

char MYString::at(int index) {
	if (index >= 0 && index < end) {
		return str[index];
	}
	else {
		return '\0';
	}
}

bool MYString::read(istream& inputStrm) {
	char inputWord[100];
	if (inputStrm >> inputWord) {
		for (end = 0; inputWord[end] != '\0'; ++end);  			//empty loop

		// cap = ??;						//TODO: needs to potentially grow for prog3

		for (int i = 0; i <= end; ++i) {
			str[i] = inputWord[i];
		}
		return true;
	}
	else
		return false;
}

void MYString::write(ostream& outputStrm) {
	outputStrm << str;
}

bool MYString::lessThan(const MYString& argStr) {
	// TODO: you need to write.
	return false;
}

bool MYString::greaterThan(const MYString& argStr) {
	//TODO: you need to write.
	return false;
}

bool MYString::equals(const MYString& argStr) {
	//TODO: you need to write.
	return false;
}


void MYString::setEqualTo(const MYString& argStr) {
	end = argStr.end;

	// cap = ??;						//TODO: needs to potentially grow for prog3

	for (int i = 0; i <= end; ++i) {
		str[i] = argStr.str[i];
	}
}

const char* MYString::c_str() {
	return str;
}
