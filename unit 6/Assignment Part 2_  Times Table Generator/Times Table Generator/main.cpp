#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const int WIDTH = 4;

int main()
{
// TODO (2): Declare useful contents (file name template, widths, min and max table size)

// Inside main() function...

  // TODO (3): Declare local variables
    int tableSize;
    string fileName = "times-table-<n>.txt";
    cout << "Enter the table size (from 1 to 12): "  <<endl;
    cin >> tableSize;
  // TODO (4): Obtain (validated with a while loop) table size from user
    while (tableSize < 0 || tableSize > 13) {
        cout << "Enter the table size (from 1 to 12): " <<endl;
        cin >> tableSize;
    }
  // TODO (5): Generate the filename
  fileName = fileName.replace(fileName.find('n') - 1, 3, to_string(tableSize));


  // TODO (6): Open output file for write (abort, if an error occurs)
    ofstream timesTable;
    timesTable.open(fileName);
  // TODO (7): Write table column headers
    for (int i = 0; i < tableSize * WIDTH + WIDTH; ++i){
        if (i == 3){
            timesTable << "+" ;
        }
        else {
        timesTable << "-";
        }
    }
    timesTable << endl;
    for (int i = 0 ; i <= tableSize ; ++i ){
        if (i == 0){
            timesTable << " x |";
        }
        else {
            timesTable << setfill(' ') << setw(WIDTH) << i;
        }
    }
    timesTable <<endl;
     for (int i = 0; i < tableSize *WIDTH + WIDTH; ++i){
        if (i == 3){
            timesTable << "+" ;
        }
        else {
        timesTable << "-";
        }
    }
    timesTable <<endl;
  // TODO (8): Use nested `for` loops to write the main table
  // outer loop iterates over the rows
    // inner loop iterates over the columns
   for (int i = 1; i <= tableSize; i++) {
        if (i > 9){
             timesTable << i << " |" ;
        }
        else {
            timesTable << " " << i << " |" ;
        }
        for (int j = 1; j <=tableSize; j++){
            timesTable << setw(WIDTH) << i*j ;
        }
        timesTable <<endl;
   }
     for (int i = 0; i < tableSize *WIDTH + WIDTH; ++i){
        if (i == 3){
            timesTable << "+" ;
        }
        else {
        timesTable << "-";
        }
    }
    timesTable << endl;
    timesTable.close();
  cout << "Output written to " << fileName <<"!" <<endl;
  // TODO (9): finish off with a final line, and close the file

      return 0;
}
