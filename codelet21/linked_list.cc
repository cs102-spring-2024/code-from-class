#include <iostream>
using namespace std;

class Node {
public:
    Node(string data) {
        _data = data;
        _next = nullptr;
    }

    string _data;
    Node * _next;
};

class LinkedList {
public:
    LinkedList();
    void insert(int i, string x);   // Inserts a new node with value x at i
    string acronym();
    
private:
    Node * _head;
    int _size;

    Node * get_node(int i);      // Returns Node at index i
    string acronym_recursive(Node * curr);
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
 * @brief Inserts a new Node at index i that has value x
 * 
 * @param i 
 * @param x 
 */
void LinkedList::insert(int i, string x) {
    _size++;
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

string LinkedList::acronym() {
    return acronym_recursive(_head);
}



int main() {

    LinkedList ll;

    ll.insert(0, "National");
    ll.insert(1, "Collegiate");
    ll.insert(2, "Athletic");
    ll.insert(3, "Association");

    cout << ll.acronym() << endl;
    
}