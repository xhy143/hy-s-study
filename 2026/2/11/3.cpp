#include<bits/stdc++.h>
using namespace std;
int n,f[5000][5000],father[5000];
vector<int> s[5000];
void dfs(int x){
	f[x][0]=0;
	f[x][1]=1;
	if(s[x].size()==0)return;
	for(int i=0;i<s[x].size();i++){
		int y=s[x][i];
		dfs(y);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][1],f[y][0]);
	}
}
int main(){
	int n;
	cin>>n;
	int a,b,z;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		a++;
		for(int j=1;j<=b;j++){
			cin>>z;
			z++;
			s[a].push_back(z);
			father[z]=1;
		}
	}
	int root;
	for(int i=1;i<=n;i++){ 
		if(father[i]==0){
			root=i;
			break;
		}
	}
	dfs(root);
	cout<<min(f[root][0],f[root][1]);
}
