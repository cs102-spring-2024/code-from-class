#include <iostream>
#include <string>

using namespace std;

const int DAYS = 7;

void print_ints(const int nums[], int size) {
    cout << "{";
    for(int i = 0; i < size - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[size - 1] << "}" << endl;
}

/**
 * Changes value at index in array based on user input
 */
void change_array(int array[]) {
    array[2] = 4000;
}

int main() {
    
    int temperatures[DAYS] = {37, 25, 27, 31, 21, 18, 33};
    print_ints(temperatures, DAYS);

    // This function changes the array
    change_array(temperatures);
    print_ints(temperatures, DAYS);

}
