#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;
char sen[100];
char tar[200];

///E --> E+E | E-E | E*E | E/E | (E) | a | b | c
int ar[200];

int main()
{
    int a, b, i, j=0;
    char sign;
    strcpy(tar, "a+b*c");
    strcpy(sen, "E");
    puts(sen);
    for(i=0; tar[i] ; i++)
    {
        sign=tar[i];
            switch (sign){
            case '+':
                ar[j++]=1;
                break;
            case '-':
                ar[j++]=2;
                break;
            case '*':
                ar[j++]=3;
                break;
            case '/':
                ar[j++]=4;
                break;
            }
    }

    sort(ar, ar+j);
    reverse(ar, ar+j);
    for(i=0; i<j ; i++)
    {
            switch (ar[i]){
            case 1:
                strcat(sen, "+E");
                break;
            case 2:
                strcat(sen, "-E");
                break;
            case 3:
                strcat(sen, "*E");
                break;
            case 4:
                strcat(sen, "/E");
                break;
            }
            puts(sen);
    }
    for(i=0; tar[i] ; i++){
        if(sen[i]=='E')sen[i]=tar[i];
        puts(sen);
    }

    return 0;
}
