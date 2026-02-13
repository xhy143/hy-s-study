#include <bits/stdc++.h>
using namespace std;
#define QAQ 0
#define MN 16
string words[MN];
int len[MN];
char first[MN],last[MN];
int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        len[i] = words[i].length();
        first[i] = words[i][0];
        last[i] = words[i][len[i] - 1];
    }

    int totalMasks = 1 << N;
    int dp[totalMasks][N];
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < N; i++) {
        dp[1 << i][i] = len[i];
    }

    int ans = 0;

    for (int mask = 1; mask < totalMasks; mask++) {
        for (int i = 0; i < N; i++) {
            if (dp[mask][i] == -1) continue; 
            ans = max(ans, dp[mask][i]);      

            for (int j = 0; j < N; j++) {
                if (mask >> j & 1) continue;
                if (last[i] != first[j]) continue; 

                int newMask = mask | (1 << j);
                dp[newMask][j] = max(dp[newMask][j], dp[mask][i] + len[j]);
            }
        }
    }

    cout << ans << endl;

    return QAQ;
}