#include<bits/stdc++.h>
using namespace std;
map<char, string>mp;
vector<string>vt[200];
vector<char>ans;

vector<char> first(int n,int pos)
{
    vector<char>tmp, tmp2, tmp3;
    //if(!vt[n].size())return
    for(int i=0;i<vt[n].size(); i++)
    {
        if(vt[n][i][0]<'A' || vt[n][i][0]>'Z'){

            tmp.push_back(vt[n][i][0]);
        }
        else{
            tmp2=first(vt[n][i][0],0);
            for(int k=0; k<tmp2.size(); k++)
            {
                if(tmp2[k]=='x'){
                    if(vt[n][i][1]>='A'&&vt[n][i][1]<='Z')
                                tmp3=first(vt[n][i][pos+1],pos+1);
                    else tmp.push_back(tmp2[k]);
                }
                else tmp.push_back(tmp2[k]);
            }
        }
    }
    for(int i=0;i<tmp3.size(); i++)tmp.push_back(tmp3[i]);
    return tmp;
}

int main()
{
    /*
    vt['E'].push_back("TA");
    vt['A'].push_back("+TA");
    vt['A'].push_back("x");
    vt['T'].push_back("FB");
    vt['B'].push_back("*FB");
    vt['B'].push_back("x");
    vt['F'].push_back("id");
    vt['F'].push_back("(E)");*/

    vt['S'].push_back("ABbc");
    vt['A'].push_back("cB");
    vt['A'].push_back("x");
    vt['B'].push_back("d");
    vt['B'].push_back("x");

    for(int i='A' ; i<='Z' ; i++)
    {
        if(vt[i].size()){
            printf("First(%c) = {", i);
            ans=first(i, 0);
            cout<<ans[0];
            for(int j=1; j<ans.size(); j++)
            {
                cout<<", "<<ans[j];
            }
            cout<<"}"<<endl;
        }
    }
    return 0;
}
