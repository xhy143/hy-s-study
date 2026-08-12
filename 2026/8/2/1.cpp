#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,maxn=1e3+5,maxm=2e2+5;
int dp[2][maxm][maxm][2],n,m,k;
void add(int &x,int y){
    (x+=y)%=mod;
}
signed main(){
    cin>>n>>m>>k;
    string a,b;
    cin>>a>>b;
    dp[0][0][0][0]=1;
    int t=0;
    for(int i=1;i<=n;i++){
        t^=1;
        memset(dp[t],0,sizeof(dp[t]));
        for(int j=0;j<=m;j++){
            for(int x=0;x<=k;x++){
                add(dp[t][j][x][0],dp[t^1][j][x][0]);
                add(dp[t][j][x][0],dp[t^1][j][x][1]);
                if(j>0&&a[i-1]==b[j-1]){
                    add(dp[t][j][x][1],dp[t^1][j-1][x][1]);
                    if(x>0){
                        add(dp[t][j][x][1],dp[t^1][j-1][x-1][0]);
                        add(dp[t][j][x][1],dp[t^1][j-1][x-1][1]);
                    }
                }
            }
        }
    }
    cout<<(dp[t][m][k][0]+dp[t][m][k][1])%mod;
}