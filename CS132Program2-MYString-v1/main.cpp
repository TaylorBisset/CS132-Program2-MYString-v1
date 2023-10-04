////
// Name:            Taylor Bisset
// Section:         A
// Program Name:    TBString Tester 
//
// Description:     Sort strings in alphabetical order. 
////

// main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "TBString.h"

using namespace std;

int main() 
{

    vector<TBString> words(100);        // calls default constructor 100 times
    ifstream fin("infile2.txt");

    // READ
    if (fin.fail()) 
    {
        cout << "Couldn't open infile2.txt" << endl;
        system("pause");
        exit(1);
    }

    int wordCnt = 0;
    for (; words[wordCnt].read(fin); ++wordCnt) 
    {       // empty loop
            // cout << words[wordCnt].c_str() << '\t';      // for verifying input
    }
    words.resize(wordCnt);            //shrink vector to size used

    // You need to write the rest

    // SORT

    bool notDone = true;
    while (notDone == true)
    {
        notDone = false;
        for (int i = 0; i < wordCnt - 1; i++)
        {
            if (words[i].greaterThan(words[i + 1]))
            {
                TBString tempStr = words[i];
                words[i] = words[i + 1];
                words[i + 1] = tempStr;
                notDone = true;
            }
        }
    }

    // OUTPUT

    for (int i = 0; i < wordCnt; i++)
    {
        cout << left << setw(13) << words[i].c_str();
        if ((i + 1) % 6 == 0)
        {
            cout << endl;
        }
    }

    ofstream fout("outfile.txt");
    if (fout.fail())
    {
        cout << "Couldn't open outfile.txt" << endl;
        system("pause");
        exit(1);
    }

    for (int i = 0; i < wordCnt; i++)
    {
        fout << left << setw(13) << words[i].c_str();
        if ((i + 1) % 6 == 0)
        {
            fout << endl;
        }
    }

    fin.close();
    fout.close();

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


/*

Output to console:

I            I            I            Martian      Or           Such
They         Were         a            a            a            a
amazingly    an           an           and          animal.      as
ask          ask          be.          began        began        body?
brain        busy.        compare      could        did          directing,
each,        engine       felt         first        for          his
how          human        impossible.  in           in           intelligent
intelligent  ironclad     life         lower        machines,    man's
mechanisms?  much         my           myself       myself       or
rules        ruling,      seem         seemed       sit          sits
steam        the          the          they         they         thing
things       time         to           to           to           to
to           using,       was          what         within       would

Press any key to continue . . .

*/


/*

Assignemnt Details


Very Important to Read: For program 2 you will be using a string class to read from a file, sort and then output some string .  
I will give you most of the code for the string class called MYString, that you will need to rename according to your name 
(details are given below).   I also give you the start of main that will read in words from a file.   
You will need to complete the rest of main, which is documented below.

You will need to copy and adapt your compareTo function from program 1 and add it as a private member in your MYString class.  
As we talked about in class....

Look over the MYString class, and try to understand the way it is written and can be used.   
In the past I would have the students write this program, but I found that this was a little too big of a step for many of the students.  
Now I want you to use and try to understand the pieces.   
In the next program you will be making changes to this class to make it work more naturally, and to be able to grow as needed.

Main Program Requirements:

create a vector of MYStrings that is size 100
read each of the words from the file called "infile2.txt" (the file is out in Files section under Program Resources).  
You can call the read function directly on the indexed vector<MYString>.  (do not use vector's push_back function.  
See programming note below*).  Example:   while ( words[count].read(fin) )  {...}
as you are reading the words in, keep a count of how many words were read in.
After you have read in all the words from the file, resize your vector to the correct size based on your count of the number of words read in.
// above is already written for you as an example

// below is what you need to write
sort the MYStrings from smallest to largest 
(this will be based on the ASCII encoding....meaning capital letters will sort before lower case letters) using Bubble Sort (algorithm below)
output the sorted words to outfile.txt file
6 words per line ( use setw(13) and left, which are part of <iomanip> library, 
to space them out....the setw command should not be in the write member function).  
Below is an example of what you output should look like .....but is missing the middle section.
I            I            I            Martian      Or           Such
They         Were         a            a            a            a
amazingly    an           an           and          animal.      as

......middle words.....

things       time         to           to           to           to
to           using,       was          what         within       would
Bubble Sort Algorithm:

  create bool name notDone = true;
  loop while notDone == true
       notDone = false
       loop through the elements of the array starting with first index
           compare two elements to see if they are in proper order,  if not in order than swamp them, mark notDone = true
           increment your index so you can check the next two

Program Source Files that you should modify and use:

Main:  CS132 P2 main.cppDownload CS132 P2 main.cpp

MYString.h:  MYString.hDownload MYString.h

MYString.cpp:  MYString.cppDownload MYString.cpp

Input file: infile2.txtDownload infile2.txt

These files can also be found here on Canvas at Files\Program Resources\P2 MYString Files.

Turn In:

For turn in, you will have three files: your main program, the .h file and the .cpp file, followed by the output file.  
For all programs which include class definitions, I want you to place them in that order 
(main, interface/header (.h), and implementation (.cpp),  output file ).

If you have any program output that goes to the console window, then copy is as a comment below main.

The file format for turning in files is either .h, .cpp, .txt, or pdf of the files.   
If you have a program that can easily convert your program file to pdf, please do that 
(One way to do that is within the print dialog box instead of selecting a printer you can often select Save as PDF ).   
If you don't have an easy way to convert to PDF.

Important Note: Below is the original program write up for the MYString class, from when the students had to write the class.  
Now you are only making small adjustments.   Please look at it for a description of the set up and use of the class.  
This is similar to what I give you for future programs.

Program Note: For this assignment the normal C++ string and cstring functions can not be used (except >> and << with cstrings). 
You may not #include them. You must write all the functions that will be used.

Classes, Objects, Pointers and Dynamic Memory

Program Description: This assignment you will need to create your own string class. 
For the name of the class, use your initials from your name. For example: my string class would be called LHString. 
Since each of you will be using a unique class name, I will use the name MYSting as the generic name of the class 
(but make sure for you program, that you use the correct name based on your name).

The MYString objects will hold a cstring and allow it to be used and changed. 
We will be changing this class over the next couple programs, to be adding more features to it 
(and correcting some problems that the program has in this simple version).

Below will be the details of the class. Since this is your first class that you will be writing, 
I would recommend that you write and test this class a few member functions at a time. 
For example you may want to start by writing the two constructors and the at function and then test them with some simple code in main like this:

MYString testStr("hello");

cout << "Testing testStr.at() function\n"; // testStr.at(0) should return 'h'
   for(int i = -1; i < 10; i++ ){          // purposely testing out of bounds
       cout << i << ":" << testStr.at(i) << ' '
            << static_cast<int>(testStr.at(i)) << endl;
   }
cout << testStr.c_str() << endl;
cout << endl << endl;
Your first job will be to create and test the MYString class. As you write each member function, 
you should then write some code in main to test that the member function works well. 
Notice in the above example I was purposely using indexes outside of the bounds of the string to check if this would cause problems.

Your MYString class needs to be written using the .h and .cpp format.

Inside the class we will have the following data members:

MYString Member Data
Member Data
Description
char * str
pointer to dynamic memory for storing the string
int cap
size of the memory that is available to be used
(start with 20 char's and then increase by increments of 20 whenever this is not enough)
int end
index of the end of the string (the '\0' char)
The class will store the string in dynamic memory that is pointed to with the pointer. 
When you first create an MYString object you should allocate 20 spaces of memory (using the new command). 
The string will be stored as a cstring in this memory.  
{NOTE: Here on Canvas in Files\Review Lectures from 131\   there is a pdf of the pointer and cstring lecture slides from CS 131 to use as a review}.

For this program, your MYString variables will never need to grow beyond length 20, 
in program 3 you will need to be allow your string that is held in the class to be able to be larger than 20 chars.  
So you may want to start allowing your strings to be able to grow.....if you have extra time.  
If you are optionally building in the ability to grow, it should start with a capacity of 20, but when needed it would grow in increments of 20.  
The capacity should always be a multiple of 20.

For example if we were storing the string "cat" in a MYString object, our data member would have the following values:

Member data example
str
starting addr of dynamic array
cap
20
end
3



Dynamic Memory Array
c
a
t
\0
?
?
?
?
?
?
?
?
?
?
?
?
?
?
?
?


MYString Member Functions
Programming Note: Write and test one or two functions at a time
Member Functions : return type
Description

MYString( )	Default Constructor: creates an empty string
MYString (const char* cstr)	creates a string that contains the information from the argument
example: MYString greeting( "hello there wise one");
length( ) : int	the length of the string ( "cat" would return 3)
capacity( ) : int	the total amount of memory available for use (always 20 in this version, but in the next version, this will change)
at( int index) : char
returns the character at a certain location ( at( 0 ) for a "cat" would return 'c' ). 
If the index is not inside the string (negative or too large) then return '\0'

read( istream& istrm) : bool
read one string from the istream argument (could be from cin or an ifstream variable).  
This should work just like the >> operator.  
When reading in, you can assume that you will not read in a string longer than 99 characters. 
This function will return true if it was able to read (remember >> operator will return true if it is able to read from a file).

For simplicity sake, you could create a local char array variable 100 that you first read into 
and then you could copy from this char array into your dynamic memory.

write( ostream& ostrm) : void	write the string out to the ostream argument, but do not add any end of line (could be cout or an ofstream variable)
c_str( ) : const char *	return a pointer to a constant cstring version of the MYString object.  
This can be nice for simple outputs:
cout << objStr.c_str( ) << endl;  // displays var contents to display
setEqualTo(const MYString& argStr): void	this does the assignment operation objStr.setEqualTo( argStr ) 
would change objStr so that it would contain the same information as argStr
c_str( ) : const char *	return a pointer to a constant cstring version of the MYString object.  
This can be nice for simple outputs:
cout << objStr.c_str( ) << endl;  // displays var contents to display
lessThan(const MYString& argStr): bool	calls compareTo to determine if the objStr < argStr
greaterThan(const MYString& argStr): bool	calls compareTo to determine if the objStr > argStr
equals(const MYString& argStr)
calls compareTo to determine if the objStr == argStr

PRIVATE:

compareTo( const MYString& argStr) : int

return an int based on the following:   this is assuming the function is called in the following way:
objStr.compareTo( argStr );

negative number if  objStr < argStr
positive number if   objStr > argStr
zero if                      objStr == argStr

Main Program Requirements:

create a vector of MYStrings that is size 100
read each of the words from the file called "infile2.txt" (the file is out in Files section under Program Resources).  
You can call the read function directly on the indexed vector<MYString>.  (do not use vector's push_back function.  
See programming note below*).  Example:   while ( words[count].read(fin) )  {...}
as you are reading the words in, keep a count of how many words were read in.
After you have read in all the words from the file, resize your vector to the correct size based on your count of the number of words read in.
sort the MYStrings from smallest to largest 
(this will be based on the ASCII encoding....meaning capital letters will sort before lower case letters) using Bubble Sort
output the sorted words to outfile.txt file
6 words per line ( use setw(13), which is part of <iomanip> library, to space them out....the setw command should not be in the write member function).  
Below is an example of what you output should look like .....but is missing the middle section.
            I            I            I      Martian           Or         Such
         They         Were            a            a            a            a
    amazingly           an           an          and      animal.           as
    ......middle of the output...........
           to       using,          was         what       within        would
*Programming Note:  Do not use the push_back() member function of vector, because this won't work for this program 
(it calls the copy constructor of our MYString class, which we haven't written).

Turn In:
For turn in, you will have three files: your main program, the .h file and the .cpp file, followed by the output file.  
For all programs which include class definitions, 
I want you to place them in that order (main, interface/header (.h), and implementation (.cpp),  output file ).

If you have any program output that goes to the console window, then copy is as a comment below main.

The file format for turning in files is either .h, .cpp, .txt, or pdf of the files.   
If you have a program that can easily convert your program file to pdf, please do that 
(One way to do that is within the print dialog box instead of selecting a printer you can often select Save as PDF ).   
If you don't have an easy way to convert to PDF.

Documenting C++ class files:
In addition to the program header documentation (above main), you should also have class header documentation 
(and author info: name, Sect #, and a general explanation of the class ) at the top of the .h file.

Ways to lose points:

if your main file does not contain the program header with a program description and short function description to accompany the function prototypes.
if you did not change the MYString class name to reflect your name.
your interface (.h) file should have a class description about what the class does
your code should also be consistently indented as talked about in class, and shown in the book
you can not use global variables unless it is a const
you should use good variable names (descriptive, and start with lower case letter )
proper placement of { and } ( a } should not be placed at the end of a line)
you need to have the three source files (mystring.h, mystring.cpp, and the main) as well as a print out of the output file
if you did not split the MYString class into separate files
Comments: Comments are a way of documenting a program (explaining who did what and how). 
All programs for the rest of the course are required to have the following program header documentation 
(above main, and in any interface files (.h) ) and inline documentation to explain any tricky pieces of code.

////
// Name: Nancy Programmer
// Section: OL1
// Program Name: Hello World
//
// Description: A brief description of the program.  What does the
//  program do (not how it does it: for example, it uses loops)?  Does
//  the program get input?  What kind?  What information is output
//  from the program and to where (screen or file)
////

#include <…>

.......the rest of the program


*/