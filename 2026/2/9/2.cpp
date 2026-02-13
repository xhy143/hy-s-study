#include <bits/stdc++.h>
using namespace std;
const int N = 100010;  
long long dp[N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        int v, w, m;
        cin >> v >> w >> m;
        int amount = m;
        for (int k = 1; amount > 0; k <<= 1) {
            int t = min(k, amount);  
            amount -= t;
            int ww = w * t;          
            long long vv = 1LL * v * t;  
            for (int j = W; j >= ww; j--) {
                if (dp[j] < dp[j - ww] + vv) {
                    dp[j] = dp[j - ww] + vv;
                }
            }
        }
    }
    
    cout << dp[W] << endl;
    return 0;
}