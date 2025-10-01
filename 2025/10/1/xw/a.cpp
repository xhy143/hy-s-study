#include<bits/stdc++.h>
using namespace std;
int n, k, hf[100001], dp[100001];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> hf[i];
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = 2147483647;
        for(int j = 1; j <= k && i - j >= 1; j++){
            dp[i] = min(dp[i], dp[i - j] + abs(hf[i] - hf[i - j]));
        }
    }
    cout << dp[n];
    return 0;
}