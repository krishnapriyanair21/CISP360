// TODO (1): Includes and namespace
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// TODO (2): Define useful constants (widths, file name)
const int ST_WIDTH = 10;
const int SQ_RT_WIDTH = 15;
const string FILENAME = "number-table.txt";

int main (){
// In the main() function ...

    // TODO (3): Declare local variables
    int start;
    int stop;
    int stepValue;
    ofstream numberTable;
    double  number;
    double squared;
    double cubed;
    double sqroot;
    // TODO (4): Acquire start, stop, and step values from user (validated, use a while loop while numbers are not valid)
    while (true) {
        cout << "Enter start, stop, and step values (space separated): " <<endl;
        cin >> start;
        cin >> stop;
        cin >> stepValue;

        if(stepValue == 0){
            cout << "Oops! step value must be greater than 0." <<endl;
            continue;
        }
        int iteration_count= ((stop - start) / stepValue + 1);

        if (stop <= start){
            cout << "Oops! stop value must be greater than start value." <<endl;
        }
        else if (stepValue <= 0) {
            cout << "Oops! step value must be greater than 0." <<endl;
        }
        else if (iteration_count > 50){
            cout << "Oops! number of iterations should not exceed 50." <<endl;
        }
        else {
            break;
        }
    }
    // TODO (5): Open output file for write (check-for / handle error)
    numberTable.open("number-table.txt");
    if (!numberTable.is_open()){
        return 1;
    }
    // TODO (6): Write table header to file
    numberTable << "---------------------------------------------" <<endl;
    numberTable << setw(ST_WIDTH) << "Number" << setw(ST_WIDTH) << "Squared" ;
    numberTable << setw(ST_WIDTH) << "Cubed" << setw(SQ_RT_WIDTH) << "Square-Root"<< endl;
    numberTable << "---------------------------------------------" <<endl;

    // TODO (7): Construct `for` loop. For each iteration...
    number = start;
    for (int i = start; i <= stop; i += stepValue) {
        squared = pow(number,2.0);
        cubed = pow(number, 3.0);
        sqroot =  sqrt(number);
        numberTable << setfill(' ') << setw(ST_WIDTH) << fixed << setprecision(0) << number;
        numberTable << setfill(' ') << setw(ST_WIDTH) << squared;
        numberTable << setfill(' ') << setw(ST_WIDTH) << cubed;
        numberTable << setfill(' ') << setw(SQ_RT_WIDTH) <<fixed << setprecision(8)<< sqroot <<endl;
        number += stepValue;
    }
        // TODO (8): Write a row of the table to the file

    // TODO (9): Finish off the table with a dashed line
    numberTable << "---------------------------------------------" <<endl;

    // TODO (10): Close the file and write a message to `cout`

    numberTable.close();
    cout << "Table written to number-table.txt" <<endl;

    // (Don't forget to return 0 at the end of the main function)
return 0;
}
