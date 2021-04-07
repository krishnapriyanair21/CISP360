#include <iostream>
#include <string>

using namespace std;

// TODO (1): includes / namespace declaration

const string BFF = "BFF";
const string IDK = "IDK";
const string JK = "JK";
const string TMI = "TMI";
const string TTYL = "TTYL";

const string BFF_LONG = "best friend forever";
const string IDK_LONG = "I don't know";
const string JK_LONG = "just kidding";
const string TMI_LONG = "too much information";
const string TTYL_LONG = " talk to you later";

int main()
{
   //TODO (2):  declare a string to hold the sentence
    string sentence;

   //TODO (3):  prompt the user input "Enter text:"
   cout << "Enter text:" <<endl;
   cout<< '\n' ;
   getline (cin, sentence);
   //TODO (4):  declare a variable to hold a search index
    int searchIndex;
   //TODO (5):  implement a find and replace while loop for each abbreviation (5 total)
   while (sentence.find(BFF) != string::npos) {
    searchIndex = sentence.find(BFF);
    sentence.replace(searchIndex, 3, BFF_LONG);
   }
   while (sentence.find(JK) != string::npos) {
    searchIndex = sentence.find(JK);
    sentence.replace(searchIndex, 2, JK_LONG);
   }
   while (sentence.find(IDK) != string::npos) {
    searchIndex = sentence.find(IDK);
    sentence.replace(searchIndex, 3, IDK_LONG);
   }
   while (sentence.find(TMI) != string::npos) {
    searchIndex = sentence.find(TMI);
    sentence.replace(searchIndex, 3, TMI_LONG);
   }
   while (sentence.find(TTYL) != string::npos) {
    searchIndex = sentence.find(TTYL);
    sentence.replace(searchIndex, 4, TTYL_LONG);
   }

   //TODO (6):  use a for loop to iterate through each character of the string and replace any '.' with '!'
   for (int i=0; i<sentence.length(); i++){
        if(sentence.find('.')!=string::npos){
            i = sentence.find('.');
            sentence.replace(i, 1, "!");
        }
    }
   //TODO (6):  output the modified string
    cout <<sentence<<endl;
   return 0;
}
