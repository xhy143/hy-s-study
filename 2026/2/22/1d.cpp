#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w.rbegin(), w.rend());
    multiset<int> rows; 
    int height = 0;
    for (int i = 0; i < n; i++) {
        auto it = rows.lower_bound(w[i]);
        if (it == rows.end()) {
            height++;
            rows.insert(W - w[i]);
        } else {
            int remaining = *it - w[i];
            rows.erase(it);
            if (remaining > 0) {
                rows.insert(remaining);
            }
        }
    }
    return height;
}

int main() {
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}