#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1000;

class Stack {
public:
    // Constructor:
    Stack() {
        _size = 0;
    }

    /**
     * @brief Pushes item onto the stack
     * 
     * @param item 
     */
    void push(int item) {
        if (_size == MAX_STACK_SIZE)
            throw out_of_range("Trying to push an item onto a stack that is at its maximum size.");

        _stack[_size] = item;
        _size++;
    }

    /**
     * @brief Returns the top element of the stack
     * 
     * @return int 
     */
    int top() {
        if (empty())
            throw out_of_range("Trying to top an empty stack.");

        return _stack[_size - 1];
    }

    /**
     * @brief Removes and returns the top item on the stack.
     * 
     * @return int 
     */
    int pop() {
        if (empty())
            throw out_of_range("Trying to pop an empty stack.");

        _size--;
        return _stack[_size];
    }

    /**
     * @brief Prints the stack
     * 
     */
    void display() {
        cout << "Stack[ ";
        for (int i = 0; i < _size; i++) {
            if (i == _size - 1)
                cout << _stack[i];
            else
                cout << _stack[i] << ", ";
        }

        cout << endl;
    }

    /**
     * @brief Returns the size of the stack
     * 
     * @return int 
     */
    int size() {
        return _size;
    }

    /**
     * @brief Returns true if the stack is empty
     * 
     * @return true 
     * @return false 
     */
    bool empty() {
        return _size == 0;
    }


private:
    int _size;
    int _stack[MAX_STACK_SIZE];
};

int main() {

    Stack history;
    history.push(14);
    cout << "top = " << history.top() << endl;
    history.push(299);
    cout << "top = " << history.top() << endl;
    history.push(50);
    cout << "top = " << history.top() << endl;
        
    history.display();
    cout << "Size = " << history.size() << endl;
    cout << "Is the stack empty? " << history.empty() << endl;

    cout << endl;
    cout << "pop = " << history.pop() << endl;
    cout << "pop = " << history.pop() << endl;

    history.display();

    cout << "pop = " << history.pop() << endl;
    cout << "Is the stack empty? " << history.empty() << endl << endl;


    // Uncomment to check if our exceptions are working
    /*
    history.pop();
    history.pop();
    history.pop();
    // cout << history.top() << endl;
    // history.pop();

    for (int i = 0; i < MAX_STACK_SIZE + 1; i++) {
        cout << "i = " << i << endl;
        history.push(i);
    }
    */


    Stack piles_of_pancakes[4];

    piles_of_pancakes[2].push(123);
    piles_of_pancakes[0].push(55);

    for (int i = 0; i < 4; i++) {
        piles_of_pancakes[i].push(i);
        piles_of_pancakes[i].push(500);
    }
    for (int i = 0; i < 4; i++) {
        piles_of_pancakes[i].display();
    }


    /// The following were to find out when bad things were happening
    /*
    // for (int i = 0; i < MAX_STACK_SIZE * 10; i++) {
    //     history.push(1);
    // }

    history.push(5.2);
    history.push('%');
    history.push('H');
    // history.push("hi there");
    history.display();

    for (int i = 0; i < 50000000; i++) {
        history.pop();
    }
    history.display();
    */

}
