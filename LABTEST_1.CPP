#include<bits/stdc++.h>
using namespace std;
char str[200];
int len;

int isFloat(){
    if(str[0]=='0'){
        if(len==4&&str[1]=='.'){
            if((str[2]>='0'||str[2]<='9')&&(str[3]>='0'||str[3]<='9'))return 1;
        }
        return 0;
    }
    else if(str[0]>='2' && str[0]<='9')
    {
        int c=0;
        for(int i=1; str[i];i++)
        {
            if(str[i]>='0'&&str[i]<='9')c++;
            else if(str[i]=='.'){
                if(i+3==len && (str[i+1]>='0'||str[i+1]<='9')&&(str[i+2]>='0'||str[i+2]<='9'))return 1;
                return 0;
            }
            else return 0;
        }
    }
    return 0;
}
int isBinary(){
    if(str[0]!='0' || len<2)return 0;
    if(str[1]!='0' && str[1]!='1')return 0;
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
        return 1;
    }
    else return 0;
}
int isCharvar()
{
    //cout<<"why";
    if(len>=4 && str[0]=='c' && str[1]=='h' && str[2]=='_'){
        if( (str[3]>='a' && str[3]<='z') || (str[3]>='A' && str[3]<='Z') || (str[3]>='0'||str[3]<='9') ){
            for(int i=3; str[i] ;i++){
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
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

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
