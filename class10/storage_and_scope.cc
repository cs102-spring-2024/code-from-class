#include <iostream>
#include <string>

using namespace std;

// static global
const int LARGE_NUMBER = 1000000;

// Parameter upper_bound is automatic local
string some_function(int upper_bound) {

    // automatic locals
    int power_of_two = 1;
    string some_chars = "";

    // static local - all function calls will use the same value!
    static char place = 'A';

    while ((power_of_two < upper_bound) && (power_of_two < LARGE_NUMBER)) {
        cout << power_of_two << endl;
        power_of_two *= 2;
        some_chars += place;
        place++;
    }

    cout << "All preceding powers of 2 are less than " << upper_bound << " and " << LARGE_NUMBER << endl << endl;

    return some_chars;
}

int main() {

    // automatic locals
    // Note: can use same name as locals in some_function
    int power_of_two = 1024;
    int place = 400000000;

    cout << some_function(50) << endl << endl;
    cout << some_function(LARGE_NUMBER) << endl << endl;
    cout << some_function(power_of_two) << endl << endl;
    cout << some_function(place) << endl << endl;

}
