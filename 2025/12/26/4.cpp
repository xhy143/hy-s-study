#include<bits/stdc++.h>
using namespace std;
int main(){
    string a[10001];
    int n,m,x,y,k,z;
    cin>>n>>m>>x>>y>>k>>z;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=x-1;i<y;i++){
        for(int j=k-1;j<z;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}