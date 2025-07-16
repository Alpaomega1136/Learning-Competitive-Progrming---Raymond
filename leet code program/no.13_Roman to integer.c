#include<stdio.h>
int romanToInt(char* s) {
    int str_len = strlen(s);
    int hasil = 0;
    for(int i = 0;i < str_len;i++){
        if(s[i]== 'M'){
            hasil+=1000;
        }
        else if(s[i]=='D'){
            hasil+=500;
        }
        else if(s[i]=='C'){
            if(s[i+1]== 'D'){
                hasil+=400;
                i++;
            }
            else if(s[i+1]== 'M'){
                hasil +=900;
                i++;
            }
            else{
                hasil+=100;
            }
        }
        else if(s[i]=='L'){
            hasil+=50;
        }
        else if(s[i]=='X'){
            if(s[i+1]== 'L'){
                hasil+=40;
                i++;
            }
            else if(s[i+1]== 'C'){
                hasil +=90;
                i++;
            }
            else{
                hasil+=10;
            }
        }
        else if(s[i]=='V'){
            hasil+=5;
        }
        else if(s[i]=='I'){
            if(s[i+1]== 'V'){
                hasil+=4;
                i++;
            }
            else if(s[i+1]== 'X'){
                hasil +=9;
                i++;
            }
            else{
                hasil++;
            }
        }
    }
    return hasil;
}