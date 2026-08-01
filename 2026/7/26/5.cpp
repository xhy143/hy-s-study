#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main(){
    int n,m;
    cin>>n>>m;
    int ans=1e9;
    for(int i=1;i<=n;i++){
        int maxx=-1e9;
        for(int j=1;j<=m;j++){
            int p;
            cin>>p;
            maxx=max(maxx,p);
        }
        ans=min(ans,maxx);
    }
    cout<<ans;
}