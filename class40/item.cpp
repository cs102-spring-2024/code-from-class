#include "item.h"

///// Item class /////

Item::Item(string name) {
    _name = name; 
}

string Item::get_name() const {
    return _name;
}

ostream & operator<<(ostream & out, const Item & thing) {
    thing.display(out);
    return out;
}

///// Crop class /////

unordered_map<string, int> Crop::_price_table = {{"Turnip", 40},
                                                 {"Potato", 50},
                                                 {"Cauliflower", 80}};

int Crop::_total_crops = 0;

Crop::Crop(string name) : Item(name) {
    _quantity = 1;
    _sell_price = _price_table[_name];
    _total_crops++;
}

void Crop::display(ostream & out) const {
    out << _name << ": " << _quantity << " -- Sells for: " << _sell_price;
    out << " coins each.";
}