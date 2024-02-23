#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1000;

class Stack {
public:
    // Constructor:
    Stack() {
        _size = 0;
    }

    void push(int item) {
        _stack[_size] = item;
        _size++;
    }


private:
    int _size;
    int _stack[MAX_STACK_SIZE];
};

int main() {

    Stack history;
    history.push(14);
    // cout << "top = " << history.top() << endl;

}
