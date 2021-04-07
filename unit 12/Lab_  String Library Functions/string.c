#include <stdio.h>
#include "_string.h"  ///this must be included

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
const char* strchr(const char* str, int c);
const char* strrchr(const char* str, int c);

///ststr is the hardest function.  It uses a tricky nested loop and must return an address.
///Here are some hints:
 /// Loop thru str1, looking for the first char of str2
 /// if(str1[i] == str2[0]) Then start inner loop, j=0
 /// loop while str1[i+j] is not null and str2[j] is not null
 /// inside loop, if(str1[i+j] != str2[j]) Then break out of inner loop
 /// when inner loop completes, if(str2[j] == '\0') Then return &str1[i]
 /// if outer loop completes, then return NULL
const char* strstr(const char* str1, const char* str2);
int isalpha(int c );

int main(void){}  ///Add your own unit tests here.  When uploading, you can leave it blank.

///Server unit testers will only tell you if it failed or not
///Unit test your own code and study the specifications provided in the description