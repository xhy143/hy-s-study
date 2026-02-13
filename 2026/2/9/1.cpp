#include <bits/stdc++.h>
using namespace std;

int main() {
    int w[6] = {1, 2, 3, 5, 10, 20};
    int cnt[6];
    for (int i = 0; i < 6; i++) {
        cin >> cnt[i];
    }
    int maxWeight = 1000; 
    vector<bool> dp(maxWeight + 1, false);
    dp[0] = true;
    for (int i = 0; i < 6; i++) { 
        for (int k = 0; k < cnt[i]; k++) { 
            for (int j = maxWeight; j >= w[i]; j--) {
                if (dp[j - w[i]]) {
                    dp[j] = true;
                }
            }
        }
    }
    int total = 0;
    for (int i = 1; i <= maxWeight; i++) {
        if (dp[i]) total++;
    }

    cout << "Total=" << total << endl;
    return 0;
}