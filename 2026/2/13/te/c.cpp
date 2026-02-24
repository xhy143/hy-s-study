#include<bits/stdc++.h>
using namespace std;

const int MOD = 9901;
int P(int m, int n) {
    if (n < 0 || n > m) return 0;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res = res * (m - i) % MOD;
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    char chars[10];
    for (int i = 0; i < m; i++) {
        cin >> chars[i];
    }
    
    int pos[20];
    char forbid[20];
    for (int i = 0; i < k; i++) {
        cin >> pos[i] >> forbid[i];
    }
    
    long long ans = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        bool used_pos[10] = {false};
        bool used_char[256] = {false};
        int cnt = 0;
        bool valid = true;
        for (int i = 0; i < k; i++) {
            if (mask >> i & 1) {
                cnt++;
                int p = pos[i];
                char c = forbid[i];
                if (used_pos[p] || used_char[c]) {
                    valid = false;
                    break;
                }
                
                used_pos[p] = true;
                used_char[c] = true;
            }
        }
        
        if (!valid) continue;
        if (cnt > n) continue;  
        long long contrib = P(m - cnt, n - cnt);
        if (cnt % 2 == 0) {
            ans = (ans + contrib) % MOD;
        } else {
            ans = (ans - contrib + MOD) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}