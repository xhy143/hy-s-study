#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp = a[0];
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        dp = max(a[i], dp + a[i]);
        ans = max(ans, dp);
    }
    cout << ans << endl;
    return 0;
}