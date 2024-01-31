#include <iostream>
#include <string>

using namespace std;

/**
 * Measuring weights of cats and dogs
 * want to know which of each weighs most
 * format:
 * dog 25.4
 * cat 11.2
 * cat 12.3
 * dog 72.9
 * dog 65.3
 * end
 */

const int NUM_PETS = 1000;

/**
 * @brief Prints array of ints of size size
 * 
 * Note: it's a good idea to make parameters const if you don't change them.
 * 
 * @param nums 
 * @param size 
 */
void print_doubles(const double nums[], const int size) {
    cout << "{";
    for (int i = 0; i < size - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[size - 1] << "}" << endl;
}

int main() {

    float weight;
    string id;
    int dog_index = 0;
    int cat_index = 0;
    
    double dog_weights[NUM_PETS] = {0.0};
    double cat_weights[NUM_PETS] = {0.0};

    cin >> id;

    while (id != "end") {
        cin >> weight;
        
        if (id == "dog") {
            dog_weights[dog_index] = weight;
            dog_index++;
        }
        else if (id == "cat") {
            cat_weights[cat_index] = weight;
            cat_index++;
        }

        cin >> id;

    }

    print_doubles(dog_weights, dog_index);
    print_doubles(cat_weights, cat_index);


}
