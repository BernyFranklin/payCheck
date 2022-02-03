/*
    C++ PaycheckV1.0.c : Defines the entry point for the console application
    Frank Bernal
    CIS054 C/C++ Programming
    Inputs: hours, payRate
    Outputs: grossPay, taxes, netPay
 */

#include <iostream>
#include <iomanip> // used to set 2 digit decimal
using namespace std;

int main(int argc, char *argv[])
{
    // define constants
    const double OVERTIME_RATE = 1.5; // OT is time and a half
    
    //declare variables
    double hours;       // value from keyboard input
    double payRate;     // value from keyboard input
    double regHours;        // remaining of values computed
    double overtimeHours;
    double regPay;
    double overtimePay;
    double totalPay;
    
    // INPUT: hours and payRate
    cout << "Enter the hours worked: ";     // prompt message
    cin >> hours;                           // input hours from keyboard
    cout << "Enter the pay rate: ";         // prompt message
    cin >> payRate;
    
    // PROCESS: compute the paycheck
    // separate regular and OT hours
    if (hours <= 40)                        // less than or equal to 40, no OT
    {
        regHours = hours;                   // separating regHours and overtimeHours
        overtimeHours = 0.0;
    }
    else                                    // hours are over 40. Compute how many are OT
    {
        regHours = 40.0;                    // regular pay for the first 40 hours
        overtimeHours = hours - 40.0;       //anything over 40 hours.
    }
    
    // compute regular, overtime, and total pay
    regPay = regHours * payRate;
    overtimePay = overtimeHours * payRate * OVERTIME_RATE;
    totalPay = regPay + overtimePay;
    
    // OUTPUT: display the paycheck values with two digits past the decimal
    cout << endl;                           // blank line before output
    cout << setiosflags(ios::fixed | ios::showpoint);       //C++ setup for display past decimal
    cout << setprecision(2);                                // two digits past the decimal point
    cout << "Pay for regular hours " << setw(7) << regPay << endl;
    cout << "Pay for overtime      " << setw(7) << overtimePay << endl;
    cout << "Total pay             " << setw(7) << totalPay << endl << endl;
    return 0;
} // end of main
