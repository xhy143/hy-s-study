#include<bits/stdc++.h>
#define in freopen("xcpc.in","r",stdin);
#define out freopen("xcpc.out","w",stdout);
#define int long long
using namespace std;
struct node{
    int l,p1,p2,p3,p4,pos;
};
int n,ans=0,used[1001],t=0;
vector<node> q;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int l,p1,p2,p3,p4;
        cin>>l>>p1>>p2>>p3>>p4;
        q.push_back({l,p1,p2,p3,p4,i});
    }
    
}