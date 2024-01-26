#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std;

int main() {

    cout << "This prints immediately because endl flushes the buffer." << endl;
    cout << "This remains in the buffer because no newline, and will print in 2 seconds.";

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    cout << endl;

}
