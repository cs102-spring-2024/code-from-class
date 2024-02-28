#include <iostream>

using namespace std;

class Stack {
public:
    // Default Constructor:
    Stack() {
        _size = 0;
        _capacity = 1;
        _stack = new int[_capacity];
    }

    // Constructor with 1 parameter
    Stack(int initial_capacity) {
        _size = 0;
        _capacity = initial_capacity;
        _stack = new int[_capacity];
    }

    // Destructor
    ~Stack() {
        // cout << "We're in the destructor!" << endl;
        delete[] _stack;
    }

    /**
     * @brief Pushes item onto the stack
     * 
     * @param item 
     */
    void push(int item) {
        if (_size == _capacity) {
            resize();
        }

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
    int _capacity;
    int * _stack;

    /**
     * @brief Makes the stack able to hold 1 more element
     *  - increment capacity
     *  - make a new array with 1 more element
     * 
     * Also: delete the old array!
     * 
     */
    void resize() {
        // cout << "Resizing from old capacity: " << _capacity << endl;
        // Create a reference to the old stack for copying over and deleting
        int * old_stack = _stack;

        // Increase the capacity and make a new array
        _capacity++;
        // _capacity *= 2;
        // _capacity += 100;
        _stack = new int[_capacity];

        // Copy old stack into new stack:
        for (int i = 0; i < _size; i++) {
            _stack[i] = old_stack[i];
        }

        delete[] old_stack;
    }
};

int main() {

    Stack history;
    // Stack history(); // NOT equivalent to above; defines a new function called history

    // Stack history(100000);
    // Stack history = Stack(100000); // equivalent to above


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

    history.push(-23);
    history.display();
    history.push(7);
    history.display();
    history.push(900);
    history.display();
    history.push(1);
    history.display();
    history.push(0);
    history.display();



    for (int i = 0; i < 100000; i++) {
        cout << "i = " << i << endl;
        history.push(i);
    }



}
