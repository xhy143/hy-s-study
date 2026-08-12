#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt[10];
string s,str;
string a[7]={"1869","1968","1689","6198","1698","1986","1896"};
signed main(){
    cin>>str;
    for(auto t:str){
        cnt[t-'0']++;
    }
    cnt[1]--,cnt[6]--;cnt[8]--,cnt[9]--;
    int r=0;
    s="";
    for(int i=1;i<=9;i++){
        for(int j=1;j<=cnt[i];j++){
            s+=char('0'+i);
            r=(r*10+i)%7;
        }
    }
    r=(r*10000)%7;
    if(r==0)s+=a[0];
    else s+=a[7-r];
    for(int i=1;i<=cnt[0];i++){
        s+='0';
    }
    cout<<s<<endl;
    return 0;
}