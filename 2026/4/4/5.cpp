#include <bits/stdc++.h>
using namespace std;

int x, y;  
string s;
int dp[10][2][11][11][2]; 

int dfs(int pos, bool tight, int prev, int prev2, bool started) {
    if (pos == s.size()) {
        return started ? 1 : 0;  
    }
    if (dp[pos][tight][prev+1][prev2+1][started] != -1) {
        return dp[pos][tight][prev+1][prev2+1][started];
    }
    
    int up = tight ? s[pos] - '0' : 9;
    int res = 0;
    
    for (int d = 0; d <= up; d++) {
        if (started && d == x) continue; 
        
        if (prev != -1 && prev * 10 + d == y) continue;
        
        bool nstarted = started || (d != 0);
        int nprev = d;
        int nprev2 = prev;
        if (!nstarted) {
            nprev = -1;
            nprev2 = -1;
        }
        
        res += dfs(pos + 1, tight && (d == up), nprev, nprev2, nstarted);
    }
    return dp[pos][tight][prev+1][prev2+1][started] = res;
}

int solve(int n) {
    if (n < 0) return 0;
    s = to_string(n);
    memset(dp, -1, sizeof dp);
    int ans = dfs(0, true, -1, -1, false);
    if (x != 0) {
        ans += 1;  
    }
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r >> x >> y;
    cout << solve(r) - solve(l-1) << endl;
    return 0;
}