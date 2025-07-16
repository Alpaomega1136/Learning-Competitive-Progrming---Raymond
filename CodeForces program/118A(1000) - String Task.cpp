// Link : https://codeforces.com/problemset/problem/118/A
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string result = "";
    for (char c : s) {
        if (c != 'A' && c != 'O' && c != 'Y' && c != 'E' && c != 'U' && c != 'I' &&
            c != 'a' && c != 'o' && c != 'y' && c != 'e' && c != 'u' && c != 'i') {
            result += '.';
            result += tolower(c);
        }
    }
    cout << result << endl;
    return 0;
}