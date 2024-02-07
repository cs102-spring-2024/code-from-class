#include <iostream>
#include <string>

using namespace std;

string print_stuff(int num_times) {

    // Note: because of local scope, this is a different variable
    // than the dog in the main (or any other) function
    string dog = "Jeremy";

    for (int i = 0; i < num_times; i++) {
        cout << "i = " << i << endl;
        cout << "Dog's name at start of loop: " << dog << endl;

        // Note: we can declare a different local "dog" in this loop
        // 
        int dog = 15;
        cout << "Dog's name at end of loop: " << dog << endl;
    }

    // can we use i here?
    // cout << "Value of i at end of loop: " << i << endl;

    // Can't declare same variable twice in the same block
    // double dog = 3.1415;

    // What will this return?
    return dog;
}


int main() {
    int dog = 5;
    string name = print_stuff(dog);

    cout << "The dog's name was " << name << endl;
}
