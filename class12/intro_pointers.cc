#include <iostream>

using namespace std;

int add_10_to_int_pointer(int * number_ptr) {
    return 10 + *number_ptr;
}

int main() {
    
    int fruit = 5;
    cout << "variable fruit has value: " << fruit << endl;
    cout << "and is stored at memory address: " << &fruit << endl;

    int * fruit_pointer = &fruit;
    cout << "fruit_pointer is at same memory: " << fruit_pointer << endl;

    int veggies = 7;
    int * healthy = &veggies;
    cout << "The address of veggies is        " << healthy << endl;

    cout << "The address of fruit_pointer is: " << &fruit_pointer << endl << endl;

    // reassign pointer
    healthy = fruit_pointer;

    cout << "now, healthy points to           " << healthy << endl;
    cout << "But, veggies is still: " << veggies << endl;

    // Dereferencing:
    cout << "*healthy gives us the value at address of healthy: " << *healthy << endl;
    int new_fruit = *healthy; // assigns a new variable
    cout << "new_fruit has value " << new_fruit << endl << endl;

    *healthy = 17;
    cout << "what will these values be? " << *healthy << " " << *fruit_pointer << " " << fruit << endl;

    cout << "new_fruit = " << new_fruit << endl;

    cout << "new_fruit memory addres: " << &new_fruit << endl;

    // Passing a pointer to a function
    int result = add_10_to_int_pointer(healthy);
    cout << "the result is " << result << endl;

    // Arrays and pointers
    int array[7] = {19, 4, 6, 1, 23, 56, -8};
    int * what = array;

    cout << endl << endl;
    cout << array[0] << endl;
    cout << *what << endl;
    cout << what[0] << endl;
    cout << *array << endl;

    cout << array << endl;

    cout << *(array + 2) << endl;

}
