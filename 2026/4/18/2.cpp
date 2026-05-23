#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getx(int j){
    return j+1;
}
ll gety(int j,vector<ll>&dp,vector<ll>&sum){
    return dp[j]-sum[j]*(j+1);
}
ll mp(int n,int m,vector<int>&a){
    vector<ll>sum(n+1,0);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i-1];
    vector<ll>dp(n+1,0);
    deque<int>q;
    q.push_back(0);
    for(int i=1;i<=n;i++){
        ll k=-sum[i];
        int l=0,r=q.size()-1;
        while(l<r){
            int mid=(l+r)>>1;
            ll x1=getx(q[mid]),y1=gety(q[mid],dp,sum);
            ll x2=getx(q[mid+1]),y2=gety(q[mid+1],dp,sum);
            if((y2-y1)>=k*(x2-x1)) l=++mid;
            else r=mid;
        }
        int j=q[l];
        dp[i]=dp[j]+(sum[i]-sum[j])*(j+1)-m;
        while(q.size()>=2){
            int j1=q[q.size()-2],j2=q[q.size()-1];
            ll x1=getx(j1),y1=gety(j1,dp,sum),x2=getx(j2),y2=gety(j2,dp,sum),x3=getx(i),y3=gety(i,dp,sum);
            if((y2-y1)*(x3-x2)<=(y3-y2)*(x2-x1)){
                q.pop_back();
            }
            else break;
        }
        q.push_back(i);
    }
    return dp[n];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a.push_back(p);
    }
    cout<<mp(n,m,a);
}