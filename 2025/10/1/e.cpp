#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;
int x,s,t; 
char c;
int main(){
    cin>>t;
    while(scanf("%c",&c) && c != '\n'){ 
        cin>>x;
        if(c == '*') t = t * x % mod; 
        else s = (s + t) % mod,t = x;
    }
    cout<<(s+t)%mod;
    return 0;
}
