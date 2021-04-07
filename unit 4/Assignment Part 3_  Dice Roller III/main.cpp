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

        // TODO (2): Start the output (e.g. "2d6 result: ")

        // TODO (3): Throw some dice and sum/display the result
    }

    return 0;
}
