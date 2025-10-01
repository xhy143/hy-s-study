#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    int m, p1, s1, s2;
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    long long dragon = 0, tiger = 0;
    for (int i = 1; i < m; i++) {
        dragon += c[i] * abs(i - m);
    }
    for (int i = m + 1; i <= n; i++) {
        tiger += c[i] * abs(i - m);
    }

    long long min_qs = 1145141919810;
    int ans = 1;
    for (int p2 = 1; p2 <= n; p2++) {
        long long d = dragon, t = tiger;
        if (p2 < m) d += s2 * abs(p2 - m);
        else if (p2 > m) t += s2 * abs(p2 - m);
        long long qs = abs(d - t);
        if (qs < min_qs) {
            min_qs = qs;
            ans = p2;
        } else if (qs == min_qs && p2 < ans) {
            ans = p2;
        }
    }
    cout << ans << endl;
}