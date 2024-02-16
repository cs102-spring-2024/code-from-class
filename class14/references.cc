#include <iostream>

using namespace std;


int main() {

    int clinton = 13323;
    int & kirkland = clinton;
    int & hamilton = kirkland;

    int scct = 123;


    cout << clinton << " = " << kirkland << " = " << hamilton << endl;

    // kirkland = 1812;
    kirkland = scct;


    cout << clinton << " = " << kirkland << " = " << hamilton << endl;

    cout << &clinton << " = " << &kirkland << " = " << &hamilton << endl;

}
