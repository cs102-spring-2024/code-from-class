#include <iostream>

using namespace std;

const int NUMBERS_SIZE = 6;
const int RGB_SIZE = 3;

/**
 * @brief Prints array of ints of size size
 * 
 * Note: it's a good idea to make parameters const if you don't change them.
 * 
 * @param nums 
 * @param size 
 */
void print_ints(const int nums[], const int size) {
    cout << "{";
    for (int i = 0; i < size - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[size - 1] << "}" << endl;
}

int main() {

    int numbers[NUMBERS_SIZE] = {43, -52, -931, 0, 433, 8134};
    int rgb[RGB_SIZE] = {120, 33, 84};

    print_ints(numbers, NUMBERS_SIZE);
    print_ints(rgb, RGB_SIZE);

}
