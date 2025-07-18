#include <iostream>
#include <vector>
#include <algorithm> // Diperlukan untuk std::sort

using namespace std;

// Fungsi untuk melakukan Binary Search pada vector yang sudah terurut.
// Mengembalikan indeks elemen jika ditemukan, atau -1 jika tidak ditemukan.
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    // Lakukan perulangan selama rentang pencarian masih valid (left <= right)
    while (left <= right) {
        // Hitung titik tengah untuk menghindari overflow
        int mid = left + (right - left) / 2;

        // Cek apakah elemen di tengah adalah target
        if (arr[mid] == target) {
            return mid; // Target ditemukan, kembalikan indeksnya
        }

        // Jika target lebih besar, abaikan separuh bagian kiri
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // Jika target lebih kecil, abaikan separuh bagian kanan
        else {
            right = mid - 1;
        }
    }

    // Jika loop selesai tanpa menemukan target, kembalikan -1
    return -1;
}

// Fungsi bantuan untuk mencetak isi vector
void printVector(const vector<int>& vec) {
    for (int number : vec) {
        cout << number << " ";
    }
    cout << endl;
}

int main() {
    // Contoh vector yang belum terurut
    vector<int> numbers = {90, 11, 22, 64, 12, 25, 34};
    
    // Binary Search memerlukan data yang terurut, jadi kita urutkan terlebih dahulu
    sort(numbers.begin(), numbers.end());

    cout << "Data yang sudah diurutkan: ";
    printVector(numbers);

    // Minta pengguna memasukkan angka yang ingin dicari
    int target_value;
    cout << "\nMasukkan angka yang ingin Anda cari: ";
    cin >> target_value;

    // Panggil fungsi binarySearch
    int result_index = binarySearch(numbers, target_value);

    // Tampilkan hasilnya
    if (result_index != -1) {
        cout << "Angka " << target_value << " ditemukan pada indeks: " << result_index << endl;
    } else {
        cout << "Angka " << target_value << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}
