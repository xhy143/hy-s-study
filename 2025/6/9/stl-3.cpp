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
    for(int i:a){
        cout<<i<<' ';
    }
}