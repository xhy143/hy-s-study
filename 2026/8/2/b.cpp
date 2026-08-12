#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10001],dp[100001];
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        sort(a+1,a+1+n);
        int m=a[n],ans=0;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(dp[a[i]]==1)continue;
            ans+=1;
            for(int j=a[i];j<=m;j++){
                if(j-a[i]>=0&&dp[j-a[i]]==1)dp[j]=1;
            }
        }
        cout<<ans<<endl;
    }
}