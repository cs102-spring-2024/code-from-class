#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// typedef allows us to define the name of a new type
// in this case, my_type is defined to mean int
typedef string my_type;

class BinaryNode {
public:
    my_type _data;
    BinaryNode * _left;
    BinaryNode * _right;

    BinaryNode(my_type data) {
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
    bool search(my_type target);
    void insert(my_type new_data);
    void print();
    void in_order_traversal();
    void in_order_to_vector(vector<my_type> &);
    int height();

private:
    void destructor_recursive(BinaryNode * curr);
    bool search_recursive(BinaryNode * curr, my_type target);
    void insert_recursive(BinaryNode * & curr, my_type new_data);
    void print_recursive(BinaryNode * curr);
    void in_order_traversal_recursive(BinaryNode * curr);
    void in_order_to_vector_recursive(BinaryNode *, vector<my_type> &, int &);
    int height_recursive(BinaryNode *);

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
        // cout << "About to delete " << curr->_data << endl;
        delete curr;
    }
}

bool BinarySearchTree::search(my_type target) {
    return search_recursive(_root, target);
}

bool BinarySearchTree::search_recursive(BinaryNode * curr, my_type target) {
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


void BinarySearchTree::insert(my_type new_data) {
    insert_recursive(_root, new_data);
}

void BinarySearchTree::insert_recursive(BinaryNode * & curr, my_type new_data) {
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

void BinarySearchTree::in_order_to_vector(vector<my_type> & numbers) {
    int index = 0;
    in_order_to_vector_recursive(_root, numbers, index);
}

void BinarySearchTree::in_order_to_vector_recursive(BinaryNode * curr, \
                                        vector<my_type> & numbers, int & index) {
    // Implicit base case: if nullptr, do nothing
    if (curr != nullptr) {
        in_order_to_vector_recursive(curr->_left, numbers, index);
        
        // Visit this node
        numbers[index] = curr->_data;
        index++;

        in_order_to_vector_recursive(curr->_right, numbers, index);
    }
}

int BinarySearchTree::height() {
    return height_recursive(_root);
}

int BinarySearchTree::height_recursive(BinaryNode * curr) {
    if (curr == nullptr)
        return -1;

    int left_height = height_recursive(curr->_left) + 1;
    int right_height = height_recursive(curr->_right) + 1;
    return max(left_height, right_height);
}

void tree_sort(vector<my_type> & numbers) {
    BinarySearchTree bst;

    for (int i = 0; i < numbers.size(); i++) {
        bst.insert(numbers[i]);
    }

    bst.in_order_to_vector(numbers);
}

int main() {

    BinarySearchTree bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    bst.insert(70);
    bst.insert(5);
    bst.insert(2); 
    bst.insert(-6); 
    bst.insert(8); 

    bst.in_order_traversal();

    BinarySearchTree bst_doubles;
    bst_doubles.insert(3.1415);
    bst_doubles.insert(2000.3);
    bst_doubles.insert(-42.234567);
    bst_doubles.insert(0.0);
    bst_doubles.insert(4023.23232);
    bst_doubles.in_order_traversal();

    BinarySearchTree names;
    names.insert("Fred");
    names.insert("George");
    names.insert("Ron");
    names.insert("Charlie");
    names.insert("Ginny");
    names.insert("Bill");
    names.insert("Percy");
    names.in_order_traversal();



}