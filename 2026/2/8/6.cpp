#include<bits/stdc++.h>
using namespace std;
#define QAQ 0
int t,w,s[10001],dp[1001][1001];
int catchp(int t,int w){
    return (w%2==0?1:2)==s[t];
}
int main(){
    cin>>t>>w;
    for(int i=0;i<t;i++){
        cin>>s[i];
    }
    dp[0][0]=0;
    for(int i=1;i<t;i++){
        for(int j=1;j<w;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+catchp(i,j);
        }
    }
    cout<<dp[t-1][w-1];
    return QAQ;
}