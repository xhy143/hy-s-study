#include<bits/stdc++.h>
using namespace std;
int qpow(int a,int b,int m){
    int res=1;
    while(b){
        if(b&1) res=1ll*res*a%m;
        a=1ll*a*a%m;
        b>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,m,tmp,phi=1;
    string b;
    cin>>a>>m>>b;
    a%=m,tmp=m;
    for(int i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            phi*=(i-1);
            tmp/=i;
        }
        while(tmp%i==0){
            phi*=i;
            tmp/=i;
        }
    }
    if(tmp>1)phi*=(tmp-1);
    int mod=0,flag=0;
    for(int i=0;i<b.size();i++){
        int num=b[i]-'0';
        mod=mod*10+num;
        if(mod>=phi){
            mod%=phi;
            flag=1;
        }
    }
    if(flag) mod+=phi;
    cout<<qpow(a,mod,m)<<'\n';
}