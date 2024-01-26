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

int main() {

    float weight;
    float max_dog = 0;
    float max_cat = 0;
    string id;

    cin >> id;

    while (id != "end") {
        cin >> weight;
        if (id == "dog" && weight > max_dog) {
            max_dog = weight;
        }
        else if (id == "cat" && weight > max_cat) {
            max_cat = weight;
        }

        cin >> id;

    }

    cout << "The max dog is " << max_dog << endl;

    cout << "The max cat is " << max_cat << endl;


}
