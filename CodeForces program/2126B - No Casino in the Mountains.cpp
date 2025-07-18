// Link : https://codeforces.com/contest/2126/problem/B

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int hikes = 0;
    for (int i = 0; i <= n - k; ) {
        bool can_hike = true;
        for (int j = 0; j < k; ++j) {
            if (a[i + j] == 1) {
                can_hike = false;
                break;
            }
        }

        if (can_hike) {
            hikes++;
            i += k + 1;
        } else {
            i++;
        }
    }

    cout << hikes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}