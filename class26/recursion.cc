#include <iostream>
using namespace std;

long fib(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    
    return fib(n - 1) + fib(n - 2);
}

long sum_0_to_n(long n) {
    if (n == 0)
        return 0;

    return n + sum_0_to_n(n - 1);
}

int main() {

    int n = 7;
    cout << "fib(" << n << ") = " << fib(n) << endl; 

    n = 15;
    cout << "fib(" << n << ") = " << fib(n) << endl;
    n = 37;
    cout << "fib(" << n << ") = " << fib(n) << endl;

    // n = 47;
    // cout << "fib(" << n << ") = " << fib(n) << endl;
    
    // n = 57;
    // cout << "fib(" << n << ") = " << fib(n) << endl;

    cout << endl;
    n = 10;
    cout << "sum of numbers 0 to " << n << " = " << sum_0_to_n(n) << endl;

    n = 100000;
    cout << "sum of numbers 0 to " << n << " = " << sum_0_to_n(n) << endl;


    //// This produces a seg fault because of a stack overflow error
    // n = 1000000;
    // cout << "sum of numbers 0 to " << n << " = " << sum_0_to_n(n) << endl;


}