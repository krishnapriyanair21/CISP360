#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    /// Note that `#include <iomanip>` is required for the following line,
    /// which configures the `cout` object to print floating point numbers
    /// as "fixed, to 2 decimal places, always showing the decimal point".
    cout << setprecision(2) << fixed << showpoint;

    /// Declare input variables
    double loanAmount;
    double ratePercent;
    int numMonths;


    cout << "Enter the loan amount: " << endl;
    cin >> loanAmount;
    cout << "Enter the monthly interest rate (%): " <<endl;
    cin >> ratePercent;
    cout << "Enter the number of months: " <<endl;
    cin >> numMonths;
    /// TODO (1): Write your code here.


    /// Compute the required values:
    /*
     *               P * i
     *    A  =  ---------------
     *                      -n
     *           1 - (1 + i)
     */

    /// TODO (2): Uncomment and complete the code here:
    /// double rateDecimal = ...
    /// double numerator = ...
    /// double denominator = ...
    /// double monthlyPayment = ...
    /// double paidBack = ...
    /// double interestPaid = ...


    /// Output the report here
    cout << "----------------------" << endl;
    /// TODO (3): Write your code here
    cout << "----------------------" << endl;

    return 0;
}
