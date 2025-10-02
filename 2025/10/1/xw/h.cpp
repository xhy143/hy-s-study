#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<bool> dp(K + 1, false);
    dp[0] = false;
    for (int i = 1; i <= K; ++i) {
        for (int x : A) {
            if (i >= x && !dp[i - x]) {
                dp[i] = true;
                break; 
            }
        }
    }
    if (dp[K]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    
    return 0;
}
