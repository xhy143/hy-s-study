#include <bits/stdc++.h>
#define OwO 0
using namespace std;
int main(){
    int n, i, j, k, l, t, dp[60][60];
    string s;
    cin>>s;
    n = s.length();
    for (i = 0; i < n; ++i){
        dp[i][i] = 1;
    }
    for (l = 1; l < n; ++l){
        for (i = 0; i + l < n; ++i){
            if (s[i] == s[i + l]){
                dp[i][i + l] = dp[i][i + l - 1];
            }
            else{
                dp[i][i + l] = dp[i][i] + dp[i + 1][i + l];
                for (k = i + 1; k < i + l; ++k){
                    dp[i][i + l] = min(dp[i][i + l], dp[i][k] + dp[k + 1][i + l]);
                }
            }
        }
    }
    cout<<dp[0][n-1];
    return OwO;
}
