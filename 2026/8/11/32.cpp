#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;

struct state {
    long long u, diff;
};
bool cmp1(state a,state b){
    return a.diff<b.diff;
}
bool cmp2(state a,int b){
    return a.diff<b;
}
int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    
    int n1 = n / 2, n2 = n - n1;
    vector<state> left;
    for (int mask = 0; mask < pow(3, n1); mask++) {
        long long u = 0, diff = 0;
        int tmp = mask;
        for (int i = 0; i < n1; i++) {
            int s = tmp % 3; tmp /= 3;
            if (s == 0) u += r[i];
            else if (s == 1) diff += r[i];
            else diff -= r[i];
        }
        left.push_back({u, diff});
    }
    vector<state> right;
    for (int mask = 0; mask < pow(3, n2); mask++) {
        long long u = 0, diff = 0;
        int tmp = mask;
        for (int i = 0; i < n2; i++) {
            int s = tmp % 3; tmp /= 3;
            if (s == 0) u += r[n1 + i];
            else if (s == 1) diff += r[n1 + i];
            else diff -= r[n1 + i];
        }
        right.push_back({u, diff});
    }
    sort(right.begin(), right.end(), cmp1);
    
    long long ans = INF;
    for (const auto& ls : left) {
        long long target = -ls.diff;
        int idx = lower_bound(right.begin(), right.end(), target,cmp2) - right.begin();
        for (int j = max(0, idx - 1); j <= min((int)right.size() - 1, idx); j++) {
            long long total_diff = llabs(ls.diff + right[j].diff);
            long long total_u = ls.u + right[j].u;
            ans = min(ans, total_u + k * total_diff);
        }
    }
    
    cout << ans << endl;
    return 0;
}