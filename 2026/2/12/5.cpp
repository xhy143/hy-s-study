#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffffffffffff
#define TAT 0
using namespace std;
int d[10001],n,m,cnt[10001],inq[10001];
struct node{
    int e,w;
};
vector<node>a[100001];
bool p(int s){
    fill(d+1,d+1+n,INF);
    fill(cnt,cnt+n+1,0);
    fill(inq,inq+n+1,0);
    queue<int>q;
    q.push(s);
    inq[s]=1,d[s]=0,cnt[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].e,w=a[u][i].w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>n-1)return 1;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    return 0;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s,e,w;
        cin>>s>>e>>w;
        a[s].push_back({e,w});
    }
    cout<<(p(1)?"Yes":"No");
}