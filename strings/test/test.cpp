#include <iostream>
using namespace std;

int main() {
    int first_number, second_number, sum;

    cout << "Enter two integers: ";
    // Use cin to read both numbers at once
    cin >> first_number >> second_number;

    // Calculate the sum
    sum = first_number + second_number;

    // Display the result
    cout << first_number << " + " << second_number << " = " << sum << endl;

    return 0;
}
