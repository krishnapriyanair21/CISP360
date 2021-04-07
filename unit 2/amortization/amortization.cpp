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
    double rateDecimal = ratePercent / 100;
    double numerator = (loanAmount * rateDecimal);
    double denominator = 1 - (pow ((1 + rateDecimal), -numMonths));
    double monthlyPayment = numerator / denominator;
    double paidBack = monthlyPayment * numMonths;
    double interestPaid = paidBack - loanAmount;


    /// TODO (3): Write your code here
    cout << "Loan Amount: $ " << loanAmount << endl;
    cout << "Monthly Interest Rate: " << ratePercent << "%" <<endl;
    cout << "Number of Payments: " << numMonths <<endl;
    cout << "Monthly Payment: $ " << monthlyPayment << endl;
    cout <<"Amount Paid Back: $ " << paidBack <<endl;
    cout <<"Interest Paid: $ " <<interestPaid <<endl;

    return 0;
}
