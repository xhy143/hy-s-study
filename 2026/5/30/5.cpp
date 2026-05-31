#include <iostream>
using namespace std;
using ll = long long;

ll mod_pow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll N, P;
        cin >> N >> P;

        if (N >= P) {
            cout << "0\n";
            continue;
        }
        ll prod = 1;
        for (ll k = N + 1; k <= P - 1; ++k) {
            prod = (prod * (k % P)) % P;
        }
        ll inv = mod_pow(prod, P - 2, P);
        ll ans = (P - 1) * inv % P;   
        cout << ans << '\n';
    }

    return 0;
}