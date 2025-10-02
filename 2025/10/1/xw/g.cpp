#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    vector<vector<long long>> dp(H + 1, vector<long long>(W + 1, 0));

    dp[1][1] = 1;

    for (int j = 2; j <= W; j++) {
        if (grid[0][j-1] == '.') {
            dp[1][j] = dp[1][j-1];
        } else {
            dp[1][j] = 0;
        }
    }
    for (int i = 2; i <= H; i++) {
        if (grid[i-1][0] == '.') {
            dp[i][1] = dp[i-1][1];
        } else {
            dp[i][1] = 0;
        }
    }
    for (int i = 2; i <= H; i++) {
        for (int j = 2; j <= W; j++) {
            if (grid[i-1][j-1] == '#') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    
    cout << dp[H][W] << endl;
    
    return 0;
}
