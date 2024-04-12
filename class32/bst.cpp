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
};

class BinarySearchTree {
public:

    BinarySearchTree();
    bool search(int target);
    void insert(int new_data);

    BinaryNode * _root;
private:
    bool search_recursive(BinaryNode * curr, int target);
    void insert_recursive(BinaryNode * & curr, int new_data);

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


}

int main() {

    BinaryNode * three = new BinaryNode(3);
    BinaryNode * one = new BinaryNode(1);
    BinaryNode * four = new BinaryNode(4);
    BinaryNode * seven = new BinaryNode(7);
    BinaryNode * five = new BinaryNode(5);

    three->_left = one;
    three->_right = four;
    four->_right = seven;
    seven->_left = five;

    BinarySearchTree bst;
    bst._root = three;

    cout << "is 8 in bst? " << bst.search(8) << endl;
    cout << "is 1 in bst? " << bst.search(1) << endl;
    cout << "is 7 in bst? " << bst.search(7) << endl;

    bst.insert(2);

}