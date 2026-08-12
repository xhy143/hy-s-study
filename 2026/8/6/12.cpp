#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7,maxn=5e2+100,maxk=maxn*maxn;
int n,m,k;
signed main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    int all=n*m;
    if(k>n*m){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>>dp(all+1,vector<int>(k+1,0));
    dp[0][0]=1;
    for(int i=1;i<=all;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
            if(j>0){
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
    }
    int ans=dp[all][k];
    if(all%2==0&&k==all/2){
        cout<<ans%mod;
    }else{
        cout<<(2*ans)%mod;
    }
}