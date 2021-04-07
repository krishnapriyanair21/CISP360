#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 4000000;
const string FILE_NAME = "GoogleWords.txt";
string a[MAX_SIZE];

void insertionSort(string a[], int size);
int binarySearch(string a[], string key, int size);
int readDictionary(string a[], string fileName);
void writeDictionary(string a[], int size, string fileName);
int updateDictionary(string a[], int size, string s, string fileName);
void outputMatches(string a[], int size, string s);

int main()
{
    int size = readDictionary(a, FILE_NAME);
    string input;
    cout << "Type one word.  \"q\" to quit." << endl;
    cout << "> ";
    cin >> input;
    while(input != "q")
    {
        outputMatches(a, size, input);
        size = updateDictionary(a, size, input, FILE_NAME);
        cout << "> ";
        cin >> input;
    }
    return 0;
}

///TODO(0)  define binarySearch

///TODO(1)  define insertionSort

///TODO(2)  define readDictionary
/*
- Open an ifstream using fileName
- Read one word at a time, separated by \n, into a
- return the number of words read.  This will be used for size throughout the rest of the code.
*/

///TODO(3)  define writeDictionary
/*
- Open an ofstream using fileName
    - Use its default behavior of deleting the existing file, we will write a new one.
- Write each element of a to the file.
*/

///TODO(4)  define updateDictionary
/*
- Use binarySearch to search a for s.  
- If s is NOT found at a valid index:
    - assign s to the end of the array.
        - The index of the end of the array is size.  eg if size is 5, the new element should be written to index 5.
    - increment size
    - Sort a using insertionSort
    - Write a to the file using writeDictionary
*/

///TODO(5)  define outputMatches
/*
- loop through each element of a
    - call .find on each element, searching for s
    - If the element begins with s, ie the index returned from .find is 0, then print the element
*/
