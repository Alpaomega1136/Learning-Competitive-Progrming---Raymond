// link : https://codeforces.com/problemset/problem/71/A
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    typedef struct {
        char word[101];
    } Word;
    Word tempat[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", tempat[i].word);
    }
    for(int i = 0; i < n; i++) {
        int Length = 0;
        while (tempat[i].word[Length] != '\0' && tempat[i].word[Length] != '\n') {
            Length++;
        }
        if (Length > 10) {
            printf("%c%d%c\n", tempat[i].word[0], Length - 2, tempat[i].word[Length - 1]);
        } else {
            printf("%s\n", tempat[i].word);
        }
    }
    return 0;
}