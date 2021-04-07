#include <iostream>
#include <random>

using namespace std;

int main() {
    srand(32767);

    cout << "Enter dice throw designators..." << endl
         << " # dice: 1 to 8, # sides: 4, 6, 8, 10, 12" << endl
         << " e.g. '2d6', or '0' to quit" << endl;

    int nDice, nSides;
    char ch;

    // A "forever" loop...
    while (true) {
        cout << "> ";
        cin >> nDice;
        if (nDice == 0) {
            // User signal to end the prgram
            break;
        }
        cin >> ch >> nSides;
        cout << endl;

        // TODO (1): Validate input (skip if bad)
        if (nDice >= 9 || nDice < 0 || ch != 'd' || !(nSides == 4 || nSides == 6 || nSides == 8 || nSides == 10 || nSides ==12) ){
            cout << "Invalid Designator" <<endl;
            continue;
        }
        int roll;
        int sum = 0;
        // TODO (2): Start the output (e.g. "2d6 result: ")
        cout << nDice << ch <<nSides << "result: " ;
        // TODO (3): Throw some dice and sum/display the result
        for (int i = 1; i < nDice; i++) {
            roll = (rand () % nSides) + 1;
            cout << roll << " + ";
            sum = roll + sum;
        }
        roll = (rand () % nSides) + 1;
        sum += roll;
        cout << roll << " = " <<sum <<endl;
    }

    return 0;
}
