#include <iostream>

using namespace std;

class BinaryNode {
public:
    int _data;
    BinaryNode * _left;
    BinaryNode * _right;

    BinaryNode(int data) {
        _data = data;
        _left = nullptr;
        _right = nullptr;
    }

    void print_node() {
        cout << "Node: " << _data;
        if (_left == nullptr)
            cout << " Left child is: NULL";
        else
            cout << " Left child is: " << _left->_data;
        
        if (_right == nullptr)
            cout << " Right child is: NULL";
        else
            cout << " Right child is: " << _right->_data;
    
        cout << endl;
    }
};

class BinarySearchTree {
public:

    BinarySearchTree();
    bool search(int target);
    void insert(int new_data);
    void print();

private:
    bool search_recursive(BinaryNode * curr, int target);
    void insert_recursive(BinaryNode * & curr, int new_data);
    void print_recursive(BinaryNode * curr);

    BinaryNode * _root;
};

BinarySearchTree::BinarySearchTree() {
    _root = nullptr;
}


bool BinarySearchTree::search(int target) {
    return search_recursive(_root, target);
}

bool BinarySearchTree::search_recursive(BinaryNode * curr, int target) {
    // Base case: if curr is null, target is not in tree, so return false
    if (curr == nullptr)
        return false;

    // curr->print_node();

    // Base case: curr == target, return true
    if (curr->_data == target)
        return true;

    // Recursive cases: check if we should go left or right
    if (target < curr->_data)
        return search_recursive(curr->_left, target);

    return search_recursive(curr->_right, target);
}


void BinarySearchTree::insert(int new_data) {
    insert_recursive(_root, new_data);
}

void BinarySearchTree::insert_recursive(BinaryNode * & curr, int new_data) {
    // Base case: if curr is nullptr, put new_data here!
    if (curr == nullptr)
        curr = new BinaryNode(new_data);
    
    // Recursive case: check if we should insert in left or right subtree
    else if (new_data <= curr->_data)
        insert_recursive(curr->_left, new_data);
    else
        insert_recursive(curr->_right, new_data);
}

void BinarySearchTree::print() {
    print_recursive(_root);
}

void BinarySearchTree::print_recursive(BinaryNode * curr) {
    if (curr != nullptr) {
        curr->print_node();
        print_recursive(curr->_left);
        print_recursive(curr->_right);
    }
}

int main() {

    ///// Don't need anymore because can insert nodes.
    // BinaryNode * three = new BinaryNode(3);
    // BinaryNode * one = new BinaryNode(1);
    // BinaryNode * four = new BinaryNode(4);
    // BinaryNode * seven = new BinaryNode(7);
    // BinaryNode * five = new BinaryNode(5);

    // three->_left = one;
    // three->_right = four;
    // four->_right = seven;
    // seven->_left = five;

    BinarySearchTree bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    bst.insert(7);
    bst.insert(5);

    bool is8 = bst.search(8);
    cout << "is 8 in bst? " << is8 << endl;
    bool is1 = bst.search(1);
    cout << "is 1 in bst? " << is1 << endl;
    bool is7 = bst.search(7);
    cout << "is 7 in bst? " << is7 << endl;

    bst.insert(2); 

    bool is2 = bst.search(2);
    cout << "is 2 in bst? " << is2 << endl;

    bst.print();

}