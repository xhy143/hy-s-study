#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    vector<int> left, right;
    for (int p : pos) {
        if (p < 0) left.push_back(p);
        else right.push_back(p);
    }
    sort(left.begin(), left.end(), greater<int>()); 
    sort(right.begin(), right.end()); 
    
    int L = left.size();
    int R = right.size();
    long long dp[L+1][R+1][2];
    if (L > 0) {
        dp[1][0][0] = abs(left[0]) * n; 
    }
    if (R > 0) {
        dp[0][1][1] = abs(right[0]) * n;
    }
    
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= R; j++) {
            for (int side = 0; side < 2; side++) {
                if (dp[i][j][side] >= LLONG_MAX/2) continue;
                
                int remaining = n - (i + j);
                int curPos;
                if (side == 0) {
                    if (i == 0) curPos = 0;
                    else curPos = left[i-1];
                } else {
                    if (j == 0) curPos = 0;
                    else curPos = right[j-1];
                }
                if (i < L) {
                    int nextPos = left[i];
                    int dist = abs(curPos - nextPos);
                    long long newLoss = dp[i][j][side] + (long long)dist * remaining;
                    dp[i+1][j][0] = min(dp[i+1][j][0], newLoss);
                }
                if (j < R) {
                    int nextPos = right[j];
                    int dist = abs(curPos - nextPos);
                    long long newLoss = dp[i][j][side] + (long long)dist * remaining;
                    dp[i][j+1][1] = min(dp[i][j+1][1], newLoss);
                }
            }
        }
    }
    
    long long ans = min(dp[L][R][0], dp[L][R][1]);
    cout << ans << endl;
    
    return 0;
}