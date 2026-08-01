#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    ull S = 0;
    for (int i = 0; i < n; i++) {
        ull x;
        cin >> x;
        S |= x;
    }
    vector<pair<int, int>> rules(m);
    for (int i = 0; i < m; i++) {
        cin >> rules[i].first >> rules[i].second;
        rules[i].second--; 
    }
    vector<bool> need_feed(c, false);
    for (auto &rule : rules) {
        int p = rule.first;
        int q = rule.second;
        if ((S >> p) & 1ULL) {
            need_feed[q] = true;
        }
    }
    vector<bool> sx(k, false);
    for (auto &rule : rules) {
        int p = rule.first;
        int q = rule.second;
        if (!need_feed[q]) {
            sx[p] = true;
        }
    }
    int free = 0;
    for (int i = 0; i < k; i++) {
        if (!sx[i]) free++;
    }
    if (free < 64) {
        ull ans = (1ULL << free) - n;
        cout << ans << endl;
    } else {
        if (n == 0) {
            cout << "18446744073709551616" << endl;
        } else {
            ull ans = 0 - n;  
            cout << ans << endl;
        }
    }
    
    return 0;
}