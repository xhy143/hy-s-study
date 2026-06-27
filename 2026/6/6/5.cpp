#include <bits/stdc++.h>
using namespace std;
#define int long long
int fast_mul(int a, int b, int mod) {
    int res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

int fast_pow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = fast_mul(res, a, mod);
        a = fast_mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

void exgcd(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a, x = 1, y = 0;
        return;
    }
    int nx, ny;
    exgcd(b, a % b, d, nx, ny);
    x = ny;
    y = nx - (a / b) * ny;
}

int modinv(int a, int mod) {
    int d, x, y;
    exgcd(a, mod, d, x, y);
    return (x % mod + mod) % mod;
}

signed main() {
    int n, m, L;
    cin >> n >> m >> L;

    if (n == 2) {
        if (m % 2 == 0) cout << L << endl;
        else cout << (L == 1 ? 2 : 1) << endl;
        return 0;
    }

    int mod = n - 1;
    int pow2M = fast_pow(2, m, mod);
    int inv_pow2M = modinv(pow2M, mod);
    int p = L - 1;
    int t = ((p - pow2M + 1) % mod + mod) % mod;
    int x0 = fast_mul(t, inv_pow2M, mod);
    cout << x0 + 1 << endl;
    return 0;
}