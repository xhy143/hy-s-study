#include <bits/stdc++.h>
using namespace std;
int n,a[1000007],ans;
int fa[1000007];
int find(int x){
	if(fa[x]==x) return x;
	int a=find(fa[x]);
	return fa[x]=a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(find(a[i])==i){
			fa[i]=i;ans++;
		}
		else fa[i]=a[i];
	}
	cout<<ans;
    return 0; 
}
