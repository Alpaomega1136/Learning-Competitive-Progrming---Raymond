// Link : https://codeforces.com/problemset/problem/580/A
#include <iostream>
using namespace std;

int main() {
    int n,currentMoney,prevMoney;
    cin >> n;
    int maxIncrease = 1, increase = 1;
    for(int i = 0; i < n; i++) {
        cin >> currentMoney;
        if(i > 0) {
            if(currentMoney >= prevMoney) {
                increase++;
            } else {
                if(increase > maxIncrease) {
                    maxIncrease = increase;
                }
                increase = 1; // Reset increase
            }
        }
        prevMoney = currentMoney; // Update previous money
    }
    if(increase > maxIncrease) {
        maxIncrease = increase; // Check last increase
    }
    cout << maxIncrease << endl; // Output the maximum increase
    return 0;
}