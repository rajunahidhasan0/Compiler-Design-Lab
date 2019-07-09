#include<stdio.h>
#include<string.h>
char str[200];
int len;
int isother(){
    for(int i=0;str[i];i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')){
            continue;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int isFloat(){
    if(str[0]=='.')return 0;
    int c=0,d=0;
    for(int i=0; str[i];i++){
        if(str[i]>='0'||str[i]<='9') c++;
        else if(str[i]=='.')d++;
    }
    if(d==1 && len-1==c)return 1;
    return 0;
}
int isBinary(){
    if(str[0]!=0)return 0;
    int c=0,d=0;
    for(int i=0; str[i] ;i++){
        if(str[i]=='0'||str[i]=='1') c++;
    }
    if(len==c)return 1;
    return 0;
}
int isIntvar()
{
    if( (str[0]>='a' && str[0]<='o')||(str[0]>='A' && str[0]<='O') ){
        for(int i=1; str[i] ;i++){
            if((str[i]>='0'||str[i]<='9')|| (str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z') )continue;
            else return 0;
        }
    }
    else return 0;
    return 1;
}
int isCharvar()
{
    if(len>=4 && str[0]=='c' && str[1]=='h' && str[2]=='-'){
        if( (str[3]>='a' && str[3]<='z')||(str[3]>='A' && str[3]<='Z') || (str[3]>='0'||str[3]<='9') ){
            for(int i=1; str[i] ;i++){
                if((str[i]>='0'||str[i]<='9')|| (str[0]>='a' && str[0]<='z')||(str[0]>='A' && str[0]<='Z') )continue;
                else return 0;
            }
            return 1;
        }
        else return 0;
    }
    return 0;
}
int main()
{

    while(cin>>str)
    {
        len = strlen(str);

        if(isBinary()){
            puts("Binary Number");
        }
        else if(isCharvar())
        {
            puts("Character Variable");
        }
        else if(isIntvar())
        {
            puts("Integer Variable");
        }
        else if(isFloat()){
            puts("Float Number");
        }
        else{
            puts("Undefined");
        }
    }
    return 0;
}
