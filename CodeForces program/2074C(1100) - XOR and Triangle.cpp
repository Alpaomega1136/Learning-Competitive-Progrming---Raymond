#include <iostream>
#include <cmath>

using namespace std;

bool isPowerOfTwo(long long n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

void solve() {
    long long x;
    cin >> x;

    if (isPowerOfTwo(x)) {
        cout << -1 << "\n";
        return;
    }

    if ((x & (x + 1)) == 0 && x > 1) {
        cout << -1 << "\n";
        return;
    }

    long long p = 1;
    while (p <= x) {
        p *= 2;
    }
    p /= 2;

    cout << p - 1 << "\n";
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
