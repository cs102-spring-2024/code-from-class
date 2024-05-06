#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Item {
protected:
    string _name;
    bool _can_stack;

public:
    Item(string name);
    string get_name() const;
    bool can_stack();

    // Pure virtual method -- must be implemented in a subclass
    virtual void display(ostream & out) const = 0;
    virtual void change_quantity(int n) = 0;
    virtual int get_quantity() = 0;
    virtual int sell(int quantity) = 0;
};

ostream & operator<<(ostream & out, const Item & thing);

class Crop : public Item {
protected:
    static unordered_map<string, int> _price_table;
    static int _total_crops;

    int _quantity;
    int _sell_price;

public:
    Crop(string name, int quantity = 1);
    void display(ostream & out) const;
    void change_quantity(int n);
    int get_quantity();
    int sell(int quantity);

    // Static means: this can't be called by individual instances, but is
    // called on the class as a whole
    static int get_number_crops();
};


#endif //ITEM_H
