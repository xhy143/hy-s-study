#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        m[x]++;
    }
    for(auto i:m){
        cout<<i.first<<' '<<i.second<<endl;
    }
    
}