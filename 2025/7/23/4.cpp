#include<bits/stdc++.h>
using namespace std;
int n,m,vis[10001];
int bfs(int s,int e){
    queue <int>a;
    int cnt=0;
    a.push(s);
    vis[s]++;
    while(!a.empty()){
        int m=a.front();
        if(a.front()==e){
            return vis[m]-1;//
        }
        a.pop();
        if(!vis[m-1]&&m-1>=0){
            a.push(m-1);
            vis[m-1]=vis[m]+1;//
        }
        if(!vis[m+1]&&m+1<=100000){
            a.push(m+1);
            vis[m+1]=vis[m]+1;//
        }
        if(!vis[m*2]&&m*2<=100000){
            a.push(m*2);
            vis[m*2]=vis[m]+1;//
        }
        cnt++;
    }
    return -1;
}
int main(){
    cin>>n>>m;
    cout<<bfs(n,m);
}