#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int fail[maxn];
string p,t;
int main(){
    cin>>t>>p;
    fail[0]=0;
    for(int i=1,j=0;i<p.size();i++){
        while(j&&p[i]!=p[j])j=fail[j-1];
        if(p[i]==p[j])j++;
        fail[i]=j;
    }
    int cnt=0;
    for(int i=0,j=0;i<t.size();i++){
        while(j&&t[i]!=p[j])j=fail[j-1];
        if(t[i]==p[j])j++;
        if(j==p.size()){
            cnt++;
            j=fail[j-1];
        }
    }
    cout<<cnt<<endl;
    return 0;
}