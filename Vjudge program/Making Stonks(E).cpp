//Link : https://vjudge.net/contest/733687#problem/E

#include <iostream>
#include <vector>

using namespace std;

long long CashGet(vector<pair<int, int>>& arr,long long time) {
    long long total = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].first <= time) {
            total += (time - arr[i].first) / arr[i].second;
        }
    }
    return total;
}

long long searchTime(vector<pair<int, int>>& arr, long long X, long long left, long long right) {
    if (left >= right) {
        return left;
    }
    long long mid = (left + right) / 2;
    if (CashGet(arr, mid) >= X) {
        return searchTime(arr, X, left, mid);
    } else {
        return searchTime(arr, X, mid + 1, right);
    }
}

long long rangeTime(vector<pair<int, int>>& arr, long long X, long long time) {
    if(CashGet(arr, time) >= X) {
        if(time == 1){
            return searchTime(arr, X, 1, time);
        }
        else {
            return searchTime(arr, X, time / 2, time);
        }
    }
    else {
        return rangeTime(arr, X, time * 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N ;
    long long X;
    cin >> N >> X;
    vector<pair<int,int>> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << rangeTime(arr, X, 1) << endl;
    return 0;
}