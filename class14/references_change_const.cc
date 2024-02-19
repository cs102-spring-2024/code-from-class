#include <iostream>

using namespace std;

int main() {

    int clinton = 13323;
    const int & kirkland = clinton;

    cout << clinton << " = " << kirkland << endl;

    clinton = 1812;

    cout << clinton << " = " << kirkland << endl;

}
