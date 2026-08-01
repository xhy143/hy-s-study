#include<bits/stdc++.h>
#define in freopen("pop.in","r",stdin);
#define out freopen("pop.out","w",stdout);
#define int long long
using namespace std;
const int maxn=2e5 + 5;
int n;
int a[maxn],b[maxn];
int pos[maxn];
set<int>alive; 
map<int,set<int>>valPos; 
struct BIT {
    int c[maxn];
    void init(){memset(c,0,sizeof(c));}
    void add(int x,int v) {
        for(;x<=n;x+=x&-x)c[x]+=v;
    }
    int sum(int x){
        int res=0;
        for(;x>0;x-=x&-x)res+=c[x];
        return res;
    }
    int rangeSum(int l,int r) {
        if(l>r)return 0;
        return sum(r)-sum(l-1);
    }
}bit;
signed main() {
    in out
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        valPos[a[i]].insert(i);
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    bit.init();
    for(int i=1;i<=n;i++) {
        bit.add(i,1);
        alive.insert(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        int op=b[i];
        int tpos;
        if(op == 0) {
            auto it=valPos.begin();
            int minVal=it->first;
            tpos=*(it->second.begin());
        } else {
            auto it=valPos.end();
            --it;
            int maxVal=it->first;
            tpos=*(it->second.rbegin());
        }
        int rank=bit.sum(tpos);
        int aliven=alive.size();
        if(op==0) {
            ans+=rank-1;
        } else {
            ans+=aliven-rank;
        }
        bit.add(tpos,-1);
        alive.erase(tpos);
        int val=a[tpos];
        valPos[val].erase(tpos);
        if(valPos[val].empty()) {
            valPos.erase(val);
        }
    }
    cout<<ans<<'\n';
    return 0;
}