// Link : https://codeforces.com/problemset/problem/230/A
#include <iostream>

using namespace std;

int main(){
    int strength, n;
    cin >> strength >> n;
    int dragons[n][2]; // Each dragon has strength and bonus
    for(int i = 0; i < n; i++){
        cin >> dragons[i][0] >> dragons[i][1]; // Read strength and bonus
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(dragons[i][0] > dragons[j][0]) {
                swap(dragons[i], dragons[j]); // Sort dragons by strength (bubble sort)
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(strength > dragons[i][0]) {
            strength += dragons[i][1]; // Increase strength by bonus
        } else {
            cout << "NO" << endl; // Not enough strength to defeat the dragon
            return 0;
        }
    }
    cout << "YES" << endl; // All dragons defeated
    return 0;
}