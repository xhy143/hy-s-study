#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string v;
        cin>>v;
        a.insert(v);
    }
    cout<<52-a.size();
}