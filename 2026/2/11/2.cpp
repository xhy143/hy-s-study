#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,son[100005];
vector<int>ve[100005];
void dfs(int u,int fa){
	son[u] = 1;
	int l;
	l = ve[u].size();
	for(int i = 0;i<l;i++){
		if(ve[u][i] == fa){
			continue;
		}
		dfs(ve[u][i],u);
		son[u] = son[u]+son[ve[u][i]];
	}
}
signed main(){
	cin>>n;
	for(int i = 1;i<n;i++){
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	if(n%2){
		cout<<-1<<endl;
		return 0;
	}
	dfs(1,0);
	int ans;
	ans = -1;
	for(int i = 1;i<=n;i++){
		if(son[i]%2 == 0){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

