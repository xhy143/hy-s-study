#include<bits/stdc++.h>
using namespace std;
struct node
{
    int t,ne,d;
}a[200005];
int n,e,fr[100005],c[100005],s[100005],maxs[100005],sum;
void add(int f,int t,int d)
{
    a[++e].t=t;
    a[e].ne=fr[f];
    fr[f]=e;
    a[e].d=d;
}
void treedp(int fa,int u)
{
    s[u]=c[u];
    for (int i=fr[u];i;i=a[i].ne)
        if (a[i].t!=fa)
        {
            treedp(u,a[i].t);
            s[u]+=s[a[i].t];
            maxs[u]=max(maxs[u],s[a[i].t]);
        }
    maxs[u]=max(maxs[u],sum-s[u]);
}
void dfs(int fa,int u)
{                          
    for (int i=fr[u];i;i=a[i].ne)
        if (fa!=a[i].t)
        {
            s[a[i].t]=s[u]+a[i].d;
            dfs(u,a[i].t);
        }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>c[i],sum+=c[i];
    for (int i=1,x,y,z;i<n;i++)
        cin>>x>>y>>z,add(x,y,z),add(y,x,z);
    treedp(1,1);
    int an=1;
    for (int i=2;i<=n;i++)
        if (maxs[i]<maxs[an])
            an=i;
    s[an]=0;
    dfs(an,an);
    long long ans=0;
    for (int i=1;i<=n;i++)
        ans+=s[i]*(long long)c[i];
    cout<<ans;
}