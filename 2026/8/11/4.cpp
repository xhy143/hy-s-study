#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=1e6+10;
int T,n,m,L,V,l[M],r[M],d[N],v[N],a[N];
struct node{
    int l,r;
};
vector<node>jl;
bool cmp(node a,node b){
    return a.r<b.r;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        jl.clear();
        cin>>n>>m>>L>>V;
        for(int i=0;i<M;i++){
            l[i]=r[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            int p;
            cin>>p;
            l[p]=r[p]=p;
        }
        for(int i=1;i<=L;i++){
            if(l[i])continue;
            l[i]=l[i-1];
        }
        for(int i=L;i>=0;i--){
            if(r[i])continue;
            r[i]=r[i+1];
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(!r[d[i]]||v[i]<=V)continue;
                jl.push_back({r[d[i]],l[L]});
            }
            if(a[i]>0){
                if(!r[d[i]])continue;
                if(v[i]>V){
                    jl.push_back({r[d[i]],l[L]});
                }
                else{
                    int s=(V*V-v[i]*v[i])/(2*a[i])+1;
                    s+=d[i];
                    if(s>L||!r[s])continue;
                    jl.push_back({r[s],l[L]});
                }
            }
            if(a[i]<0){
                if(!r[d[i]]||v[i]<=V)continue;
                int s=(V*V-v[i]*v[i])/(2*a[i]);
                if((V*V-v[i]*v[i])%(2*a[i])==0)s--;
                s+=d[i];
                if(s>L)s=L;
                if(r[d[i]]>l[s])continue;
                jl.push_back({r[d[i]],l[s]});
            }
        }
        sort(jl.begin(),jl.end(),cmp);
        int p=-1,ans=0;
        cout<<jl.size()<<' ';
        for(int i=0;i<jl.size();i++){
            if(i&&jl[i].l<=jl[i-1].l)continue;
            if(p<jl[i].l)p=jl[i].r,ans++;
        }
        cout<<m-ans<<'\n';
    }
    return 0;
}
