#include <bits/stdc++.h>
using namespace std;
#define int long long
int S(int n) {
    return 1LL * n * (n + 1) * (2 * n + 1) / 6;
}
signed main() {
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        if (K == 0) { cout << 0 << '\n'; continue; }
        int ans = -1;
        for (int n = 1; n <= 1000000; n++) {
            int sum = S(n);
            if (sum < K) continue;
            if ((sum - K) % 2 != 0) continue;
            if (n >= 6) {
                ans = n;
                break;
            } else {
                vector<int> qw;
                for (int i = 1; i <= n; i++) qw.push_back(1LL * i * i);
                int tgt = (sum + K) / 2;
                bool ok = false;
                for (int mask = 0; mask < (1 << n); mask++) {
                    int cur = 0;
                    for (int i = 0; i < n; i++) {
                        if (mask & (1 << i)) cur += qw[i];
                    }
                    if (cur == tgt) { ok = true; break; }
                }
                if (ok) { ans = n; break; }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}