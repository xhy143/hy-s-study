#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e7 + 10;
bool fpri[maxn];
vector<int> primes;
int phi[maxn];
int pre[maxn];  

void ispr() {
    fpri[1] = 1;
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!fpri[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes) {
            if (1ll * i * p >= maxn)
                break;
            fpri[i * p] = true;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
    pre[1] = 1;
    for (int i = 2; i < maxn; i++) {
        pre[i] = pre[i - 1] + phi[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ispr();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << 2LL * pre[n] - 1 << '\n';
    }
    
    return 0;
}