#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    int total = N * M;
    if (K > total) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> dp(total + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= total; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
        }
    }
    int ans = dp[total][K];
    if (total % 2 == 0 && K == total / 2) {
        cout << ans % MOD << '\n';
    } else {
        cout << (2 * ans) % MOD << '\n';
    }

    return 0;
}