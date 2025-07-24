#include<bits/stdc++.h>
using namespace std;
int m,n,vis[100001]={0};

int bfs(int s,int e){
    queue<int>a;
    a.push(s);
    vis[s]=1;
    while(!a.empty()){
        int p=a.front();
        if(p==e){
            return vis[p]-1;
        }
        if(p-1>=0&&vis[p-1]==0){
            a.push(p-1);
            vis[p-1]=vis[p]+1;
        }
        if(p+1<=100000&&vis[p+1]==0){
            a.push(p+1);
            vis[p+1]=vis[p]+1;
        }
        if(p*2<=100000&&vis[p*2]==0){
            a.push(p*2);
            vis[p*2]=vis[p]+1;
        }
        a.pop();
    }
    return -1;
}
int main(){
    cin>>n>>m;
    cout<<bfs(n,m);
}