#include <bits/stdc++.h>
using namespace std;

int dp[1 << 10][1000]; 
bool used[10];  

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        int d;
        cin >> s >> d;
        int n = s.length();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int r = 0; r < d; r++) {
                if (dp[mask][r] == 0) continue;
                memset(used, 0, sizeof(used));
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) continue; 
                    
                    int digit = s[i] - '0';
                    if (used[digit]) continue;  
                    used[digit] = true;
                    
                    int newMask = mask | (1 << i);
                    int newR = (r * 10 + digit) % d;
                    dp[newMask][newR] += dp[mask][r];
                }
            }
        }
        
        cout << dp[(1 << n) - 1][0] << endl;
    }
    
    return 0;
}