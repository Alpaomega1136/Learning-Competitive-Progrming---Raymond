// Link : https://codeforces.com/problemset/problem/1/A
#include <iostream>

using namespace std;

int main() {
    long long int n, m, a;
    cin >> n >> m >> a;
    long long int totalTiles = 0;
    if(n % a != 0){
        totalTiles += (n / a) + 1;
    }
    else {
        totalTiles += (n / a);
    }
    if(m % a != 0){
        totalTiles *= (m / a) + 1;
    }
    else {
        totalTiles *= (m / a);
    }
    cout << totalTiles << endl;
    return 0;
}