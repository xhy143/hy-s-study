#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("gift.in", "r", stdin);
    freopen("gift.out", "w", stdout);
    int n, M;
    cin >> n >> M;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    long long max_value = 0;
    long long sum_w = 0, sum_v = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        sum_w += w[r];
        sum_v += v[r];
        while (sum_w > M && l <= r) {
            sum_w -= w[l];
            sum_v -= v[l];
            l++;
        }
        if (sum_w <= M) {
            max_value = max(max_value, sum_v);
        }
    }
    cout << max_value << endl;
    return 0;
}