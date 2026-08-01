#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+100;
int a[maxn],sum[maxn];
signed main(){
    int n,k;
    cin>>n>>k;
    int ans=0,ansi=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid=(l+r)>>1;
        int b=i;
        while(l<=r){
            mid=(l+r)>>1;
            int len=i-mid+1;
            int sump=sum[i]-sum[mid-1];
            int cost=len*a[i]-sump;
            if(cost<=k){
                b=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int cnt=i-b+1;
        if(cnt>ans){
            ans=cnt;
            ansi=a[i];
        }
    }
    cout<<ans<<' '<<ansi;
}