#include<bits/stdc++.h>
using namespace std;
const int N=11,mod=10;
int n,ans,dp[N][N][N][N][N];
int main()
{
	cin>>n;
    if(n==1){
        cout<<81<<endl;
        return 0;
    }
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		for(int j=1;j<=9;j++)
		{
			dp[(a+j)%mod][b][c][d][e]++;
			dp[a][(b+j)%mod][c][d][e]++;
			dp[a][b][(c+j)%mod][d][e]++;
			dp[a][b][c][(d+j)%mod][e]++;
			dp[a][b][c][d][(e+j)%mod]++;
			dp[(a+j)%mod][(b+j)%mod][c][d][e]++;
			dp[a][(b+j)%mod][(c+j)%mod][d][e]++;
			dp[a][b][(c+j)%mod][(d+j)%mod][e]++;
			dp[a][b][c][(d+j)%mod][(e+j)%mod]++;
		}
	}
	for(int i=0;i<=9;i++)
	    for(int j=0;j<=9;j++)
	        for(int k=0;k<=9;k++)
	            for(int u=0;u<=9;u++)
	                for(int v=0;v<=9;v++)
	                    if(dp[i][j][k][u][v]==n)ans++;
	cout<<ans;
	return 0;
}
