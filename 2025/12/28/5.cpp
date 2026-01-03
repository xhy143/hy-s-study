#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100][100],q[100][100];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            q[i][j]=q[i-1][j]+q[i][j-1]-q[i-1][j-1]+a[i][j];
        }
    int ans=-0x3f3f3f;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            for(int nx=x;nx<=n;nx++){
                for(int ny=y;ny<=n;ny++){
                    int curans=q[nx][ny]-q[x-1][ny]-q[nx][y-1]+q[x-1][y-1];
                    ans=max(ans,curans);
                }
            }
    cout<<ans;
}