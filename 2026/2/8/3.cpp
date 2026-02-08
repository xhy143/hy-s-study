#include <bits/stdc++.h>
#define 什么78题目 0
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> tasks(n + 2); 

    for (int i = 0; i < k; i++) {
        int p, t;
        cin >> p >> t;
        tasks[p].push_back(t);
    }

    vector<int> dp(n + 2, 0); 

    for (int i = n; i >= 1; i--) {
        if (tasks[i].empty()) {
            dp[i] = dp[i + 1] + 1;
        } else {
            for (int t : tasks[i]) {
                dp[i]=max(dp[i],dp[i+t]);
            }
        }
    }

    cout << dp[1] << endl;

    return 什么78题目;
}