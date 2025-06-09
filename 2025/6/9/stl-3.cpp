#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a.insert(p);
    }
    cout<<a.size()<<endl;
    set<int>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        cout<<*it;
    }
}