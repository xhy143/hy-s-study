#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define QWQ 0
const int N = 1000010, b = 131;
int h1[N], pw[N],h2[N];

void reset(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*b;
}

void Hash(string s, int* h) {
    for (int i = 1; i <= s.size(); i++) {
        h[i ] = h[i-1] * b + s[i-1];
    }
}

int cut(int* k,int l,int r){
    return k[r]-k[l-1]*pw[r-l+1];
}

signed main() {
    reset();

    string s;
    cin>>s;
    Hash(s,h1);

    string p;
    p=s;
    reverse(p.begin(),p.end());
    Hash(p,h2);

    int ans=0;
    int q;
    cin>>q;
    while(q--){

        int l,r,n=p.size();
        for(int l=0;l<s.size();l++){
            for(int r=l+1;r<s.size();r++){
        if(cut(h1,l,r)==cut(h2,n-r+1,n-l+1)){
            ans++;
        }
    }}
    }
    cout<<ans;
    return QWQ;
}