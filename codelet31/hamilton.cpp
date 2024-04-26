#include <iostream>

using namespace std;

class HamiltonPerson {
public:
    HamiltonPerson(string name, int id) {
        _name = name;
        _id = id;
    }

    string get_name() const {
        return _name;
    }

private:
    string _name;
    int _id;
};

class Professor : public HamiltonPerson {
public:
    Professor(string name, int id, string dept) : HamiltonPerson(name, id) {
        _dept = dept;
    }

    string get_dept() const {
        return _dept;
    }

private:
    string _dept;
};



int main() {
    Student jane("Jane", 3418843, "Biology", 2026);
    Student felix("Felix", 5343145, "History", 2024);
    Professor prof_datta("Prof. Datta", 8431441, "Biology");

    if (jane.major_has_professor(prof_datta)) {
        cout << jane.get_name() << " is majoring in the dept. that ";
        cout << prof_datta.get_name() << " teaches in!" << endl;
    }
    else {
        cout << jane.get_name() << " is NOT majoring in the dept. that ";
        cout << prof_datta.get_name() << " teaches in!" << endl;  
    }

    if (felix.major_has_professor(prof_datta)) {
        cout << felix.get_name() << " is majoring in the dept. that ";
        cout << prof_datta.get_name() << " teaches in!" << endl;
    }
    else {
        cout << felix.get_name() << " is NOT majoring in the dept. that ";
        cout << prof_datta.get_name() << " teaches in!" << endl;  
    }

}