#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxp = 100000000;
vector<int> prefix;
vector<int> gap;
void pre() {
    vector<bool> isPrime(maxp + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= maxp; i++) {
        if (isPrime[i]) {
            for (int j = 1LL * i * i; j <= maxp; j += i) {
                isPrime[j] = false;
            }
        }
    }
    prefix.reserve(6000001);
    gap.reserve(6000001);
    prefix.push_back(0);
    gap.push_back(0); 
    int sum = 0;
    int prev = 0;
    for (int i = 2; i <= maxp; i++) {
        if (isPrime[i]) {
            sum += i;
            prefix.push_back(sum);
            gap.push_back(i - prev);
            prev = i;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int T;
    cin >> T;
    while (T--) {
        int y;
        cin >> y;
        if (y == 0) {
            cout << 1 << '\n';
            continue;
        }
        auto it = lower_bound(prefix.begin(), prefix.end(), y);
        if (it == prefix.end() || *it != y) {
            cout << 0 << '\n';
        } else {
            int idx = it - prefix.begin();
            cout << gap[idx] << '\n';
        }
    }
    return 0;
}