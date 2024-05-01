#include <iostream>
#include "farmer.h"
#include "item.h"

using namespace std;

int main() {
    Farmer jane("Jane");
    jane.say_hi();

    Crop * turnip = new Crop("Turnip");

    cout << *turnip << endl;



}