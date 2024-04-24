#include <iostream>
#include <vector>

using namespace std;

/*
ostream & operator<<(ostream & out, const vector<int> & vect) {
    out << "{";

    for (int i = 0; i < vect.size() - 1; i++) {
        out << vect[i] << ", ";
    }

    out << vect[vect.size() - 1] << "}";

    return out;
}
*/


/**
 * @brief Use templating so that this can print a vector of anything!
 */
template<typename printing>
ostream & operator<<(ostream & out, const vector<printing> & vect) {
    out << "{";

    for (int i = 0; i < vect.size() - 1; i++) {
        out << vect[i] << ", ";
    }

    out << vect[vect.size() - 1] << "}";

    return out;
}

int main() {

    vector<int> temps = {54, 59, 47, 48, 41, 48, 61, 59};
    cout << temps << endl;

    vector<string> animals = {"Dog", "Elephant", "Zebrafish", "Canary", "Mouse", "Crow"};
    cout << animals << endl;


}