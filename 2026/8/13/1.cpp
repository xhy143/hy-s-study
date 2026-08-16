#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll mod;
vector<ll> jc, inv;

ll qpow(ll a, ll b) {
    if(b == 0) return 1;
    ll ans = qpow(a, b/2);
    if(b % 2 == 0) {
        return (ans * ans) % mod;
    } else {
        return (ans * ans) % mod * a % mod;
    }
}

void init(ll p) {
    mod = p;
    int limit = p;  
    jc.resize(limit + 1);
    inv.resize(limit + 1);
    
    jc[0] = inv[0] = 1;
    for(int i = 1; i < limit; i++) {
        jc[i] = (jc[i-1] * i) % mod;
    }
    if(limit > 1) {
        inv[limit - 1] = qpow(jc[limit - 1], mod - 2);
        for(int i = limit - 1; i > 1; i--) {
            inv[i-1] = inv[i] * i % mod;
        }
    }
}
ll c(ll n, ll m) {
    if(m < 0 || m > n) return 0;
    if(n >= mod) return 0;  
    return jc[n] * inv[m] % mod * inv[n-m] % mod;
}
// Lucas：C(n,m) mod p = C(n/p, m/p) * C(n%p, m%p) mod p
ll lucas(ll n, ll m) {
    if(m == 0) return 1;
    if(n < m) return 0;
    return lucas(n / mod, m / mod) * c(n % mod, m % mod) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--) {
        ll n, m, p;
        cin >> n >> m >> p;
        
        init(p); 
        cout << lucas(n + m, n) << endl;
    }
    
    return 0;
}