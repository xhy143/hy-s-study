#include<bits/stdc++.h>
using namespace std;
const int maxp=1e7;
vector<int>primes,pri;
int minp[maxp+10],n,q;
bool vis[maxp+10];
void init(){
    for(int i=2;i<=maxp;i++){
        if(!vis[i]){
            primes.push_back(i);
            minp[i]=i;
        }
        for(int p:primes){
            if(1ll*i*p>maxp) break;
            vis[i*p]=1;
            minp[i*p]=p;
            if(i%p==0)break;
        }
    }
}
int calc(int x){
    return (upper_bound(pri.begin(),pri.end(),x)-pri.begin());
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,lastp=0;
        cin>>x;
        while(x!=1){
            if(lastp!=minp[x]){
                lastp=minp[x];
                pri.push_back(lastp);
            }
            x/=minp[x];
        }
    }
    sort(pri.begin(),pri.end());
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<endl;
    }
}