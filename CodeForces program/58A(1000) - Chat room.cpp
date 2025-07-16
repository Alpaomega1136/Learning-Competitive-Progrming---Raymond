// Link : https://codeforces.com/problemset/problem/58/A
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    string target = "hello";
    int idxTarget = 0;
    for (char c : s) {
        if (c == target[idxTarget]) {
            idxTarget++;
            if (idxTarget == target.size()) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}