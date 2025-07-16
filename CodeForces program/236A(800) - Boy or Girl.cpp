#include <iostream>
#include <string>
#include <set> 

int main() {
    std::string username;
    std::cin >> username;

    // 2. Buat sebuah set untuk menampung karakter-karakter yang unik
    // Set akan secara otomatis mengabaikan duplikat.
    std::set<char> distinct_chars;

    // 3. Masukkan setiap karakter dari username ke dalam set
    for (char c : username) {
        distinct_chars.insert(c);
    }

    // 4. Dapatkan jumlah karakter unik dengan memeriksa ukuran set
    int distinct_count = distinct_chars.size();

    // 5. Cek apakah jumlahnya genap atau ganjil
    if (distinct_count % 2 == 0) {
        // Jika genap, dia adalah perempuan
        std::cout << "CHAT WITH HER!" << std::endl;
    } else {
        // Jika ganjil, dia adalah laki-laki
        std::cout << "IGNORE HIM!" << std::endl;
    }

    return 0;
}
