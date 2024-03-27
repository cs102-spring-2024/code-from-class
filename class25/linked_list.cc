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
    bool contains(int x);        // true if list contains data x
    int size();                  // size of list
    void display();              // Prints the linked list
    int max();                   // returns the maximum element in the list
private:
    Node * _head;
    int _size;

    Node * get_node(int i);      // Returns Node at index i
    bool contains_recursive(Node * curr, int x);
    int size_recursive(Node * curr);
    int max_recursive(Node * curr);
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

/**
 * @brief Returns true if x is in this linked list
 */
bool LinkedList::contains(int x) {
    return contains_recursive(_head, x);
}

bool LinkedList::contains_recursive(Node * curr, int x) {
    if (curr == nullptr)
        return false;

    if (curr->_data == x)
        return true;

    return contains_recursive(curr->_next, x);
}

int LinkedList::size() {
    return size_recursive(_head);
}

int LinkedList::size_recursive(Node * curr) {
    // Base case: empty list's size = 0
    if (curr == nullptr)
        return 0;

    // Find the length of the rest of the list, and add 1 to it
    int size_rest_of_list = size_recursive(curr->_next);
    return size_rest_of_list + 1;
}

int LinkedList::max() {
    return max_recursive(_head);
}

int LinkedList::max_recursive(Node * curr) {
    // Note: diff base case than prev example

    // cout << "At the beginning. curr->_data = " << curr->_data << endl;

    if (curr->_next == nullptr)
        return curr->_data;

    // Assume recursion fairy gives the max value in all nodes after curr
    int max_of_rest_of_list = max_recursive(curr->_next);

    // cout << "After recursive call. curr->_data = " << curr->_data << " and max_of_rest_of_list = " << max_of_rest_of_list << endl;

    if (curr->_data > max_of_rest_of_list)
        return curr->_data;

    return max_of_rest_of_list;
}

int main() {

    LinkedList ll;

    for (int i = 0; i < 6; i++) {
        ll.insert(i, i * 11);
    }

    ll.display();

    cout << "Does list contain 44? " << ll.contains(44) << endl;
    cout << "Does list contain 38? " << ll.contains(38) << endl;
    cout << "Size of list: " << ll.size() << endl;

    // cout << "Max of LL: " << ll.max() << endl;
    ll.insert(2, 999);
    ll.display();

    int the_max = ll.max();
    cout << "Max of LL: " << the_max << endl;


}