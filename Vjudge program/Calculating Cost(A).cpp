// Link  : https://vjudge.net/contest/733687#problem/A

#include <iostream>
#include <vector>

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


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mean = 0,n;
    vector<int> arr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
        mean += x;
    }
    cout << mean / n << endl;
    mergeSort(arr, 0, n - 1);
    if(n % 2 == 0){
        cout << (arr[n / 2 - 1] + arr[n / 2]) / 2 << endl;
    } else {
        cout << arr[n / 2] << endl;
    }
    int currentnum = arr[0], modus = arr[0], total = 1, maxcount = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] == currentnum){
            total++;
        } else {
            if(total >= maxcount){
                maxcount = total;
                modus = currentnum;
            }
            currentnum = arr[i];
            total = 1;
        }
    }
    if(total >= maxcount){
        modus = currentnum;
    }
    cout << modus << endl;
    return 0;
}