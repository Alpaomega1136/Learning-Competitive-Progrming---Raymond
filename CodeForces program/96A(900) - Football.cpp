// Link : https://codeforces.com/problemset/problem/96/A

#include <iostream>

using namespace std;
int main() {
    string s;
    cin >> s;
    int cek_number = s[0];
    int index = 1;
    int count = 1;
    while (index < s.length() && count < 7){
        if(cek_number == s[index]){
            count++;
        } else {
            cek_number = s[index];
            count = 1;
        }
        index++;
    }
    if(count >= 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}