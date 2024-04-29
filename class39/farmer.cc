#include "farmer.h"

Farmer::Farmer(string name) {
    _name = name;
    _coins = 0;
}

void Farmer::say_hi() {
    cout << "Hi, I'm farmer " << _name << endl;
}