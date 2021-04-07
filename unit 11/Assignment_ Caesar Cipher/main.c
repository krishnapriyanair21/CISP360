#include <stdio.h>
#include <ctype.h>
#include <string.h>

void shiftStr(char str[], int shift);
void encipher(FILE* inFile, FILE* outFile, int key);
int validFileSuffix(char str[]);

const int BUFFER_SIZE = 2048;

int main()
{
    char inName[BUFFER_SIZE];
    
    ///TODO(0):  Declare strings for outName and outPrefix

    int key;

    
    ///TODO(1):  Prompt and read file name
    
    ///TODO(2):  Validate file name
    ///while()
    {
       ///Error message and prompt / read again
    }

    ///TODO(3):  Open read file
    ///TODO(4):  If the input file is NULL, error and exit program

    ///TODO(5):  Prompt and read output file prefix

    ///TODO(6):  Copy prefix to output file string, concatenate input file name

    ///TODO(7):  Open output file.  If it fails, exit the program.

    ///TODO(8):  Prompt and read the key.  Don't forget the & for the int on scanf!!

    printf("Encrypting...\n");
    encipher(inFile, outFile, key);
    printf("Complete.\n");
}

///TODO(9):  validFileSuffix

///TODO(10):  encipher
///declare a string of size BUFFER_SIZE
///using fgets, read while it does not return NULL
///call shiftStr to shift the buffer
///use fprintf to output the string to the output file

///TODO(11):  shiftStr
///Mod the shift with 26
///loop through each char
///only process if isalpha is nonzero
///if lowercase and char + shift > 'z' OR uppercase and char + shift > 'Z', subtract 26 from shift
///else if lowercase and char + shift < 'a' OR uppercase and char + shift < 'A', add 26 to shift
///add shift to the char, continue loop

