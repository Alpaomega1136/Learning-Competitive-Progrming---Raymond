// Link : https://vjudge.net/contest/733687#problem/B
#include <iostream>
#include <vector>

using namespace std;

void sortSecondary(vector<pair<string,int>>& arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j].second > arr[j + 1].second){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortPrimary(vector<pair<string,int>>& arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            string currentTitle = arr[j].first;
            string nextTitle = arr[j + 1].first;
            if(int(currentTitle[0]) > int(nextTitle[0])){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<string,int>> arr;
    for(int i = 0;i < n; i++){
        int Years;
        string Title;
        cin >> Title >> Years;
        arr.push_back(make_pair(Title, Years));
    }
    sortSecondary(arr, n);
    sortPrimary(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i].first << endl;
    }
    return 0;
}