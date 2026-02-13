#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define int long long
struct node{
    int x,y;
}a[6000];
double d[6000];
int n,k;
bool vis[6000];
vector<double> e;
double prim(){
    fill(d+1,d+n+1,INF);
    int u=-1;
    d[1]=0;
    double sum=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int v=1;v<=n;v++){
            if(!vis[v]&&(u==-1||d[v]<d[u])){
                u=v;
            }
        }
        vis[u]=1;
        sum+=d[u];
        e.push_back(d[u]);
        for(int v=1;v<=n;v++){
            d[v]=min(d[v],sqrt( pow(  a[u].x- a[v].x ,2) + pow(  a[v].y-  a[u].y , 2)));
        }
    }
    sort(e.rbegin(),e.rend());
    for(int i=0;i<k-1;i++){
        sum-=e[i];
    }
    return sum;
}
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    cout<<fixed<<setprecision(8)<<prim();
}