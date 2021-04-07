#include <stdio.h>
#include "_string.h"  ///this must be included

size_t strlen(const char* str){
    int count = 0;
    int i = 0 ;
    while (str[i] != '\0'){
        count++;
        i ++;
    }
    return count;
}
int strcmp(const char* str1, const char* str2){
    int i =0;
    while (str1[i] == str2[i]){
        if (str1[i] == '\0'){
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
char* strcpy(char* dest, const char* src){
    int i = 0;
    while (src[i] != '\0'){ ///notworking
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
char* strncpy(char* dest, const char* src, size_t n){
    for (size_t i = 0; i < n; i++){
            dest[i] = src[i];
        }
        return dest;
}
char* strcat(char* dest, const char* src){
    int i = 0;
    int j = 0;
    while (dest[i] != '\0'){
        i++;
    }
    while (src[j] != '\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    return dest;
}
char* strncat(char* dest, const char* src, size_t n){
    int i = 0;
    int j;
    while (dest[i] != '\0'){
        i++;
    }
    for (j = 0; j < n; j++){
        dest[i] = src[j];
        i++;
    }
    return dest;
}
const char* strchr(const char* str, int c){
    while (*str != '\0'){
        if (*str == c){
            return (char*) str;
        }
        *str++;
    }
    return NULL;
}
const char* strrchr(const char* str, int c){
    char* value = 0;
     while (*str != '\0'){
        if (*str == (char)c){
            value = str;
        }
        *str++;
    }
    return value;

}

///ststr is the hardest function.  It uses a tricky nested loop and must return an address.
///Here are some hints:
 /// Loop thru str1, looking for the first char of str2
 /// if(str1[i] == str2[0]) Then start inner loop, j=0
 /// loop while str1[i+j] is not null and str2[j] is not null
 /// inside loop, if(str1[i+j] != str2[j]) Then break out of inner loop
 /// when inner loop completes, if(str2[j] == '\0') Then return &str1[i]
 /// if outer loop completes, then return NULL
const char* strstr(const char* str1, const char* str2){
    if (*str2 == '\0')
		return str1;
	for (int i = 0; i < strlen(str1); i++)
	{
		if (*(str1 + i) == *str2)
		{
			char* ptr = strstr(str1 + i + 1, str2 + 1);
			return (ptr) ? ptr - 1 : NULL;
		}
	}

	return NULL;
}

int isalnum(int c ){
    if ( (c > 47 && c < 58) || (c > 64 && c < 91)|| (c > 96 && c < 123)){
        return 1;
    }
    else {
        return 0;
    }
}

int main(void){}  ///Add your own unit tests here.  When uploading, you can leave it blank.

///Server unit testers will only tell you if it failed or not
///Unit test your own code and study the specifications provided in the description
