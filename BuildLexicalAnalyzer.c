#include<stdio.h>
int main()
{
    int length, i, c=0;
    char st[100];

    gets(st);

    length = strlen(st);

    for(i=0; i<length; i++)
    {
        if(isdigit(st[i]))
            c++;
    }
    if(length==c && st[0]!='0'){
        if(c<=4)puts("ShortInt Number");
        else puts("LongInt Number");
        return 0;
    }
    if( (st[0]>='i' && st[0]<='n')||(st[0]>='I' && st[0]<='N') )
    {
        c=0;
        for(i=1; i<length; i++)
        {
            if( (st[0]>='a' && st[0]<='z')||(st[0]>='A' && st[0]<='Z')||(st[0]>='0' && st[0]<='9') )c++;
        }
        if(c==length-1){
            puts("Integer Variable");
        }
        return 0;
    }

    puts("Invalid input");

    return 0;
}
