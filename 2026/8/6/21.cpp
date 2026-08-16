#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 58954412;
vector<int> primes;
vector<int> prefix;
bool vis[MAXN];
void init(int n) {
    n=min(n,MAXN);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (1LL * i * p > n) break;
            vis[i * p] = 1;
            if (i % p == 0) break;
        }
    }
    prefix.resize(primes.size() + 100, 0);
    int sum = 0;
    for (int i = 0; i < (int)primes.size(); i++) {
        sum += primes[i];
        prefix[i + 1] = sum;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<int>Y;
    int t=T,mxt=0;
    while(t--){
        int y;
        cin>>y;
        Y.push_back(y);
        mxt=max(mxt,y);
    }
    init(mxt);
    int e=0;
    while (T--) {
        int y;
        y=Y[e];
        e++;
        if (y == 0) {
            cout << 1 << '\n';
            continue;
        }
        
        auto it = lower_bound(prefix.begin(), prefix.end(), y);
        if (it == prefix.end() || *it != y) {
            cout << 0 << '\n';
        } else {
            int idx = it - prefix.begin(); 
            int ans;
            if (idx < (int)primes.size()) {
                ans = primes[idx] - primes[idx - 1];
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}