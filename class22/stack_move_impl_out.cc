#include <iostream>

using namespace std;

class Node {
public:
    Node(int data) {
        _next = nullptr;
        _data = data;
    }

    // Attributes are public on purpose!
    int _data;
    Node * _next;
};

// Class declaration -- showing the interface
class Stack {
public:
    Stack();
    ~Stack();
    void push(int item);
    int top();
    int pop();
    int size();
    void display();

private:
    Node * _top;
    int _size;
};

// Below here are all of the stack method implementations

Stack::Stack() {
    _top = nullptr;
    _size = 0;
}

Stack::~Stack() {
    cout << "Calling the destructor" << endl;

    while (_top != nullptr)
        pop();
}

void Stack::push(int item) {
    // This is good: use dynamic memory
    Node * node_ptr = new Node(item);

    // change _top to point to node_ptr
    node_ptr->_next = _top;
    _top = node_ptr;

    _size++;
}

int Stack::top() {
    return _top->_data;
}

int Stack::pop() {
    // Get data and a pointer to old top
    int int_to_return = _top->_data;
    Node * old_top = _top;

    // Reassign top, then delete old top
    _top = _top->_next;
    delete old_top;

    _size--;

    return int_to_return;
}

int Stack::size() {
    return _size;
}

void Stack::display() {
    cout << "Stack[ ";
    
    string result = "";
    

    for (Node * curr = _top; curr != nullptr; curr = curr->_next) {
        if (curr != _top)
            result = to_string(curr->_data) + ", " + result;
        else
            result = to_string(curr->_data) + result;        
    }

    cout << result << endl;
}


int main() {
    Stack stack;

    stack.push(5);
    stack.push(17);
    stack.push(99);

    stack.display();

    cout << stack.top() << endl;
    cout << stack.pop() << endl;

    cout << "size = " << stack.size() << endl;

}
