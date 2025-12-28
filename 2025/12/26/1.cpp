#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    map<int,int>p;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p[x]++;
    }
    vector <int>a;
    for(auto t:p){
        a.push_back(t.first);
    }
    int ans=1;
    int cans=1;
    for(int i=1;i<p.size();i++){
        if(a[i]-a[i-1]==1){
            cans++;
        }else{
            ans=max(cans,ans);
            cans=1;
        }
    }
    ans=max(cans,ans);
    cout<<ans;
}