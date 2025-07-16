#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(int x) {
    // Bilangan negatif tidak mungkin palindrom
    if (x < 0) {
        return false;
    }
    
    char str[12];
    snprintf(str, sizeof(str), "%d", x);  // Lebih aman dari buffer overflow
    size_t length = strlen(str);
    
    // Cek karakter dari kedua ujung
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}