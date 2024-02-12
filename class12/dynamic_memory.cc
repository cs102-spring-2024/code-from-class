#include <iostream>

using namespace std;

void print_ints(const int nums[], int size) {
    cout << "{";
    for(int i = 0; i < size - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[size - 1] << "}" << endl;
}

int main() {

    // Dynamic storage int:
    int * cows = new int;
    *cows = 72;

    cout << "*cows = " << *cows << endl;

    delete cows;
    // delete cows; // double delete (double free) -- don't do this

    // Shouldn't access an address after we've freed it
    // cout << "*cows now = " << *cows << endl;


}
