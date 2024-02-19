#include <iostream>

using namespace std;


class Card {
private:
    // Attributes:
    string _suit;
    string _rank;

public:
    // _Constructor_ method -- called to create a new Card object
    Card(string suit, string rank) {
        _suit = suit;
        _rank = rank;
    }

    // _getter_ methods - return values of attributes in the class
    string get_suit() {
        return _suit;
    }

    string get_rank() {
        return _rank;
    }

    // _setter_ methods - set the values of attributes in the class
    void set_suit(string new_suit) {
        _suit = new_suit;
    }

    void set_rank(string new_rank) {
        _rank = new_rank;
    }

};

int main() {

    Card my_card = Card("Spades", "10");
    cout << my_card.get_rank() << " of " << my_card.get_suit() << endl; 

    my_card.set_suit("Diamonds");
    cout << my_card.get_rank() << " of " << my_card.get_suit() << endl; 

}
