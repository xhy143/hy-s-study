#include<iostream>
using namespace std;
bool a[114][514];
int b[1919][810];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;cin>>c;
			a[i][j]=c-'0';
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
		}
	}
	int mn=0x3f3f3f3f;
	for(int x1=0;x1<n;x1++){
		for(int y1=0;y1<m;y1++){
			for(int x2=x1;x2<=n;x2++){
				for(int y2=y1;y2<=m;y2++){
					int tmp=b[x2][y2]-b[x2][y1]-b[x1][y2]+b[x1][y1];
					if(tmp>=k)mn=min(mn,(x2-x1)*(y2-y1));
				}
			}
		}
	}
	cout<<((mn==0x3f3f3f3f)?0:mn);
	return 0;
}
