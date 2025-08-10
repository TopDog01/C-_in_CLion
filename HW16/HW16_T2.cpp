#include <iostream>
#include <string>

using namespace std;

int main()
{
    string integerPart;
    string fractionalPart;

    cout << "Enter the integer part of the number: ";
    cin >> integerPart;

    cout << "Enter the fractional part of the number: ";
    cin >> fractionalPart;

    string combineNumber = integerPart + "." + fractionalPart;
    double result = std::stod(combineNumber);
    cout << "The constructed number is: " << result << endl;
    return 0;
}