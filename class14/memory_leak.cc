#include <iostream>

using namespace std;

const long NUM_LOOPS = 50000;
const long SIZE_ARRAY = 1000000000;

int main() {

    int * array_to_leak;

    for (int i = 0; i < NUM_LOOPS; i++) {
        if (i % 1000 == 0) {
            cout << "i = " << i << endl;
        }

        // Each time through the loop, we are requesting new memory, without
        // freeing the memory we were alread using!
        // i.e. we're leaking memory
        array_to_leak = new int[SIZE_ARRAY];

        // What if we delete?
        // Prevents the memory leak!
        // delete[] array_to_leak;
    }

}
