#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Standard Template Library
    // contains useful data structures
    // can hold different data types depending on what you put inside <   >

    // A vector is a lot like a dynamic array with some useful methods
    vector<int> nums = {32, 34, 19};

    // Access like with an array:
    cout << nums[2] << endl;
    nums[0] = 54;

    // Add the argument to the end of the vector
    // You don't have to worry about resizing!
    nums.push_back(288);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
    }
    cout << endl;

}