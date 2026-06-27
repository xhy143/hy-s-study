#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=16;
    int g[101][101];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }
}