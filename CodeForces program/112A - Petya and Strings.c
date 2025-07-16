// Link : https://codeforces.com/problemset/problem/112/A
#include <string.h>
#include <stdio.h>

int main() {
    char str1[101], str2[101];
    scanf("%s %s", str1, str2);
    
    // Convert both strings to lowercase
    for (int i = 0; str1[i]; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] += 32; // Convert to lowercase
        }
    }
    for (int i = 0; str2[i]; i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] += 32; // Convert to lowercase
        }
    }
    // Compare the strings
    int result = strcmp(str1, str2);
    if (result < 0) {
        printf("-1\n");
    } else if (result > 0) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}