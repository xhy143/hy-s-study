#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    freopen("crotate.in","r",stdin);
    freopen("crotate.out","w",stdout);
    long long N;
    cin >> N;

    if (N == 1) {
        cout << 2 << endl;
        return 0;
    }

    long long ans;
    if (N % 2 == 1) {
        long long exp = (N - 3) / 2;
        ans = (4 * 3) % MOD * powmod(5, exp) % MOD;
    } else {
        long long exp = N / 2 - 1;
        ans = 4 * powmod(5, exp) % MOD;
    }

    cout << ans << endl;
    return 0;
}