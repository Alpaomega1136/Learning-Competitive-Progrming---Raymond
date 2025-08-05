// LInk : https://codeforces.com/problemset/problem/2121/D

#include <iostream>
#include <vector>

using namespace std;

int main ()  {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int size;
        cin >> size;
        int A[size];
        for(int j = 0; j < size; j++) {
            cin >> A[j];
        }
        int B[size];
        for(int j = 0; j < size; j++) {
            cin >> B[j];
        }
        int countOperations = 0;
        vector<pair<int,int>> operations;
        for(int i = 0; i < size; i++) {
            if(A[i] > B[i]) {
                swap(A[i], B[i]);
                countOperations++;
                operations.push_back({3, i + 1});
            }
        }
        for(int j = 0; j < size - 1; j++) {
            for(int k = 0; k < size - 1 - j; k++) {
                if(A[k] > A[k + 1]) {
                    swap(A[k], A[k + 1]);
                    countOperations++;
                    operations.push_back({1, k + 1});
                }
            }
        }
        for(int j = 0; j < size - 1; j++) {
            for(int k = 0; k < size - 1 - j; k++) {
                if(B[k] > B[k + 1]) {
                    swap(B[k], B[k + 1]);
                    countOperations++;
                    operations.push_back({2, k + 1});
                }
            }
        }  
        cout << countOperations << endl;
        for(auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }
}