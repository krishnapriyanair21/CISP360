// TODO (1): includes and namespace declaration
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
// main() function:
int main (){

    // TODO (2): declare local variables
    string fileName;
    ifstream file;
    // TODO (3): acquire input filename (validated)
    cout << "Enter the name of the input file: " <<endl;
    cin >> fileName;
    while (fileName.find(".txt")== string::npos){
        cout << "Only filenames ending in '.txt' are accepted!" <<endl;
        cout << "Enter the name of the input file: " <<endl;
        cin >> fileName;
    }
    // TODO (4): open input file (abort if failure)
    file.open(fileName);
    if (!file.is_open()){
        cout << "Failed to open file for read: " <<fileName <<endl;
        return 1;
    }
    // TODO (5): generate output file names and open output files
    //           (check there were no errors, abort if failure)
    ofstream even;
    ofstream odd;

    string evenFile = fileName.replace(fileName.find(".txt"), 4, "-even.txt");
    fileName = fileName.replace(fileName.find("-even"), 5, ""); ///fixing file name

    string oddFile = fileName.replace(fileName.find(".txt"), 4, "-odd.txt");
    fileName = fileName.replace(fileName.find("-odd"), 4, ""); ///fixing file name

    even.open(evenFile);
    if (!even.is_open()){
        cout << "Failed to open file for read: " << fileName << endl;
        return 1;
    }
    odd.open(oddFile);
    if (!odd.is_open()) {
        cout << "Failed to open file for read: " <<fileName <<endl;
    }
    // TODO (6): initialize word counts
    int evenCount = 0;
    int oddCount = 0;
    int total = 0;
    string input;
    // TODO (7): use a `while` loop to read in / test / output each word
    while (!file.eof()){
        file >> input;
        if (!file.fail()){
            if (input.length() % 2 == 0){
                evenCount++;
                even << input<< endl;
            }
            else if (input.length() % 2 == 1){
                oddCount++;
                odd << input <<endl;
            }
            else {
                cout<< " I DON'T WORK" <<endl;
            }
        total++;
        }
    }

    // TODO (8): close all files

    // TODO (9): output summary
    cout << total <<" words read in from " << fileName <<endl;
    cout << evenCount << " words written to " << evenFile <<endl;
    cout << oddCount << " words written to " << oddFile <<endl;
    // (and what do we finish main() with?)
    return 0;
}
