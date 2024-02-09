#include <iostream>

using namespace std;

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

}
