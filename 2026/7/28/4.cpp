#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=365*24*60*60,maxn=1e5+100;
struct node{
    int t,tp;
    bool operator<(const node&b)const{
        return t*b.tp<b.t*tp;
    }
};
vector<node>a;
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int t,tp;
        cin>>t>>tp;
        a.push_back({t,tp});
    }
    sort(a.begin(),a.end());
    int time=0;
    for(int i=0;i<n;i++){
        (time+=(a[i].t+a[i].tp*time))%=mod;
    }
    cout<<time;
}