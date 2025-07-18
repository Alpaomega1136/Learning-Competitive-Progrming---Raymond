// Link : https://codeforces.com/contest/2126/problem/0

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int minDigit = 10;
        for (char c : s) {
            minDigit = min(minDigit, c - '0');
        }
        cout << minDigit << endl;
    }
    return 0;
}