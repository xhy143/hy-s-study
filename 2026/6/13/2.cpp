#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int p;
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
    for(int i=1;i<=p-1;i++){
        fac[i]=1ll*fac[i-1]*i%p;
    }
    ll d,x,y;
    exgcd(fac[p-1],p,d,x,y);
    invf[p-1]=(x+p%p);
    for(int i=p-2;i>=0;i--) invf[i]=1ll*invf[i+1]*(i+1)%p;
}
ll cs(int n,int m){
    if(m>n)return 0;
    return 1ll*fac[n]*invf[m]%p*invf[n-m]%p;
}
ll c(int n,int m){
    if(n<0||m<0||m>n)return 0;
    ll ans=1;
    while(n>0){
        ans=1ll*ans*cs(n%p,m%p)%p;
        n/=p;m/=p;
    }
    return ans;
}
signed main(){
    int t;
    cin>>t>>p;
    init();
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<c(n,k)<<endl;
    }
}