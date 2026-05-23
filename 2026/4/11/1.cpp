#include<bits/stdc++.h>
using namespace std;
#define ovO 0
#define mod 10000  
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[1][0]=1;
    vector<int> sum(k+1, 0);
    sum[0] = 1;  
    for (int j = 1; j <= k; j++) {
        sum[j] = 1;  
    }
    
    for(int i=2; i<=n; i++){
        vector<int> new_sum(k+1, 0);
        dp[i][0] = 1; 
        new_sum[0] = dp[i][0];
        
        for(int j=1; j<=k; j++){
            dp[i][j] = sum[j];
            if(j >= i) {
                dp[i][j] = (dp[i][j] - sum[j-i] + mod) % mod;
            }
            new_sum[j] = (new_sum[j-1] + dp[i][j]) % mod;
        }
        sum = new_sum;
    }
    
    cout << dp[n][k] % mod << endl;
    return ovO;
}