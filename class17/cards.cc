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

    /**
     * @brief Returns a long string representation of the card
     * 
     * @return string 
     */
    string long_string() {
        string result = _rank + " of " + _suit;
        return result;
    }

    /**
     * @brief Returns a short string representation of the card
     * For example, for the 5 of Diamonds it should return 5D
     * If the card is King of Spades, it should be KS
     * 
     * @return string 
     */
    string short_string() {
        string result = "";
        if (_rank == "10")
            result += _rank;
        else
            result += _rank[0];

        result += _suit[0];
        return result;
    }

    /**
     * @brief Returns true if this card is a face card
     */
    bool is_face() {
        return _rank == "Jack" || _rank == "Queen" || _rank == "King";
    }

    /**
     * @brief Returns the integer value of the card's rank, between 2 (for 2)
     *        and 14 (for Ace)
     * 
     * @return int 
     */
    int rank_number() {
        if (_rank == "Jack")
            return 11;
        else if (_rank == "Queen")
            return 12;
        else if (_rank == "King")
            return 13;
        else if (_rank == "Ace")
            return 14;
        else if (_rank == "10")
            return 10;

        return _rank[0] - '0';
    }

    /**
     * @brief Tells if two cards have the same rank
     * 
     * We pass other Card by reference, so that we don't have to make
     * a copy.
     */
    bool equal_rank(Card & other) {
        return _rank == other.get_rank();
    }

    /**
     * @brief Returns true if this card has a higher rank than other
     */
    bool higher_rank(Card & other) {
        return rank_number() > other.rank_number();
    }

};


int main() {

    Card my_card = Card("Spades", "10");
    cout << my_card.get_rank() << " of " << my_card.get_suit() << endl; 

    my_card.set_suit("Diamonds");
    cout << my_card.get_rank() << " of " << my_card.get_suit() << endl; 
    cout << my_card.long_string() << endl; 

    Card your_card = Card("Hearts", "King");
    Card steves_card = Card("Clubs", "3");

    // Create an array of cards
    Card hand[3] = {my_card, your_card, steves_card};

    for (int i = 0; i < 3; i++) {
        cout << "short card: " << hand[i].short_string();
        if (hand[i].is_face())
            cout << " is a face card";
        else
            cout << " is NOT a face card";

        cout << " and has rank: " << hand[i].rank_number() << endl;
    }

    cout << endl << "Does the rank of my_card equal the rank of you_card? ";
    cout << my_card.equal_rank(your_card) << endl;

    Card billys_card = Card("Hearts", "10");
    cout << endl << "Does the rank of my_card equal the rank of billys_card? ";
    cout << my_card.equal_rank(billys_card) << endl;

    cout << endl << "Is the rank of my_card greater than the rank of you_card? ";
    cout << my_card.higher_rank(your_card) << endl;

    cout << endl << "Is the rank of my_card greater than the rank of billys_card? ";
    cout << my_card.higher_rank(billys_card) << endl;

    cout << endl << "Is the rank of my_card greater than the rank of steves_card? ";
    cout << my_card.higher_rank(steves_card) << endl;

}
