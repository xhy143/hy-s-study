#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, V;
    cin >> n >> V;
    vector<int> v(n+1), w(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    vector<int> dp(V+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}