#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100001],b[100001];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        a[i]=p+a[i-1];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cout<<a[y]-a[x-1]<<endl;
    }
}