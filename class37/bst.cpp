#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// A templated class or function can take different data types
// vector is an example: vector<int> or vector<string>
// With templating, we can have diff BSTs with different types in them
// in the same file

// Steps to template a class:
// 1. make template
// 2. move all methods back inside the class declaration

template<typename my_type>
class BinaryNode {
public:
    my_type _data;
    BinaryNode<my_type> * _left;
    BinaryNode<my_type> * _right;

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

template<typename T>
class BinarySearchTree {
public:

    BinarySearchTree() {
        _root = nullptr;
    }

    ~BinarySearchTree() {
        destructor_recursive(_root);
    }

    bool search(T target) {
        return search_recursive(_root, target);
    }

    void insert(T new_data) {
        insert_recursive(_root, new_data);
    }

    void print() {
        print_recursive(_root);
    }


    void in_order_traversal() {
        in_order_traversal_recursive(_root);
    }

    void in_order_to_vector(vector<T> & numbers) {
        int index = 0;
        in_order_to_vector_recursive(_root, numbers, index);
    }


private:
    /**
     * @brief Delete every node in the tree using a post-order traversal
     * 
     * @param curr 
     */
    void destructor_recursive(BinaryNode<T> * curr) {
        // Implicit base case: do nothing
        if (curr != nullptr) {
            destructor_recursive(curr->_left);
            destructor_recursive(curr->_right);
            // cout << "About to delete " << curr->_data << endl;
            delete curr;
        }
    }

    bool search_recursive(BinaryNode<T> * curr, T target) {
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

    void insert_recursive(BinaryNode<T> * & curr, T new_data) {
        // Base case: if curr is nullptr, put new_data here!
        if (curr == nullptr)
            curr = new BinaryNode<T>(new_data);
        
        // Recursive case: check if we should insert in left or right subtree
        else if (new_data <= curr->_data)
            insert_recursive(curr->_left, new_data);
        else
            insert_recursive(curr->_right, new_data);
    }

    void print_recursive(BinaryNode<T> * curr) {
        if (curr != nullptr) {
            curr->print_node();
            print_recursive(curr->_left);
            print_recursive(curr->_right);
        }
    }

    void in_order_traversal_recursive(BinaryNode<T> * curr) {
        // Implicit base case: if nullptr, do nothing
        if (curr != nullptr) {
            in_order_traversal_recursive(curr->_left);
            curr->print_node();
            in_order_traversal_recursive(curr->_right);
        }
    }

    void in_order_to_vector_recursive(BinaryNode<T> * curr, \
                                            vector<T> & numbers, int & index) {
        // Implicit base case: if nullptr, do nothing
        if (curr != nullptr) {
            in_order_to_vector_recursive(curr->_left, numbers, index);
            
            // Visit this node
            numbers[index] = curr->_data;
            index++;

            in_order_to_vector_recursive(curr->_right, numbers, index);
        }
    }

    BinaryNode<T> * _root;
};

/// Template a function in the same way we template a class
template<typename S>
void tree_sort(vector<S> & numbers) {
    BinarySearchTree<S> bst;

    for (int i = 0; i < numbers.size(); i++) {
        bst.insert(numbers[i]);
    }

    bst.in_order_to_vector(numbers);
}

template<typename printing>
ostream & operator<<(ostream & out, const vector<printing> & vect) {
    out << "{";

    for (int i = 0; i < vect.size() - 1; i++) {
        out << vect[i] << ", ";
    }

    out << vect[vect.size() - 1] << "}";

    return out;
}


int main() {

    BinarySearchTree<int> bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    bst.insert(70);
    bst.insert(5);
    bst.insert(2); 
    bst.insert(-6); 
    bst.insert(8); 
    bst.in_order_traversal();

    BinarySearchTree<double> bst_doubles;
    bst_doubles.insert(3.1415);
    bst_doubles.insert(2000.3);
    bst_doubles.insert(-42.234567);
    bst_doubles.insert(0.0);
    bst_doubles.insert(4023.23232);
    bst_doubles.in_order_traversal();

    BinarySearchTree<string> names;
    names.insert("Fred");
    names.insert("George");
    names.insert("Ron");
    names.insert("Charlie");
    names.insert("Ginny");
    names.insert("Bill");
    names.insert("Percy");
    names.in_order_traversal();

    vector<string> animals = {"Dog", "Elephant", "Zebrafish", "Canary", "Mouse", "Crow"};
    tree_sort(animals);
    cout << animals << endl;



}