#include <iostream>
#include <algorithm>

using namespace std;

const int EXTRA_GRADES = 25;

void print_ints(const int nums[], int size) {
    cout << "{";
    for(int i = 0; i < size - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[size - 1] << "}" << endl;
}

/**
 * @brief Creates a new array of ints based on user input and returns it
 * 
 * @param count - size of the array
 * @return int* - returned array of ints
 */
int * input_ints(int count) {
    cout << "Enter ints, one line at a time:" << endl;
    int * integers = new int[count];

    for (int i = 0; i < count; i++) {
        cin >> integers[i];
    }

    return integers;
}

int median(int * numbers, int count) {
    sort(numbers, numbers + count);
    return numbers[count / 2];
}

int main() {

    // Dynamic storage int:
    int * cows = new int;
    *cows = 72;

    cout << "*cows = " << *cows << endl;

    delete cows;
    // delete cows; // double delete (double free) -- don't do this

    // Shouldn't access an address after we've freed it
    // cout << "*cows now = " << *cows << endl;

    // Create a dynamic array
    int * rgb = new int[3] {250, 183, 23};
    cout << "rgb[1] = " << rgb[1] << endl;
    rgb[2] = 60;
    cout << "rgb = ";
    print_ints(rgb, 3);

    /// Don't do this, it's accessing memory past the end of the array
    // rgb[3000] = 177;
    // cout << "rgb[3000] = " << rgb[3000] << endl;

    delete[] rgb;

    // Create a dynamic array with a size determined at runtime.
    int count;
    cout << "How many grades do you want to enter: ";
    cin >> count;

    // Return a dynamic array from a function
    int * grades = input_ints(count);

    print_ints(grades, count);
    int * grades_another = grades;

    int med = median(grades, count);
    cout << endl << "median of grades = " << med << endl;
    cout << "grades = ";
    // print_ints(grades, count);

    int * old_grades = grades;
    grades = new int[count + EXTRA_GRADES];

    // Copy over grades to new array
    for (int i = 0; i < count; i++) {
        // cout << "before reassigning, grades[" << i << "] = " << grades[i] << endl;
        grades[i] = old_grades[i];
        // cout << "after reassigning, grades[" << i << "] = " << grades[i] << endl << endl;
    }

    delete[] old_grades;

    for (int i = count; i < count + EXTRA_GRADES; i++)
        grades[i] = 50;

    // print_ints(grades, count + EXTRA_GRADES);

    int new_med = median(grades, count + EXTRA_GRADES);
    cout << "new median is: " << new_med << endl;



    delete[] grades;
    // delete[] grades_another;

    // Shows we can make a new array and have grades point to it after
    // we deleted grades
    // grades = new int[4] {98, 67, 77, 87};
    // print_ints(grades, 4);
    // delete[] grades;



}
