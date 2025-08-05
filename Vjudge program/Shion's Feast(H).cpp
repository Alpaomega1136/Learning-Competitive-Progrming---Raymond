// Link : https://vjudge.net/contest/733687#problem/H

#include <bits/stdc++.h>
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

    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

void removeDuplicates(vector<int>& sorted_vec) {
    auto last = unique(sorted_vec.begin(), sorted_vec.end());
    sorted_vec.erase(last, sorted_vec.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int M, K;
        cin >> M >> K;
        vector<int> Arr;
        for(int i = 0; i < M; i++) {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        mergeSort(Arr, 0, M - 1);
        removeDuplicates(Arr);
    }
}