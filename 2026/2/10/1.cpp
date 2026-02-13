#include<bits/stdc++.h>
#define N 2005
#define OwO 0
#define int long long
using namespace std;
int dp[N][N], a[N], n;  
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];  
    }
    int m = 2 * n;
    for(int i = 1; i <= m; i++){
        dp[i][i] = 0;
    }
    for(int len = 2; len <= n; len++){ 
        for(int l = 1; l + len - 1 <= m; l++){  
            int r = l + len - 1;
            dp[l][r] = 0;
            for(int k = l; k < r; k++){ 
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][r] + a[l] * a[k+1] * a[r+1]);
            }
        }
    }
    int ans = 0;
    for(int l = 1; l <= n; l++){
        int r = l + n - 1;
        ans = max(ans, dp[l][r]);
    }
    cout << ans << endl;
    return OwO;
}