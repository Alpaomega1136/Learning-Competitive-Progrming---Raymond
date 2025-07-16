// Link : https://codeforces.com/problemset/problem/339/A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Diperlukan untuk fungsi std::sort

int main() {
    // Mengatur agar input/output berjalan lebih cepat (opsional, tapi bagus untuk competitive programming)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 1. Baca seluruh baris input sebagai sebuah string
    std::string s;
    std::cin >> s;

    // 2. Ekstrak hanya angka-angkanya dan simpan ke dalam vector
    // Vector adalah array dinamis yang ukurannya bisa berubah-ubah.
    std::vector<char> numbers;
    for (char c : s) {
        // Jika karakter bukan '+', maka itu adalah angka.
        if (c != '+') {
            numbers.push_back(c);
        }
    }

    // 3. Urutkan vector yang berisi angka-angka tersebut
    // std::sort akan mengurutkan dari yang terkecil ke terbesar.
    std::sort(numbers.begin(), numbers.end());

    // 4. Cetak kembali hasilnya dengan format yang benar
    for (size_t i = 0; i < numbers.size(); ++i) {
        // Cetak angka saat ini
        std::cout << numbers[i];
        
        // Jika ini bukan angka terakhir, cetak tanda '+'
        if (i < numbers.size() - 1) {
            std::cout << "+";
        }
    }
    
    // Cetak baris baru di akhir
    std::cout << std::endl;

    return 0;
}
