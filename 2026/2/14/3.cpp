#include<bits/stdc++.h>
#define OwO 0
using namespace std;
priority_queue<int>q1,q2;
int n,R,L,ans;
int a[200010],dp[200010];
int main(){
    cin>>n>>L>>R;
    for(int i=0;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<L;i++)q2.push(a[i]);
    for(int i=L;i<=n;i++){
        q1.push(dp[i-L]);
        if(i-R-1>=L)q2.push(dp[i-R-1]);
        while(!q2.empty()&&q1.top()==q2.top()){
            q1.pop();q2.pop();
        }
        dp[i]=q1.top()+a[i];            
    }
    for(int i=n-R+1;i<=n;i++)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return OwO;
}
