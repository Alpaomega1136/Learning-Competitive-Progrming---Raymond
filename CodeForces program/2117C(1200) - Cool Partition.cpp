// Link : https://codeforces.com/problemset/problem/2117/C
#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // --- OPTIMISASI DIMULAI DI SINI ---

    // 1. Pra-komputasi: Hitung jumlah elemen unik untuk setiap prefix.
    // distinct_counts[i] akan menyimpan jumlah elemen unik di a[0...i].
    vector<int> distinct_counts(n);
    vector<bool> seen_prefix(n + 1, false); // Menggunakan array boolean lebih cepat dari set
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!seen_prefix[a[i]]) {
            seen_prefix[a[i]] = true;
            count++;
        }
        distinct_counts[i] = count;
    }

    int segments = 0;
    int right_boundary = n - 1;

    // Loop utama sekarang jauh lebih cepat.
    while (right_boundary >= 0) {
        segments++;

        // Dapatkan jumlah unik yang dibutuhkan dari hasil pra-komputasi.
        int num_uniques_needed = distinct_counts[right_boundary];
        
        set<int> seen_in_segment;
        for (int i = right_boundary; i >= 0; --i) {
            seen_in_segment.insert(a[i]);

            if (seen_in_segment.size() == num_uniques_needed) {
                // Setelah menemukan segmen, perbarui batas dan lanjutkan.
                right_boundary = i - 1;
                break;
            }
        }
    }

    cout << segments << "\n";
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
