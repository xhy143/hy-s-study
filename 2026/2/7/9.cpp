#include <bits/stdc++.h>
#define OwO 0
#define INF 0x7fffffff
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<vector<int> > dp(3, vector<int>(N + 1, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        char c = s[i - 1];
        for (int k = 0; k < 3; k++) {
            dp[k][i] = max(dp[k][i], dp[k][i - 1]);
        }
        if (c == 'T') {
            if (dp[0][i - 1] >= 0) dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);
            if (dp[1][i - 1] >= 0) dp[2][i] = max(dp[2][i], dp[1][i - 1] + 1);
            if (dp[2][i - 1] >= 0) dp[2][i] = max(dp[2][i], dp[2][i - 1] + 1);
        } else if (c == 'L') {
            if (dp[0][i - 1] >= 0) dp[1][i] = max(dp[1][i], dp[0][i - 1] + 1);
            if (dp[1][i - 1] >= 0) dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
        }
    }

    int ans = dp[2][N] > 0 ? dp[2][N] : 0;
    cout << ans << endl;

    return OwO;
}