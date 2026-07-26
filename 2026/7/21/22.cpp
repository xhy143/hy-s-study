#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int fail[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        string p;
        cin>>p;
        fail[0]=0;
        int maxf=0;
        for(int i=1,j=0;i<p.size();i++){
            while(j&&p[i]!=p[j])j=fail[j-1];
            if(p[i]==p[j])j++;
            fail[i]=j;
        }
        for(int i=1;i<p.size();i++){
            maxf=max(maxf,fail[i]);
        }
        int n=p.size(),r=n-fail[n-1];
        if(n%r==0)cout<<n/r;
        else cout<<1;
        cout<<endl;
    }
    return 0;
}