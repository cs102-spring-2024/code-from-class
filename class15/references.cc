#include <iostream>

using namespace std;

void add_100_to_int(int num) {
    num += 100;
}

void add_100_to_int_reference(int & num) {
    num += 100;
}

void add_100_to_int_pointer(int * num) {
    *num += 100;
}

/**
 * @brief Return x + 1 and y + 1, without changing calling arguments
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int increment_x_and_y(int x, int y, int & new_y) {
    new_y = y + 1;
    return x + 1;
}

int main() {

    int clinton = 13323;
    int & kirkland = clinton;
    int & hamilton = kirkland;

    int scct = 123;
    cout << clinton << " = " << kirkland << " = " << hamilton << endl;
    // kirkland = 1812;
    kirkland = scct;

    cout << clinton << " = " << kirkland << " = " << hamilton << endl;
    cout << &clinton << " = " << &kirkland << " = " << &hamilton << endl << endl;

    // Try pass by reference:
    int calories = 140;

    // Pass by value:
    add_100_to_int(calories);
    cout << "calories = " << calories << " after pass by value" << endl;

    // Pass by reference:
    add_100_to_int_reference(calories);
    cout << "calories = " << calories << " after pass by reference" << endl;

    // Pass by pointer:
    add_100_to_int_pointer(&calories);
    cout << "calories = " << calories << " after pass by pointer" << endl << endl;

    // Multiple return values
    int dogs = 15;
    int cats = 12;
    int more_cats;
    int more_dogs = increment_x_and_y(dogs, cats, more_cats);

    cout << more_dogs << " and " << more_cats << endl;

}
