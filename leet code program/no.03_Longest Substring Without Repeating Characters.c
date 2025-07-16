#include<stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s){
    int long_s = strlen(s);
    int hasil = 0,sementara,cek = 0,k = 0;
    char huruf[long_s];
    for(int i = 0;i < long_s;i++){
        sementara = 1;
        int j = i + 1;
        for(int l = 0;l < long_s - i;l++){
            huruf[l]='0';
        }
        while (cek == 0){
            for(int k = 0;k < j;k++){
                if(huruf[k]==s[j]){
                if(hasil <= sementara){
                    hasil = sementara;}
                cek = 1;}
                else{
                    k++;
                }
            }
            sementara++;
            }
            
        }
    if(hasil <= sementara){
        hasil = sementara;
    }
return hasil;
}
