// Link : https://codeforces.com/problemset/problem/1374/B
#include <iostream>
using namespace std;

int CheckNumber(int number){
    if(number == 1) {
        return 0; // 1 is not a prime number
    }
    else{
        int powerOf2 = 0;
        int powerOf3 = 0;
        while(number % 2 == 0){
            number = number / 2;
            powerOf2++;
        }
        while(number % 3 == 0){
            number = number / 3;
            powerOf3++;
        }
        if(number != 1 || powerOf2 > powerOf3) {
            return -1; // Not possible to convert to 1
        } else {
            return powerOf3 - powerOf2 + powerOf3; // Return the number of operations needed
        }
    }
}

int main() {
    int Lengthnumber;
    cin >> Lengthnumber;
    int arraynumber[Lengthnumber];
    for(int i = 0; i < Lengthnumber; i++) {
        cin >> arraynumber[i];
    }
    for(int i = 0; i < Lengthnumber; i++) {
        cout << CheckNumber(arraynumber[i]);
        if(i < Lengthnumber - 1) {
            cout << " "; // Print space between results
        }
    }
    cout << endl; // Print a newline after all results
    return 0;
}