#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    Animal(string name) {
        _name = name;
    }

    string get_name() const {
        return _name;
    }

    // virtual qualifier means that the subclass can overwrite this method
    virtual void make_sound() const {
        cout << "gurgle or something?" << endl;
    }

private:
    string _name;
};

// Cat class inherits from Animal class -- Cat is subclass, Animal is superclass
// "public" means that Cat inherits the public methods from the Animal class
class Cat : public Animal {
public:

    // ": Animal(name)" -- this calls the superclass's constructor, passing name
    Cat(string name) : Animal(name) {
    }

    void make_sound() const {
        cout << "Meow!!!" << endl;
    }
};

class Reptile : public Animal {
public:
    Reptile(string name) : Animal(name) {
    }
};

class Dog : public Animal {
public:
    Dog(string name, string collar_color) : Animal(name) {
        _collar_color = collar_color;
    }

    void make_sound() const {
        cout << "Bark!!! My name is: ";
        /// We can't access private attributes in the parent class
        // cout << _name;

        /// Instead, call get_name
        cout << get_name();

        cout << " and my collar is " << _collar_color << endl;
    }

private:
    string _collar_color;
};

class GermanShepherd : public Dog {
public:
    GermanShepherd(string name, string collar_color) : Dog(name, collar_color) {
    }
};

int main() {

    Cat hugo("Hugo");
    Reptile george("George");
    Dog stuart("Stuart", "blue");
    Dog oliver("Oliver", "red");
    GermanShepherd betsy("Betsy", "yellow");

    cout << hugo.get_name() << endl;
    hugo.make_sound();

    cout << george.get_name() << endl;
    george.make_sound();

    stuart.make_sound();
    oliver.make_sound();
    betsy.make_sound();
    cout << betsy.get_name() << endl;
    
}