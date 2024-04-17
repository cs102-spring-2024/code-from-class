#include <iostream>
#include <vector>

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
    ~BinarySearchTree();
    bool search(int target);
    void insert(int new_data);
    void print();
    void in_order_traversal();

private:
    void destructor_recursive(BinaryNode * curr);
    bool search_recursive(BinaryNode * curr, int target);
    void insert_recursive(BinaryNode * & curr, int new_data);
    void print_recursive(BinaryNode * curr);
    void in_order_traversal_recursive(BinaryNode * curr);

    BinaryNode * _root;
};

BinarySearchTree::BinarySearchTree() {
    _root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    destructor_recursive(_root);
}

/**
 * @brief Delete every node in the tree using a post-order traversal
 * 
 * @param curr 
 */
void BinarySearchTree::destructor_recursive(BinaryNode * curr) {
    // Implicit base case: do nothing
    if (curr != nullptr) {
        destructor_recursive(curr->_left);
        destructor_recursive(curr->_right);
        cout << "About to delete " << curr->_data << endl;
        delete curr;
    }
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

void BinarySearchTree::in_order_traversal() {
    in_order_traversal_recursive(_root);
}

void BinarySearchTree::in_order_traversal_recursive(BinaryNode * curr) {
    // Implicit base case: if nullptr, do nothing
    if (curr != nullptr) {
        in_order_traversal_recursive(curr->_left);
        curr->print_node();
        in_order_traversal_recursive(curr->_right);
    }
}


void tree_sort(vector<int> numbers) {
    BinarySearchTree bst;

    for (int i = 0; i < numbers.size(); i++) {
        bst.insert(numbers[i]);
    }

    // bst.in_order_to_vector();
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
    bst.insert(2); 
    bst.insert(-6); 
    bst.insert(8); 
    bst.insert(6); 

    bst.in_order_traversal();

    vector<int> candy = {5, 2, -9, 0, -3, 32, 31, 28, -24, 54, -2, -42};

    tree_sort(candy);

    for (int i = 0; i < candy.size(); i++) {
        cout << candy[i] << ", ";
    }
    cout << endl;

}