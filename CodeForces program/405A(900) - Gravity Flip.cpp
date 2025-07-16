// Link : https://codeforces.com/problemset/problem/405/A
#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int i, j, k;
    int n_left = mid - left + 1; // panjang dari array kiri
    int n_right = right - mid; // panjang dari array kanan
    int leftArr[n_left], rightArr[n_right]; // inisialisasi array yang ada pada kiri dan kanan

    // mengisi array kiri
    for(i = 0; i < n_left; i++)
        leftArr[i] = a[left + i];
    
    // mengisi array kanan
    for(j = 0; j < n_right; j++)
        rightArr[j] = a[mid + 1 + j];

    i = 0; // index untuk array kiri
    j = 0; // index untuk array kanan
    k = left; // index untuk array utama

    while(i < n_left && j < n_right){
        if(leftArr[i] <= rightArr[j]){
            a[k] = leftArr[i];
            i++;
        } else {
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n_left){
        a[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n_right){
        a[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right){
    if(left < right){
        int mid = left + (right - left) /  2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        
        merge(a, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}