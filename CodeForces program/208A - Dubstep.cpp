// Link : https://codeforces.com/problemset/problem/208/A
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int wordSpaceChecks = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'W' && s[i + 1] == 'U' && s[i+2] == 'B'){
            if(wordSpaceChecks == 1) {
                cout << " ";
            }
            i += 2; // Skip the next two characters
        }
        else {
            cout << s[i];
            wordSpaceChecks = 1; // Set flag to indicate a word has been printed
        }
    }
    cout << endl;
    return 0;
}

