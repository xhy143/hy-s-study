#include<bits/stdc++.h>
using namespace std;
struct node{
    int  num,cnt;
}e[1000001];
int a,b,vis[100001],ans=0;
void bfs(int a,int b){
    queue<node>q;
    q.push({a,0});
    while(!q.empty()){
        node now=q.front();
        q.pop();
        if(now.num==b){
            cout<<now.cnt;
            return;
        }
        if(now.num>b) continue;
        node nxt=now;
        nxt.num+=1;
        if(vis[nxt.num]==0){
            vis[nxt.num]=1;
            nxt.cnt++;
            q.push(nxt);
        }
        nxt=now;
        nxt.num*=2;
        if(vis[nxt.num]==0){
            vis[nxt.num]=1;
            nxt.cnt++;
            q.push(nxt);
        }
    }
}
int main(){
    cin>>a>>b;bfs(a,b);
}