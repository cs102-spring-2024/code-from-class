#include <iostream>

using namespace std;

class Node {
public:
    Node(int data) {
        _next = nullptr;
        _data = data;
    }

    void display_node() {
        cout << "Node info:" << endl;
        cout << "_data = " << _data << endl;
        cout << "_next = " << _next << endl;
    }

    // Attributes are public on purpose!
    int _data;
    Node * _next;
};

class Stack {
public:
    Stack() {
        _top = nullptr;
    }

    void push(int item) {
        // THIS IS BAD: This node and its pointer will be freed at the end
        // of the method!!!
        // Node node(item);
        // Node * node_ptr = &node;

        // This is good: use dynamic memory
        Node * node_ptr = new Node(item);

        // change _top to point to node_ptr
        node_ptr->_next = _top;
        _top = node_ptr;

    }

private:
    Node * _top;
};

int main() {
    // Create a node
    Node my_node(17);
    cout << "_data = " << my_node._data << " and _next = " << my_node._next << endl;
    my_node.display_node();

    cout << "Linking to other_node:" << endl;
    Node other_node(5);
    my_node._next = &other_node;
    my_node.display_node();

    Node * my_node_ptr = & my_node;
    my_node_ptr->display_node();

}
