#include<bits/stdc++.h>
using namespace std;
int n,m,ans,tmp,sum[101][101];
char mp[101][101];
int jc(int a,int b,int c,int d){
	int cnt=sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
	if(2*cnt==(c-a+1)*(d-b+1)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j]-'0';
		}
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) {
			for (int k = i; k <= n; k++) {
				for (int z = j; z <= m; z++) {
					if (jc(i, j, k, z)){
						ans = max(ans, (k - i + 1) * (z - j + 1));
					}
						
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}