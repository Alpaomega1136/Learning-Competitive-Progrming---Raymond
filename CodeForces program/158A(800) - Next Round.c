// Link : https://codeforces.com/problemset/problem/158/A
#include <stdio.h>

int main(){
    int n, pass, count = 0;
    scanf("%d %d", &n, &pass);
    int scores[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &scores[i]);
    }
    for(int i = 0; i < n; i++){
        if(scores[i] >= scores[pass - 1] && scores[i] > 0){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}