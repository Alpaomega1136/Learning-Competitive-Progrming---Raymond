// Link : https://codeforces.com/problemset/problem/133/A
#include <iostream>
using namespace std;
#include <string>

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        int ASCII = int(s[i]);
        if (ASCII == 72 || ASCII == 81 || ASCII == 57 ) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}