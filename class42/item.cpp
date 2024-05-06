#include "item.h"

///// Item class /////

Item::Item(string name) {
    _name = name; 
}

string Item::get_name() const {
    return _name;
}

bool Item::can_stack() {
    return _can_stack;
}

ostream & operator<<(ostream & out, const Item & thing) {
    thing.display(out);
    return out;
}

///// Crop class /////

unordered_map<string, int> Crop::_price_table = {{"Turnip", 40},
                                                 {"Potato", 50},
                                                 {"Cauliflower", 80},
                                                 {"Beet", 30}};

int Crop::_total_crops = 0;

Crop::Crop(string name, int quantity) : Item(name) {
    _quantity = quantity;
    _sell_price = _price_table[_name];
    _total_crops++;
    _can_stack = true;
}

void Crop::display(ostream & out) const {
    out << _name << ": " << _quantity << " -- Sells for: " << _sell_price;
    out << " coins each.";
}

int Crop::get_number_crops() {
    return _total_crops;
}

void Crop::change_quantity(int n) {
    _quantity += n;
}

int Crop::get_quantity() {
    return _quantity;
}

int Crop::sell(int quantity) {
    int number_to_sell = min(quantity, _quantity);
    change_quantity(-number_to_sell);
    return number_to_sell * _sell_price;
}