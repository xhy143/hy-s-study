#include<bits/stdc++.h>
using namespace std;
int m,n;

int main(){
    cin>>n>>m;
    vector<vector<int> > v(n+1);
    for(int i=1;i<=m;i++){
        int pos,n;
        cin>>pos>>n;
        v[pos].push_back(n);
    }
    for(int i=1;i<=n;i++){
        cout<<v[i].size()<<" ";
        sort(v[i].begin(),v[i].end());
        for(int j : v[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
