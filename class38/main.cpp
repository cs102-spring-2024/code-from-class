#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

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

    BinarySearchTree<std::string> names;
    names.insert("Fred");
    names.insert("George");
    names.insert("Ron");
    names.insert("Charlie");
    names.insert("Ginny");
    names.insert("Bill");
    names.insert("Percy");
    names.in_order_traversal();

    std::vector<string> animals = {"Dog", "Elephant", "Zebrafish", "Canary", "Mouse", "Crow"};
    tree_sort(animals);
    cout << animals << endl;
}