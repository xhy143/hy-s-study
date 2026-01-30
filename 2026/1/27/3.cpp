#include<bits/stdc++.h>
using namespace std;
int a[4500],dp[4500];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		    dp[j]=max(dp[j],dp[j-i]+a[i]);
		}
	}
	cout<<dp[n];
}