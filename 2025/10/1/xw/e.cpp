#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    
    vector<int> w(N);
    vector<int> v(N);
    int total_value = 0; 
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
        total_value += v[i];
    }

    vector<long long> dp(total_value + 1, LLONG_MAX);
    dp[0] = 0;  

    for (int i = 0; i < N; ++i) {

        for (int j = total_value; j >= v[i]; --j) {
            if (dp[j - v[i]] != LLONG_MAX) {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    int max_val = 0;
    for (int j = total_value; j >= 0; --j) {
        if (dp[j] <= V) {
            max_val = j;
            break;
        }
    }
    
    cout << max_val << endl;
    
    return 0;
}
