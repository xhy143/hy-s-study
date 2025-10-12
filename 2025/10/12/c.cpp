#include<bits/stdc++.h>
using namespace std;
map<int,int>a;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a[b]+=1;
    }
    
    for(auto p:a){
        cout<<p.first<<' '<<p.second<<endl;
    }
}