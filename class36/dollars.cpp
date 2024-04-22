#include <iostream>

using namespace std;

class Dollars {
private:
    int _dollars;
    int _cents;

public:
    Dollars(int dollars, int cents);
    Dollars operator+(const Dollars & other) const;
    Dollars operator*(const int & factor) const;

    int get_dollars() const {return _dollars;}
    int get_cents() const {return _cents;}

};

Dollars::Dollars(int dollars, int cents) {
    _dollars = dollars;
    _cents = cents;
}

Dollars Dollars::operator+(const Dollars & other) const {
    int cents = _cents + other._cents;
    int dollars = _dollars + other._dollars + (cents / 100);
    return Dollars(dollars, cents % 100);
}

Dollars Dollars::operator*(const int & factor) const {
    int cents = (_cents * factor) % 100;
    int dollars = (_dollars * factor) + ((_cents * factor) / 100);
    return Dollars(dollars, cents);
}

Dollars operator*(const int factor, const Dollars & money) {
    return money * factor;
}

ostream & operator<<(ostream & out, const Dollars & money) {
    out << "$" << money.get_dollars() << ".";

    // Handle when cents is less than 10
    if (money.get_cents() < 10)
        out << 0;
    out << money.get_cents();

    return out;
}

int main() {

    Dollars change(7, 53);
    Dollars a_bit_more(8, 6);
    Dollars min_wage(15, 80);

    Dollars money = change + a_bit_more;
    Dollars more_money = change + min_wage;

    cout << change << endl;
    cout << a_bit_more << endl;

    cout << money.get_dollars() << " and " << money.get_cents() << endl;
    cout << more_money.get_dollars() << " and " << more_money.get_cents() << endl;

    Dollars week = min_wage * 40;
    cout << "week: " << week.get_dollars() << " and " << week.get_cents() << endl;

    //// Can't multiply in this order, because we haven't defined int * Dollars
    Dollars month = 245 * min_wage;

    cout << "month: " << month << endl;

}