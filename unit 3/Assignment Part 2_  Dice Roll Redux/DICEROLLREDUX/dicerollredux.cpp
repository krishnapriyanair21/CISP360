#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // TODO (1): Initialize random number generator with correct SEED
    srand(1701);
    // TODO (2): Declare variables
    int numSides;
    int numDice;
    char space;
    int firstRoll;
    int secondRoll;
    int thirdRoll;


    // TODO (3): Prompt user for designation, and read input
    cout << "Choose 1, 2, or 3 dice (6-, 10-, 12-, or 20-sided)" <<endl;
    cout <<"Enter designation (e.g. '2d6'):" ;
    cin >> numDice;
    cin >> space;
    cin >> numSides;


    // TODO (4): Validate input
    if (numDice  < 0 || numDice  > 3) {
        cout << "Not a valid designation" <<endl;
    }
    else if (space != 'd') {
        cout << "Not a valid designation" <<endl;
    }
    else if (!((numSides == 6) || (numSides == 10) || (numSides == 12) || (numSides == 20))){
        cout << "Not a valid designation" <<endl;
    }
   else {
        if (numDice == 1){
                firstRoll= (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll <<endl;
                firstRoll= (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll <<endl;
                firstRoll= (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll <<endl;
        }
        else if (numDice == 2){
                firstRoll= (rand () % numSides) + 1;
                secondRoll = (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " = " << firstRoll + secondRoll <<endl;
                firstRoll= (rand () % numSides) + 1;
                secondRoll = (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " = " << firstRoll + secondRoll <<endl;
                firstRoll= (rand () % numSides) + 1;
                secondRoll = (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " = " << firstRoll + secondRoll <<endl;
        }
        else {
                firstRoll= (rand () % numSides) + 1;
                secondRoll = (rand () % numSides) + 1;
                thirdRoll = (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " + " << thirdRoll << " = " << firstRoll + secondRoll + thirdRoll <<endl;
                firstRoll= (rand () % numSides) + 1;
                secondRoll = (rand () % numSides) + 1;
                thirdRoll = (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " + " << thirdRoll << " = " << firstRoll + secondRoll + thirdRoll <<endl;
                firstRoll= (rand () % numSides) + 1;
                secondRoll = (rand () % numSides) + 1;
                thirdRoll = (rand () % numSides) + 1;
                cout << numDice << "d" << numSides << " result: " << firstRoll << " + " << secondRoll << " + " << thirdRoll << " = " << firstRoll + secondRoll + thirdRoll <<endl;
        }
    }
    // TODO (5): If NOT valid ... output error message

    // ... else ...
    // TODO (6) Generate and print the result of roll one
    // TODO (7) Generate and print the result of roll two
    // TODO (8) Generate and print the result of roll three

    return 0;
}
