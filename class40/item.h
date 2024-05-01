#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Item {
protected:
    string _name;

public:
    Item(string name);
    string get_name() const;

    // Pure virtual method -- must be implemented in a subclass
    virtual void display(ostream & out) const = 0;
};

ostream & operator<<(ostream & out, const Item & thing);

class Crop : public Item {
protected:
    static unordered_map<string, int> _price_table;
    static int _total_crops;

    int _quantity;
    int _sell_price;

public:
    Crop(string name);
    void display(ostream & out) const;
};


#endif //ITEM_H
