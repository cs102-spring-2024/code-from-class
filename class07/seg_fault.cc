#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

int main() {

    int grades[ARRAY_SIZE] = {};

    for (int i = 0; i < 11; i++) {
        cout << "grades[" << i << "] = " << grades[i] << endl;
    }


}
