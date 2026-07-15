#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000001];
int lg[100001],f[100001][20];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    lg[1]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][0]=a[i];
    }
    for(int i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
    }
    for(int j=1;j<=lg[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=__gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    while(m--){
        int l,r;
        cin>>l>>r;
        int k=lg[r-l+1];
        cout<<__gcd(f[l][k],f[r-(1<<k)+1][k])<<'\n';
    }
}