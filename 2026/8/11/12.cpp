#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int C[70][70];
int fact[70];
int dp[30][30][30][3]; 
void init() {
    for (int i = 0; i < 70; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
    fact[0] = 1;
    for (int i = 1; i < 70; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
}
int solve(int u, int l, int d) {
    if (u + l + d == 0) return 1;
    if (u > 26 || l > 26 || d > 10) return 0;
    
    memset(dp, 0, sizeof(dp));
    
    if (u > 0) dp[1][0][0][0] = u;
    if (l > 0) dp[0][1][0][1] = l;
    if (d > 0) dp[0][0][1][2] = d;
    
    for (int i = 0; i <= u; i++) {
        for (int j = 0; j <= l; j++) {
            for (int k = 0; k <= d; k++) {
                if (i + j + k == 0) continue;
                if (i > 0) {
                    if (j < l) {
                        dp[i][j+1][k][1] = (dp[i][j+1][k][1] + dp[i][j][k][0] * (l - j)) % mod;
                    }
                    if (k < d) {
                        dp[i][j][k+1][2] = (dp[i][j][k+1][2] + dp[i][j][k][0] * (d - k)) % mod;
                    }
                }
                if (j > 0) {
                    if (i < u) {
                        dp[i+1][j][k][0] = (dp[i+1][j][k][0] + dp[i][j][k][1] * (u - i)) % mod;
                    }
                    if (k < d) {
                        dp[i][j][k+1][2] = (dp[i][j][k+1][2] + dp[i][j][k][1] * (d - k)) % mod;
                    }
                }
                if (k > 0) {
                    if (i < u) {
                        dp[i+1][j][k][0] = (dp[i+1][j][k][0] + dp[i][j][k][2] * (u - i)) % mod;
                    }
                    if (j < l) {
                        dp[i][j+1][k][1] = (dp[i][j+1][k][1] + dp[i][j][k][2] * (l - j)) % mod;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int t = 0; t < 3; t++) {
        ans = (ans + dp[u][l][d][t]) % mod;
    }
    return ans;
}
signed main() {
    freopen("passwd.in", "r", stdin);
    freopen("passwd.out", "w", stdout);
    init();
    int u, l, d;
    cin >> u >> l >> d;
    int c = C[26][u] * C[26][l] % mod * C[10][d] % mod;
    int ans = solve(u, l, d);
    cout << c * ans % mod << endl;
    return 0;
}