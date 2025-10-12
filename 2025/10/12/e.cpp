#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[101][101];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dp[i][j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        
    }
}