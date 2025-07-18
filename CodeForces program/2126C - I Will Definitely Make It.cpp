// Link : https://codeforces.com/contest/2126/problem/C

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftVec(n1), rightVec(n2);

    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Merge the sorted halves
        merge(vec, left, mid, right);
    }
}

void solve() {
    int n,idxNow;
    cin >> n >> idxNow;
    vector<int> a(n);
    int maxNum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > maxNum) {
            maxNum = a[i];
        }
    }
    int numNow = a[idxNow - 1];
    mergeSort(a, 0, n - 1);
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());
    for(int i = 0; i < n; i++) {
        if(a[i] == numNow) {
            idxNow = i + 1;
            break;
        }
    }
    int waterLevel = 0;
    for(int i = idxNow - 1; i < n; i++) {
        if(a[i] == maxNum) {
            cout << "YES\n";
            return;
        }
        else{
            if(a[i+1] - a[i] > a[i] - waterLevel) {
                cout << "NO\n";
                return;
            }
            waterLevel += a[i+1] - a[i];
        }
    }
}


int main () {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}