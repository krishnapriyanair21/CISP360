#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

using namespace std;

int main() {
    const int R_SEED = 314159;
    // TODO: (1) add more constants here as needed (optional)

    // TODO: (2) declare variables for user input
    char choice;
    double x;
    double y;

    // TODO: (3a) configure RNG with R_SEED
    srand (R_SEED);
    // TODO: (3b) configure `cout` to output doubles / floating points to 2 decimal places
    cout << setprecision(2) << fixed << showpoint;
    // TODO: (4) prompt the user with selection choices
    cout << "Select particle location by: " <<endl;
    cout << '\t' << "[E] entering coordinates" <<endl;
    cout << '\t' << "[R] random generation" <<endl;
    // TODO: (5) read in user choice
    cin >> choice;
    // TODO: (6) use a switch statement to set x and y values
    // switch (choice) {
        // 'E' or 'e' => prompt for, and read in, user values x and y
        // 'R' or 'r' => set x and y to random values in the range {-12..12}
        // otherwise output invalid choice message
    // }
    switch (choice) {
        case ('e' ):
            cout << "Enter X-coordinate: ";
            cin >> x ;
            cout << "Enter Y-coordinate: ";
            cin >> y;
            break;
        case ('E' ):
            cout << "Enter X-coordinate:";
            cin >> x ;
            cout << "Enter Y-coordinate:";
            cin >> y;
            break;
        case ( 'r' ):
            x = rand () % 25 + (-12);
            y = rand () % 25 + (-12);
            break;
         case ( 'R' ):
            x = rand () % 25 + (-12);
            y = rand () % 25 + (-12);
            break;
        default:
            cout << "Unknown option: " <<choice <<endl;
    }

    // TODO: (7) if not an invalid choice...
    // if ( ... not choice invalid ... ) {
    if (choice == 'E' || choice == 'e' || choice == 'r' || choice == 'R'){

        // TODO: (8) display particle location (x,y)
        cout << "Particle is at (" << x << "," << y << ")"<<endl;

        // TODO: (9) compute particle distance from origin
        double distance;
        distance = sqrt ((pow (x, 2.0))+ (pow (y, 2.0)));
        // TODO: (10) declare/assign boolean `onWall` if particle close enough
        bool onWall = (fabs (distance - 10) <0.0001);

        // TODO: (11) declare/assign boolean 'inside' if particle inside wall
        bool inside = (distance < 10) ;
        // TODO: (12) use above flags to decide what to output as the result
        if (onWall)
            cout << "On cell wall" <<endl;
        else if (inside)
            cout <<"Inside cell wall" <<endl;
        else
            cout << "Outside cell wall" <<endl;
    }

    return 0;
}
