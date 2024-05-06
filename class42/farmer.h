#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class Farmer {
private:
    string _name;
    vector<Item *> _items;
    int _coins;
    int _backpack_capacity;

    Item * find_item(string target_name);
    void add_new_item(Item * thing);

public:
    Farmer(string name);
    void say_hi();
    void display(ostream & out) const;
    void add_item(Item * thing);
    void sell(string name, int quantity);
};

ostream & operator<<(ostream & out, const Farmer & farmer);

#endif // FARMER_H