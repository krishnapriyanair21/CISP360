
#include <iostream>
#include <string>

using namespace std;

int main () {
// TODO (2): output program title
cout <<"== Fizz Buzz Deluxe ==" << endl;
// TODO (3): input (and validate) a pair of words
string word1;
string word2;
bool checkLength = true;

while (checkLength){
    cout << "Enter a pair of words (each from 3-6 chars long): ";
    cin >> word1;
    //cin >> space;
    cin >> word2;
    if ((word1.size() >= 3 && word1.size() <= 6) && (word2.size() >= 3 && word2.size() <= 6)) {
        checkLength = false ;
    }
    else {
        checkLength = true;
    }
}
// TODO (4): input (and validate) a pair of divisors

int num1;
int num2;
do {
    cout << "Enter two different integers (between 2 and 15): ";
    cin >> num1;
    //cin >> space;
    cin >> num2;
} while ((num1 < 1 || num1 > 16) || (num2 < 1 || num2 > 16) || num1 == num2 );
// TODO (5): Output "fizz buzz" sequence from 1 to 100
 for (int i = 1; i <= 100; i ++) {
    if (i % num1 == 0 && i % num2 ==0) {
        cout << word1 << word2 << " ";
    }
    else if (i % num1 == 0) {
        cout << word1 << " ";
    }
    else if (i % num2 == 0) {
        cout << word2 << " ";
    }
    else {
        cout << i << " ";
    }
    if (i % 10 == 0){
        cout << '\n';
    }
 }
// TODO (6): Output "fizz buzz" symbol map
for (int i = 1; i <= 100; i ++) {
    if (i % num1 == 0 && i % num2 ==0) {
        cout << "#";
    }
    else if (i % num1 == 0) {
        cout << "+";
    }
    else if (i % num2 == 0) {
        cout << "*";
    }
    else {
        cout << "." ;
    }
    if (i % 10 == 0){
        cout << '\n';
    }
 }
// TODO (7): Don't forget to `return 0;` at the end of `main()`

return 0;
}
