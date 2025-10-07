#include<bits/stdc++.h>
using namespace std;
#define ll long long //不开long long见祖宗
int main(){
    ll ans;
    int a1,b1;
    char a[1000001];
    cin>>a;
    sscanf(a,"%d+%d=",&a1,&b1); //666sscanf输不了长整型
    ans=a1+b1;
    cout<<ans;
}