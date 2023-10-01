////
// Name:            Taylor Bisset
// Section:         A
// Program Name:    MYString Tester 
//
// Description:     Sort strings form smallest to largest 
//                  according to ASCII encoding. 
////

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "MYString.h"

using namespace std;

int main() {

    vector<MYString> words(100);        // calls default constructor 100 times
    ifstream fin("infile2.txt");

    // READ
    if (fin.fail()) {
        cout << "Couldn't open infile2.txt" << endl;
        system("pause");
        exit(1);
    }

    int wordCnt = 0;
    for (; words[wordCnt].read(fin); ++wordCnt) {       // empty loop
        // cout << words[wordCnt].c_str() << '\t';      // for verifying input
    }
    words.resize(wordCnt);            //shrink vector to size used

    // You need to write the rest

    // SORT



    // OUTPUT


    // OS independent program termination sequence. 
#ifdef _WIN32
    cout << endl;
    system("pause");
#else
    cout << endl;
    cout << "Press any key to continue . . . ";
    cin.get();
#endif
    return 0;
}

