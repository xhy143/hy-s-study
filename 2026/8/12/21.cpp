#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    freopen("package.in", "r", stdin);
    freopen("package.out", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> w(n);
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        total += w[i];
    }
    if(total <= m) {
        cout << total << endl;
        return 0;
    }
    sort(w.begin(), w.end(), greater<int>());
    k = min(k, n);
    int gift_sum = 0;
    for(int i = 0; i < k; i++) {
        gift_sum += w[i];
    }
    vector<int> rest;
    for(int i = k; i < n; i++) {
        rest.push_back(w[i]);
    }
    if(rest.empty()) {
        cout << gift_sum << endl;
        return 0;
    }
    sort(rest.begin(), rest.end(), greater<int>());
    
    int best_pack = 0;
    for(int idx = 0; idx < (int)rest.size(); idx++) {
        int last = rest[idx];
        vector<int> others;
        for(int i = 0; i < (int)rest.size(); i++) {
            if(i != idx) others.push_back(rest[i]);
        }
        vector<char> dp(m, 0);  
        dp[0] = 1;
        for(int x : others) {
            if(x >= m) continue;  
            for(int j = m - 1; j >= x; j--) {
                if(dp[j - x]) {
                    dp[j] = 1;
                }
            }
        }
        int max_sum = 0;
        for(int j = m - 1; j >= 0; j--) {
            if(dp[j]) {
                max_sum = j;
                break;
            }
        }
        if(max_sum < m) {
            best_pack = max(best_pack, max_sum + last);
        }
    }
    cout << gift_sum + best_pack << endl;
    
    return 0;
}