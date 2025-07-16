#include <iostream>

using namespace std;
int main() {
    int Limak, Bob;
    cin >> Limak >> Bob;
    int years = 0;
    while (Limak <= Bob) {
        Limak *= 3; 
        Bob *= 2;   
        years++;    
    }
    cout << years << endl; 
    return 0;
}