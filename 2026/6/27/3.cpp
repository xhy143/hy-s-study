#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1000005;
ll p;
ll fac[maxn], invf[maxn];
bool cl = false;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < p; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    invf[p - 1] = qpow(fac[p - 1], p - 2);
    for (int i = p - 2; i >= 0; i--) {
        invf[i] = invf[i + 1] * (i + 1) % p;
    }
    cl = true;
}

ll C_small(ll n, ll m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * invf[m] % p * invf[n - m] % p;
}
ll C(ll n, ll m) {
    if (m < 0 || m > n) return 0;
    m = min(m, n - m);
    
    ll fm = 1, fz = 1;
    for (ll i = 1; i <= m; i++) {
        fm = fm * ((n - i + 1) % p) % p;
        fz = fz * i % p;
    }
    return fm * qpow(fz, p - 2) % p;
}

ll C_lucas(ll n, ll m) {
    if (m == 0) return 1;
    if (cl) {
        return C_lucas(n / p, m / p) * C_small(n % p, m % p) % p;
    } else {
        return C_lucas(n / p, m / p) * C(n % p, m % p) % p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T >> p;
    
    if (p <= 1000000) {
        init();
    }
    
    while (T--) {
        ll n, k;
        cin >> n >> k;
        cout << C_lucas(n + k - 1, k) << '\n';
    }
    
    return 0;
}