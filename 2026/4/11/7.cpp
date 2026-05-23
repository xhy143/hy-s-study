#include<bits/stdc++.h>
using namespace std;
int dp[10001],n,a[100001];
int g[10001][10001];
int jl[10001],ans,pos;
void DFS(int x){
	if(jl[x]) DFS(jl[x]);
	cout<<x<<" ";
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            int e;
            cin>>e;
            g[i][j]=e;
        }
    }
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=a[i];
        for(int j=1;j<=n-i;j++){
            if(g[j][i]==1&&dp[i]<dp[j]+a[i]){
                dp[i]=dp[j]+a[i];
                jl[i]=j;
            }
        }
        if(ans<dp[i]){
			 ans=dp[i];
			 pos=i;
        }
		
    }
    DFS(pos);
    cout<<ans<<endl;    
    return 0;
}