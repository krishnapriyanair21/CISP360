#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Note that `#include <cstdlib>` is required for using rand(), srand().
    srand(2019);    // *** do NOT change this seed ***
    // Note that in a production version of the program, something like
    //  `srand(time(0))` would be used to set an initial seed based on the
    //  system clock, thus "randomizing" the number sequence.

    // Declare variables
    // TODO (1): add the required variable declarations here
    int numSides;
    int numDice = 2;
    int firstRoll;
    int secondRoll;
    // Prompt user for number of sides
    // TODO (2): Print prompt; read in number of sides
    cout << "Number of sides (4, 6, 8, 10, 12, or 20): " << endl;
    cin >> numSides;

    // Generate and print the result of roll one
    // TODO (3): Roll one
    firstRoll = (rand () % numSides) + 1;
    secondRoll = (rand () % numSides) + 1;
    cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " = " << firstRoll + secondRoll <<endl;
    // Generate and print the result of roll two
    // TODO (4): Roll two
    firstRoll = (rand () % numSides) + 1;
    secondRoll = (rand () % numSides) + 1;
    cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " = " << firstRoll + secondRoll <<endl;

    // Generate and print the result of roll three
    // TODO (5): Roll three
    firstRoll = (rand () % numSides) + 1;
    secondRoll = (rand () % numSides) + 1;
    cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " = " << firstRoll + secondRoll <<endl;

    return 0;
}
