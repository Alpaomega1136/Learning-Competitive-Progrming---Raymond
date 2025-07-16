// link :  https://codeforces.com/problemset/problem/282/A
#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char operation[4];
        scanf("%s", operation);
        if(operation[1] == '+') {
            sum++;
        } else if (operation[1] == '-') {
            sum--;
        }
    }
    printf("%d\n", sum);
    return 0;
}