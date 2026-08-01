#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int n,last[maxn],ans,dp[maxn];
string str;
signed main(){
    cin>>n>>str;
    dp[0]=0,last[0]=-1;
    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0&&str[i]!=str[j]){
            j=last[j]-1;
        }
        if(j<0)last[i]=-1;
        else{
            last[i]=j;
            dp[i]=(j>0?dp[j-1]+1:1);
            ans+=dp[i];
        }
    }
    cout<<ans;
}