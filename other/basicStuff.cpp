STRINGS
cin.get();  // one char, not a string
cin >> and cout <<
cin.operator>> 
printf();  // for C
cin >> varName;  // doesn't include \n at end if you hit enter
cin.getline(varName);  // includes \n at end if you hit enter
cin.getline(varName, 256, '\n');  // removes the \n

Strings (C++)
myString.length() or myString.size() are same. STL uses .size(), so just use that.
can use == to compare
string first_ten_of_stringA = stringA.substr(0, 10);  // substr() 
int find(string pattern, int position);  // find()
myString.insert(4, "abc");  // inserts 'abc' starting at index 4 without overwriting
myString.erase(7, 3);  // erases 3 chars starting at the 7th index
myString.c_str();  // turns myString into a c-string for use with legacy code

C-Strings (C/C++), 
char myCstring[50];  // 49 letters max + 1 '\0'
char* myCstring = new char[256];
delete [] myCstring;  // need [] to free all 256 bytes of memory
int strcmp ( const char *s1, const char *s2 );  // negative if s1 < s2, 0 if equal, positive if s1 > s2
char *strcat ( char *dest, const char *src );  // strcat searches for '\0' to cat after
char *strcpy ( char *dest, const char *src );
char *strncpy ( char *dest, const char *src, size_t len );  // will only copy len bytes from src to dest
size_t strlen ( const char *s );
size_t strlen(myCstring);

Tokenizing
#include <vector>
#include <string>
using namespace std;
vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;
    do
    {
        const char *begin = str;
        while(*str != c && *str)  // dereference 'str', compare to c, and dereference 'str' to check for NULL
            str++; // increment memory location
        result.push_back(string(begin, str));  // pushback a string from begin in mem to str in mem
    } while (0 != *str++);  // increment pointer 'str', then dereference 'str', then compare to NULL
    return result;
}

Arrays
int myArray[100];
int myArray[] = { 1, 2, 3 };  // max size stuck at 3
int myArray[10] = { 1, 2, 3 };  // everything beyond the first 2 indices will be initialized to 0, not unknown values
int myArray[10] = { 0 };  // so this will initialize all values to 0! no garbage/unknown values
int myArray[10] = { };  // this initializes all values to 0 in C++, but not allowed in C
int array[1024] = {[0 ... 1023] = 42};  // sets all to 42 but only works for GCC compilers!!!!
clever solution:
#define VAL_1X     42
#define VAL_2X     VAL_1X,  VAL_1X
#define VAL_4X     VAL_2X,  VAL_2X
#define VAL_8X     VAL_4X,  VAL_4X
#define VAL_16X    VAL_8X,  VAL_8X
#define VAL_32X    VAL_16X, VAL_16X
#define VAL_64X    VAL_32X, VAL_32X
int myArray[53] = { VAL_32X, VAL_16X, VAL_4X, VAL_1X };
multidimensional arrays:
int my2DArray[20][50];  // declares a 20x50 array
int myPoints[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9} };  // can only omit first dimension...

Arrays vs Scalars
char *ptr1;
char myArray[40];
ptr1 = myArray;  // notice no "&" needed, because myArray is really just a pointer to first element
char *ptr2;
char myScalar;
ptr2 = &myScalar;  // notice the "&" is needed now

STL
https://www.tutorialspoint.com/cplusplus/cpp_stl_tutorial.htm
http://www.cplusplus.com/reference/stl/