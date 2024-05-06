#include <iostream>
#include "farmer.h"
#include "item.h"

using namespace std;

int main() {
    Farmer jane("Jane");
    jane.say_hi();

    Crop * turnip = new Crop("Turnip");
    cout << *turnip << endl;

    jane.add_item(turnip);

    for (int i = 0; i < 15; i++) {
        Crop * potato = new Crop("Potato");
        jane.add_item(potato);
    }

    for (int i = 0; i < 6; i++) {
        Crop * cauliflower = new Crop("Cauliflower");
        jane.add_item(cauliflower);
    }

    Crop * crop = new Crop("Carrot");
    jane.add_item(crop);
    crop = new Crop("Corn");
    jane.add_item(crop);
    crop = new Crop("Wheat");
    jane.add_item(crop);
    crop = new Crop("Rice");
    jane.add_item(crop);
    crop = new Crop("Strawberry");
    jane.add_item(crop);
    crop = new Crop("Beet", 40);
    jane.add_item(crop);
    crop = new Crop("Onion");
    jane.add_item(crop);
    crop = new Crop("Banana");
    jane.add_item(crop);
    crop = new Crop("Tomato");
    jane.add_item(crop);
    crop = new Crop("Radish");
    jane.add_item(crop);
    crop = new Crop("Beet", 4);
    jane.add_item(crop);

    cout << jane << endl;

    cout << "The number of Crops: " << Crop::get_number_crops() << endl;

    jane.sell("Beet", 8);
    jane.sell("Watermelon", 4);

    cout << jane << endl;


}