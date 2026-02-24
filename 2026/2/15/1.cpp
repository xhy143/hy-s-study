#include<bits/stdc++.h>
using namespace std;
int n,m,a[21],dp[33334],sum;
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j<=33333;j++){
			dp[j]=max(dp[j],dp[j-i]+a[i]);
		}
	}
	int i=0,k=0;
	cin>>m>>s;
	s=s+"#  ";
	while(i<=m){
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
			i+=3;
			k++;
		}
		else{
			i++;
			sum+=dp[k];
			k=0; 
		}
	}
	cout<<sum;
	return 0;
}
