#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5000000;
vector<int> primes;
vector<int> prefix;
unordered_map<int, int> pos; 
void init() {
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    prefix.resize(primes.size() + 1, 0);
    for (int i = 0; i < (int)primes.size(); i++) {
        prefix[i + 1] = prefix[i] + primes[i];
        pos[prefix[i + 1]] = i + 1; 
    }
}
signed main() {
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) {
        int y;
        cin >> y;
        if (y == 0) {
            cout << 1 << '\n';
            continue;
        }
        if (pos.find(y) == pos.end()) {
            cout << 0 << '\n';
        } else {
            int idx = pos[y]; 
            int ans = primes[idx] - primes[idx - 1];
            cout << ans << '\n';
        }
    }
    return 0;
}