#include<bits/stdc++.h>
using namespace std;
multiset<int>s,b;
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
int a[114514191];
int main(){
    int n,m;
    cin>>n>>m;
    int k=m/2+1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=1;j<=m;j++) ins(a[j]);
    cl(k);
    cout<<*--s.end()<<endl;
    for(int i=m+1;i<=n;i++){
        ins(a[i]);
        remove(a[i-m]);
        cl(k);
        cout<<*--s.end()<<endl;
    }
    return 0;
}