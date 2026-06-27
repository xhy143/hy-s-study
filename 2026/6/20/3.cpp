#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int MAXN = 1000005;
int fact[MAXN], invfact[MAXN];
int fp(int a, int e) {
    int r = 1;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}
void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;
    invfact[n] = fp(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % mod;
}
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % mod * invfact[n-k] % mod;
}

int P(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n-k] % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(1000000);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        if (n > m) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        for (int k = 0; k <= n; k++) {
            int term = C(n, k) * P(m - k, n - k) % mod;
            if (k & 1) ans = (ans - term + mod) % mod;
            else ans = (ans + term) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}