/* ch08 ex14
Can we declare a non-reference function argument const?
e.g. void f(const int)
What might that mean? Why might we want to do that?
Why don’t people do that often?
Try it; write a couple of small programs to see what works.
idea: the income tax rate for a specific income in a specific country is
a constant value, a function may use a tax rate as a parameter, and save
the rate multiplied by the income
*/

#include <iostream>
#include <limits>      
#include <iomanip>      
using namespace std;

#include "Tax.h"
#include "Tax.cpp"

int main()
{
    const double bracket1 = 0.1;    // 0-9,950
    const double bracket2 = 0.12;   // 9,951-40,525
    const double bracket3 = 0.22;   // 40,526-86,375
    const double bracket4 = 0.24;   // 86,376-164,925

    double income = -1;

    Tax tax(-1.0, -1.0);
    cout << "How much did you earn last year? max $164,925: ";

    do
    {
        try
        {
            cin >> income;

            if (cin.fail() || income > 164925 || income < 0)
                throw "Invalid Input. Try Again. Example: 80200";

            tax.setIncome(income);
            tax.setTotalTax(tax.brac1(bracket1) + tax.brac2(bracket2) + tax.brac3(bracket3) + tax.brac4(bracket4));
        }
        catch (const char* e)
        {
            std::cerr << e << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (tax.getIncome() == -1);

    cout << "Your income tax for last year is: $" << std::fixed << std::setprecision(2) << tax.getTotalTax() << endl;
}