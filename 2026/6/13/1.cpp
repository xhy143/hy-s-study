#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7;
const int p=1e9+7;
int fac[maxn+10],invf[maxn+10];
#define ll long long
void exgcd(ll a,ll b,ll &d,ll& x,ll&y){
    if(b==0){
        x=1;y=0;
        d=a;
        return;
    }
    ll nx,ny;
    exgcd(b,a%b,d,nx,ny);
    x=ny;
    y=nx-a/b*ny;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=maxn;i++){
        fac[i]=1ll*fac[i-1]*i%p;
    }
    ll d,x,y;
    exgcd(fac[maxn],p,d,x,y);
    invf[maxn]=(x+p%p);
    for(int i=maxn-1;i>=0;i--) invf[i]=1ll*invf[i+1]*(i+1)%p;
}
ll c(int n,int m){
    if(n<0||m<0||m>n)return 0;
    return 1ll*fac[n]*invf[m]%p*invf[n-m]%p;
}
signed main(){
    int t;
    init();
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<c(n,k)<<endl;
    }
}