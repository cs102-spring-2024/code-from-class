#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    vector<double> temps = {11.1, 22.22, 33.333, 44.4444, 55.55555};

    // An iterator is an object that references an element in a data structure,
    // as well as a way to find the next element

    // An iterator on the vector class
    // .begin() returns an iterator to the first element
    vector<double>::iterator temps_it = temps.begin();

    // While an iterator isn't exactly a pointer, it often acts like one.
    // You can:
    //   - dereference it to get a value
    //   - increment it to point to the next element
    //   - add to it like with pointer arithmetic
    
    cout << "First element: " << *temps_it << endl;
    temps_it++; // point to next element
    cout << "Second element: " << * temps_it << endl;

    // change the second element
    *temps_it = -47.2;
    cout << "Second element after change: " << *temps_it << endl;
    cout << "Two places past the second element: " << *(temps_it + 2) << endl;

    // .end() returns an iterator to just past the last element in the vector
    cout << "Last element: " << *(temps.end() - 1) << endl;

    // cout << *temps.end() << endl;

    // Let's make a for loop based on iterating from begin to end:
    cout << " ---------- For loop:" << endl;
    for (vector<double>::iterator it = temps.begin(); it != temps.end(); it++) {
        cout << *it << endl;
    }

    // Range-based for loop
    // Can be used for any data structure that has begin() and end() methods
    // implemented that return iterators
    cout << "-------- Range based for loop:" << endl;
    for (double element : temps) {
        cout << element << endl;
    }
}