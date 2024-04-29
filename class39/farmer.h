#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <vector>

using namespace std;

class Farmer {
private:
    string _name;
    vector<int> _items; /// TODO: make this a vector of Items
    int _coins;

public:
    Farmer(string name);
    void say_hi();
};

#endif // FARMER_H