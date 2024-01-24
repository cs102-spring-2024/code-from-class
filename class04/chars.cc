#include <iostream>

using namespace std;

/**
 * Returns boolean of whether ch is lowercase
 * @param: ch - character to check
 * @return: boolean of whether ch is lowercase
*/
bool is_lowercase(char ch) {
    return ch >= 'a' && ch <= 'z';
}

/**
 * If ch is a lowercase letter, return the capital version of it.
 * Otherwise, just return ch
*/
char capitalize(char ch) {
    if (is_lowercase(ch))
        return ch - 32;
    return ch;
}

int main() {

    // char ch;
    // cout << "Enter a character: ";
    // cin >> ch;

    // bool lower = is_lowercase(ch);

    // cout << lower << endl;

    // cout << ch << " capitalized is " << capitalize(ch) << endl;

    for (unsigned char ch = 0; ch < 255; ch++) {
        cout << ch << " has an ASCII value of " << int(ch) << endl;
    }


}