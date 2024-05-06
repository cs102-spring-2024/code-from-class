#include "farmer.h"

Farmer::Farmer(string name) {
    _name = name;
    _coins = 0;
    _backpack_capacity = 12;
}

/**
 * @brief If item with given name is in _items, return a pointer to it.
 * Otherwise, return a nullptr to indicate not found
 */
Item * Farmer::find_item(string target_name) {
    for (Item * item : _items) {
        if (item->get_name() == target_name) {
            return item;
        }
    }
    return nullptr;
}

void Farmer::say_hi() {
    cout << "Hi, I'm farmer " << _name << endl;
}

void Farmer::display(ostream & out) const {
    out << "*************************************************" << endl;
    out << "Farmer: " << _name << endl;
    out << "Coins: " << _coins << endl;
    out << "Items:" << endl;
    for (Item * item : _items) {
        out << *item << endl;
    }
    out << "*************************************************";
}

void Farmer::add_new_item(Item * thing) {
    if (_items.size() < _backpack_capacity) {
        _items.push_back(thing);
    }
    else {
        cout << "Sorry, can't add item " << thing->get_name();
        cout << " because your backpack is full!" << endl;
    }
}

void Farmer::add_item(Item * thing) {
    // If can't stack, add item to the end and be done.
    if(!thing->can_stack()) {
        add_new_item(thing);
        // _items.push_back(thing);
        return;
    }

    // Otherwise, see if we find a matching item in _items, and if so, increase
    // its quantity
    Item * match = find_item(thing->get_name());
    if (match != nullptr) {
        match->change_quantity(thing->get_quantity());
    }
    else {
        // If here, we don't have any of this item, so push it back
        // _items.push_back(thing);
        add_new_item(thing);
    }
}

void Farmer::sell(string name, int quantity) {
    // Find the item to sell
    Item * thing = find_item(name);

    // Check if we actually have that item
    if (thing == nullptr) {
        cout << "Uh oh, you don't have any " << name << " to sell!" << endl;
    }
    else {
        _coins += thing->sell(quantity);
    }

}


ostream & operator<<(ostream & out, const Farmer & farmer) {
    farmer.display(out);
    return out;
}