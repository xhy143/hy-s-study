#include <bits/stdc++.h>
using namespace std;
#define ll long long
void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (b == 0) {
        d = a, x = 1, y = 0;
        return;
    }
    ll nx, ny;
    exgcd(b, a % b, d, nx, ny);
    x = ny;
    y = nx - (a / b) * ny;
}
int main() {
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll a = m - n;
    ll b = L;
    ll c = y - x;
    if (a < 0) {
        a = -a;
        c = -c;
    }
    ll d, t, k;
    exgcd(a, b, d, t, k);
    if (c % d != 0) {
        cout << "Impossible" << endl;
    } else {
        t = t * (c / d);
        ll mod = b / d;
        t = (t % mod + mod) % mod;
        cout << t << endl;
    }
    
    return 0;
}