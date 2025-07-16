#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[0] >= 'a' && s[0] <= 'z') {
        // Jika huruf pertama adalah huruf kecil, ubah menjadi huruf besar
        s[0] = toupper(s[0]);
    }
    cout << s << endl;
    return 0;
}