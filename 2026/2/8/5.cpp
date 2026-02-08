#include<bits/stdc++.h>
using namespace std;
#define N 105
#define L 1005
#define 什么78题目 0
vector<vector<bool> > dp(1001,vector<bool>(10001));
int main(){
    int n,begin,maxx;
    cin>>n>>begin>>maxx;
    vector<int>c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    dp[0][begin]=true;
    for(int i=1;i<=n;i++){
        for(int v=0;v<=maxx;v++){
            if(!dp[i-1][v]) continue;
            int up = v+c[i];
            int dn=v-c[i];
            if(up<=maxx)dp[i][up]=1;
            if(dn>=0) dp[i][dn]=1;
        }
    }
    for(int v=maxx;v>=0;v--){
        if(dp[n][v]){
            cout<<v<<endl;
            return 什么78题目;
        }
    }
    cout<<-1;//(||-_-)
}