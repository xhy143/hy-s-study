#include<bits/stdc++.h>
using namespace std;
//😋😋😋😋😋😋😋😋😋
#define int long long
int k, dp[20][2][2];
int dfs(int pos, int pre, int start, int lim, string& s) {
    if(pos == s.size()) return start;  
    if(!lim && start && dp[pos][pre][start] != -1) return dp[pos][pre][start];
    
    int up = lim ? s[pos]-'0' : 9;
    int res = 0;
    for(int d = 0; d <= up; d++) {
        if(!start) {
            if(d == 0) res += dfs(pos+1, 0, 0, lim && d==up, s);
            else res += dfs(pos+1, d&1, 1, lim && d==up, s);
        } else {
            if((d&1) != pre) {
                 res += dfs(pos+1, d&1, 1, lim && d==up, s);
            }
        }
    }
    if(!lim && start) dp[pos][pre][start] = res;
    return res;
}
int count(int x) {
    if(x < 10) return x > 0 ? x : 0;
    string s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 0, 1, s);
}
signed main() {
    //freopen("alt.in", "r", stdin);
    //freopen("alt.out", "w", stdout);
    cin >> k;
    int l = 1, r = 1e18;
    while(l < r) {
        int mid = (l + r) / 2;
        if(count(mid) >= k) r = mid;
        else l = mid + 1;
    }
    
    cout << l << '\n';
    return 0;
}