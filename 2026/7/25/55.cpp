#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int n,m;
int minn=LLONG_MAX;
int f[maxn];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int fi,se;
		cin>>fi>>se;
		f[i]=fi;
		minn=min(minn,fi+se);
	}
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++){
		f[i]+=f[i-1];
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		if(m<f[i])break;
		ans=max(ans,i+(m-f[i])/minn*2);
	}
	cout<<ans;
}