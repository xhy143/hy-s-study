#include<bits/stdc++.h>
using namespace std;
int main(){
    string a[101];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='?'){
                int ans=0;
                int dx[8]={1,0,-1,0,1,-1,1,-1},dy[8]={0,1,0,-1,1,-1,-1,1};
                for(int k=0;k<8;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]=='*'){
                        ans++;
                    }
                }
                a[i][j]=ans+'0';
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}