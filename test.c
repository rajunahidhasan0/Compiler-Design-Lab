#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int length, i, c=0, t;
char st1[1000], str[1000];
char keyword[40][50]={"auto",	"break",	"case",	"char",
            "const",	"continue",	"default",	"do",
            "double",	"else",	"enum",	"extern",
            "float",	"for",	"goto",	"if",
            "int",	"long",	"register",	"return"
            "short",	"signed",	"sizeof",	"static"
            "struct",	"switch",	"typedef",	"union"
            "unsigned",	"void",	"volatile",	"while"
            };

int func(char *st)
{
        length = strlen(st);

        if(length<=2){
                if(st[0]=='+' || st[0]=='-' || st[0]=='*' || st[0]=='/'|| st[0]=='%' || st[0]=='++' || st[0]=='--'){
                    puts("Arithmetic Operator");
                    return 0;
                }
                else if(st[0]=='==' || st[0]=='<=' || st[0]=='>=' || st[0]=='!='){
                     puts("Relational Operator");
                     return 0;
                }
                else if(st[0]=='+=' || st[0]=='-=' || st[0]=='*=' || st[0]=='/='|| st[0]=='%='){
                     puts("Assignment Operator");
                     return 0;
                }

        }
        for(i=0; i<32; i++)
        {
            if(strcmp(keyword[i],strlwr(st))==0){
                puts("Keyword");
                return 0;
            }
        }
        c=0;
        t=0;
        for(i=0; i<length; i++)
        {
            if(isdigit(st[i]))
                c++;
            if(st[i]=='.')t=1;
        }
        if(c>=length-1){
            if(c==length){puts("Integer");return 0;}
            else if(c==length-1 && t==1){puts("Float");return 0;}
        }
        c=0;
        if((st[0]>='a' && st[0]<='z')||(st[0]>='A' && st[0]<='Z')||(st[0]=='_') )
        {
            c++;
            for(i=1; i<length; i++)
            {
                if((st[i]>='a' && st[i]<='z')||(st[i]>='A' && st[i]<='Z')||(st[i]=='_') ||(st[i]>='0' && st[i]<='9') )
                    c++;
            }
        }
        if(c==length)puts("Identifier");
        else puts("Invalid");
        return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    while(scanf("%s", str)==1){

        puts("no");
       // func(st);
    }
    return 0;
}
