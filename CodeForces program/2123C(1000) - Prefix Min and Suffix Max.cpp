#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Diperlukan untuk std::min dan std::max

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Jika hanya ada dua elemen, keduanya selalu bisa menang.
    if (n == 2) {
        cout << "11\n";
        return;
    }

    // 1. Pra-komputasi prefix minimum
    vector<int> prefix_min(n);
    prefix_min[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], a[i]);
    }

    // 2. Pra-komputasi suffix maximum
    vector<int> suffix_max(n);
    suffix_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_max[i] = max(suffix_max[i + 1], a[i]);
    }

    string result = "";
    // 3. Iterasi dan cek kondisi untuk setiap elemen
    for (int i = 0; i < n; ++i) {
        bool can_win = false;

        // Cek kondisi untuk elemen pertama
        if (i == 0) {
            can_win = true;
        } 
        // Cek kondisi untuk elemen terakhir
        else if (i == n - 1) {
            can_win = true;
        } 
        // Cek kondisi untuk elemen di tengah
        else {
            // Kondisi menang: lebih kecil dari min di kiri ATAU lebih besar dari max di kanan
            if (a[i] < prefix_min[i - 1] || a[i] > suffix_max[i + 1]) {
                can_win = true;
            }
        }

        if (can_win) {
            result += '1';
        } else {
            result += '0';
        }
    }
    cout << result << "\n";
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
