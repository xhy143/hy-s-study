#include<bits/stdc++.h>
using namespace std;
queue<int>a;
queue<int>ans;
int m,n,G[101][101]={0},vis[10001]={0};
void bfs(int st){
    a.push(st);
    vis[st]=1;


    while(!a.empty()){
        int x=a.front();
        for(int i=1;i<=m;i++){
            if(G[x][i]&&!vis[i]){
                vis[i]=1;
                a.push(i);
            }
        }
        ans.push(x);
        a.pop();
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        
        G[x][y]=1;
        G[y][x]=1;
    }
    bfs(1);
    while(!ans.empty()){
        cout<<ans.front()<<' ';
        ans.pop();
    }
}