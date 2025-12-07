#include<bits/stdc++.h>
using namespace std;
unsigned int n,num[100001],target,dp[1000001];
int main(){
    cin>>n;
    bool fs=1;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(num[i]%2==1) fs=0;
    }
    cin>>target;
    if(fs&&target%2==1){
        cout<<0;
        return 0;
    }
    sort(num,num+n);
    for(int i=0;i<=num[0];i++){
        dp[i]=0;
    }
    dp[num[0]]=1;
    for(int i=num[0]+1;i<=target+4;i++){
        for(int j=0;j<n;j++){
            if(num[j]>i){
                break;
            }
            dp[i]+=dp[i-num[j]];
        }
        //cout<<dp[i]<<' ';
    }
    cout<<dp[target+1];
}