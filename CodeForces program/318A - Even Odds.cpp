// Link : https://codeforces.com/problemset/problem/318/A

#include <iostream>
using namespace std;

int main() {
    long long int number, index;
    cin >> number >> index;
    long long int oddCount = number / 2 + (number % 2);
    if(index <= oddCount) {
        cout << 2 * index - 1 << endl; // Odd numbers
    } else {
        cout << 2 * (index - oddCount) << endl; // Even numbers
    }
    return 0;
}