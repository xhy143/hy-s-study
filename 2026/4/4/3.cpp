#include <bits/stdc++.h>
using namespace std;
int s1(int a){
    int ans=0;
    while(a){
        ans+=a&1;
        a>>=1;
    }
    return ans;
}
int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> pre(N, 0); 
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        pre[v] |= (1 << u);
    }

    int full = (1 << N) - 1;
    vector<int> dp(full + 1, 1e9);
    dp[0] = 0;

    for (int mask = 0; mask <= full; mask++) {
        if (dp[mask] == 1e9) continue;
        int kn = 0;
        for (int i = 0; i < N; i++) {
            if (!(mask >> i & 1) && (mask & pre[i]) == pre[i]) {
                kn |= (1 << i);
            }
        }
        int zmask = kn;
        while (zmask!=0) {
            if (s1(zmask) <= K) {
                int nmask = mask | zmask;
                dp[nmask] = min(dp[nmask], dp[mask] + 1);
            }
            zmask = (zmask - 1) & kn;
        }
    }

    cout << dp[full] << endl;
    return 0;
}