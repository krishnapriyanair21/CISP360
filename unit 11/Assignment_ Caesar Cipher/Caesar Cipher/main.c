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
    char outName[BUFFER_SIZE];
    char outPrefix[24]; ///might need to change number
    int key;

    ///read file
    FILE* inFile = NULL;
    FILE* outFile = NULL;

    ///TODO(1):  Prompt and read file name
    printf("Read file name (*.txt): \n");
    scanf("%s", inName);

    ///TODO(2):  Validate file name
    while(validFileSuffix(inName) == 0)
    {
        printf("Error.  *.txt required. \n");
        printf("Read file name (*.txt): \n");
        scanf("%s", inName);
    }

    ///TODO(3):  Open read file
    inFile = fopen(inName, "r");
    ///TODO(4):  If the input file is NULL, error and exit program
    if(inFile == NULL) {
            printf("Error: Failed to open badFile.txt\n");
        return 1;
    }
    ///TODO(5):  Prompt and read output file prefix
    printf("Output file prefix: \n");
    scanf("%s" , outPrefix);

    ///TODO(6):  Copy prefix to output file string, concatenate input file name
    strcpy(outName, outPrefix);
    strcat(outName, inName);

    ///TODO(7):  Open output file.  If it fails, exit the program.
    outFile = fopen(outName, "w");

    if(outFile == NULL) {
        printf("Error: Failed to open badFile.txt\n");
        return 1;
    }
    ///TODO(8):  Prompt and read the key.  Don't forget the & for the int on scanf!!
    printf("Key: \n");
    scanf("%d", &key);

    printf("Encrypting...\n");
    encipher(inFile, outFile, key);
    printf("Complete.\n");


    fclose(inFile);
    fclose(outFile);
}

///TODO(9):  validFileSuffix
int validFileSuffix(char str[]){
    int n = strlen(str);
    if(str[n - 4] == '.' && str[n - 3] == 't' && str[n - 2] == 'x' && str[n - 1] == 't'){
        return 1;
    }
    else {
        return 0;
    }
}

///TODO(10):  encipher
void encipher(FILE* inFile, FILE* outFile, int key){
    char declare [BUFFER_SIZE];
    while(fgets(declare, 2048, inFile) != NULL){
        shiftStr(declare, key);
        fprintf(outFile, "%s", declare);
    }
}
///declare a string of size BUFFER_SIZE
///using fgets, read while it does not return NULL
///call shiftStr to shift the buffer
///use fprintf to output the string to the output file

///TODO(11):  shiftStr
void shiftStr(char str[], int shift){
    for (size_t i = 0; i < strlen(str); i++) {
       if (isalpha(str[i]))  {
            if ( islower(str[i]) ) {
                 if ( str[i] + shift > 'z') {
                              shift -= 26;
                     }
                 else if ( str[i] + shift < 'a') {
                            shift += 26;
                     }
                }
            else {
                if (str[i] + shift > 'Z' ) {
                              shift -= 26;
                     }
                 else if ( str[i] + shift < 'A') {
                            shift += 26;
                     }
                 }
            str[i] += shift;
            }
    }
}
///Mod the shift with 26
///loop through each char
///only process if isalpha is nonzero
///if lowercase and char + shift > 'z' OR uppercase and char + shift > 'Z', subtract 26 from shift
///else if lowercase and char + shift < 'a' OR uppercase and char + shift < 'A', add 26 to shift
///add shift to the char, continue loop

