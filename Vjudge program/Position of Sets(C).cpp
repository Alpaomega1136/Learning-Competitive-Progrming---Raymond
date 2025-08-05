// Link : https://vjudge.net/contest/733687#problem/C

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<long long>& vec, int left, int mid, int right) {
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

void mergeSort(vector<long long>& vec, int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        string s;
        long long x;
        cin >> s >> x;
        arr.push_back(x);
    }
    mergeSort(arr, 0, n - 1);
    long long probability = 1;
    long long currentDif = arr[0];
    long long times = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == currentDif){
            times++;
            probability *= times;
        }
        else{
            currentDif = arr[i];
            times = 1;
        }
        probability %= 1000000007;
    }
    cout << probability << endl;
}