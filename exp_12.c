#include<stdio.h>
#include<string.h>
char sen[200];
char tar[200];
int mark[200];
///E --> E+E | E-E | E*E | E/E | (E) | a | b | c
struct st{
    int value;
    int index;
}ar[200];

void Sort(int n)
{
    int i, j, a, b;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (ar[i].value < ar[j].value)
            {
                a =  ar[i].value;  b=ar[i].index;
                ar[i].value = ar[j].value;
                ar[i].index = ar[j].index;
                ar[j].value = a; ar[j].index=b;
            }
        }
    }
}



int main()
{
    ///'mark' array ke 0 korte hobe
    int a, b, i, j=0, n;
    char sign;

    strcpy(tar, "a+b*d/e");

    n=strlen(tar);
    printf("Given: %s\n", tar);
    for(i=0; tar[i] ; i++)
    {
        sign=tar[i];
            switch (sign){
            case '+':
                ar[j].index=i; ar[j++].value=1;
                break;
            case '-':
                ar[j].index=i; ar[j++].value=2;
                break;
            case '*':
                ar[j].index=i; ar[j++].value=3;
                break;
            case '/':
                ar[j].index=i; ar[j++].value=4;
                break;
            }
    }

    //sort(ar, ar+j, compare);
    Sort(j);
    int k, l;
    printf("E\n");
    for(i=0; i<j ; i++)
    {
        mark[ar[i].index]=1;
        mark[ar[i].index-1]=1;
        mark[ar[i].index+1]=1;

        int ok=1;
        for(k=0;k<n;k++){
            if(mark[k]){
                if(k%2==1){ printf("%c", tar[k]); ok=1;}
                else if(ok){printf("E"); ok=0;}
            }
        }
        puts("");
    }
    for(i=0; i<=j ; i++)
    {
        for(k=0,l=0;k<n;k++){
            if(mark[k]){
                if(k%2==1)printf("%c", tar[k]);
                else if(l<=i){printf("%c",tar[k]);l++;}
                else printf("E");
            }
        }
        puts("");
    }
    return 0;
}
