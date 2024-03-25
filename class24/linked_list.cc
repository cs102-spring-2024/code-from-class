#include <iostream>
using namespace std;

class Node {
public:
    Node(int data) {
        _data = data;
        _next = nullptr;
    }

    int _data;
    Node * _next;
};

class LinkedList {
public:
    LinkedList();
    // ~LinkedList();
    void set(int i, int x);      // Sets index i to value x
    int get(int i);              // Gets data at index i
    void insert(int i, int x);   // Inserts a new node with value x at i
    // void delete_node(int i);     // Deletes node at index i
    // bool contains(int x);        // true if list contains data x
    // int size();                  // size of list
    void display();              // Prints the linked list
private:
    Node * _head;
    int _size;

    Node * get_node(int i);      // Returns Node at index i
};

LinkedList::LinkedList() {
    _head = nullptr;
    _size = 0;
}

/**
 * @brief Returns Node pointer to Node at index i in this linked list
 * 
 * @param i - index
 * @return Node* - node at index i
 */
Node * LinkedList::get_node(int i) {
    Node * curr = _head;
    for (; i > 0; i--) {
        curr = curr->_next;
    }
    return curr;
}

/**
 * @brief Sets the data of the Node at index i to x
 * 
 * @param i - index
 * @param x - data to set
 */
void LinkedList::set(int i, int x) {
    get_node(i)->_data = x;
}

/**
 * @brief Get the int at index i
 * 
 * @param i - index
 * @return int - value at index i
 */
int LinkedList::get(int i) {
    return get_node(i)->_data;
}

/**
 * @brief Inserts a new Node at index i that has value x
 * 
 * @param i 
 * @param x 
 */
void LinkedList::insert(int i, int x) {
    Node * new_node = new Node(x);

    if (i == 0) {
        new_node->_next = _head;
        _head = new_node;
    }
    else {
        Node * before = get_node(i - 1);
        Node * after = before->_next;

        before->_next = new_node;
        new_node->_next = after;
    }
}

/**
 * @brief Prints the linked list
 * 
 */
void LinkedList::display() {
    cout << "LinkedList: ";
    for (Node * curr = _head; curr != nullptr; curr = curr->_next) {
        cout << curr->_data;
        if (curr->_next != nullptr)
            cout << ", ";
    }
    cout << endl;
}

int main() {

    LinkedList ll;

    ll.display();

    ll.insert(0, 3);
    ll.insert(1, 92);
    ll.insert(2, 0);

    ll.set(1, 7723);
    ll.display();

    ll.insert(2, 777);
    ll.display();

    ll.insert(0, 12345); // Broken, doesn't put at start of linked list
    ll.display();

    ll.insert(5, 55);
    ll.display();

}