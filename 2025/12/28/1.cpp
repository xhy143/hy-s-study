#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],q[1001][1001];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            q[i][j]=q[i-1][j]+q[i][j-1]-q[i-1][j-1]+a[i][j];
    
    while(k--){
        int x1,y1,x,y;
        scanf("%d%d%d%d",&x1,&y1,&x,&y);
        printf("%d\n",(q[x][y] - q[x][y1-1] - q[x1-1][y] + q[x1-1][y1-1]));
    }
}
