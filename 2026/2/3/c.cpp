#include<bits/stdc++.h>
using namespace std;
#define int long long
multiset<int>s,b;

int ans=0;
void ins(int n){
    if(!s.empty()&&*(--s.end())>=n){
        s.insert(n);
    }else b.insert(n);
}
void cl(int k){
    while(s.size()<k){
        s.insert(*b.begin());
        b.erase(b.begin());
    }
    while(s.size()>k){
        multiset<int>::iterator it=--s.end();
        b.insert(*it);
        s.erase(it);
    }
}
void remove(int n){
    if(s.count(n)){
        s.erase(s.find(n));
    }else b.erase(b.find(n));
}
void del(){
    while(!b.empty()){
        b.erase(--b.end());
    }
    while(!s.empty()){
        s.erase(--s.end());
    }
}
int a[114514191];
signed main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(m=1;m<=n;m+=2){
    int k=m/2+1;
    
    for(int j=1;j<=m;j++) ins(a[j]);
    cl(k);
    ans+=*--s.end();
    for(int i=m+1;i<=n;i++){
        ins(a[i]);
        remove(a[i-m]);
        cl(k);
        ans+=*--s.end();
    }
    del();
    }
    cout<<ans;
    return 0;
}