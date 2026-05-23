#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getx(int j,vector<ll>&sum){
    return sum[j];
}
ll gety(int j,vector<ll>&dp,vector<ll>&sum){
    return dp[j]+sum[j]*sum[j];
}
ll minc(int n,int m,vector<int>&a){
    vector<ll>sum(n+1,0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i-1];
    }
    vector<ll>dp(n+1,0);
    deque<int>q;
    q.push_back(0);
    for(int i=1;i<=n;i++){
        ll k=2*sum[i];
        while(q.size()>=2){
            int j1=q[0],j2=q[1];
            if(gety(j2,dp,sum)-gety(j1,dp,sum)<=k*(getx(j2,sum)-getx(j1,sum))) q.pop_front();
            else break;
        }
        int j=q.front();
        dp[i]=dp[j]+pow(sum[i]-sum[j],2)+m;
        while(q.size()>=2){
            int j1=q[q.size()-2],j2=q[q.size()-1];
            if((gety(i,dp,sum)-gety(j2,dp,sum))*(getx(j2,sum)-getx(j1,sum))<=(gety(j2,dp,sum)-gety(j1,dp,sum))*(getx(i,sum)-getx(j2,sum))) q.pop_back();
            else break;
        }
        q.push_back(i);
    }
    return dp[n];
}
int main(){
    int n,m;
    vector<int>a;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a.push_back(p);
    }
    cout<<minc(n,m,a);
}