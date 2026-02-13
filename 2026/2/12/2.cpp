#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e8;
int M, N;
int fertile[13]; 
vector<int> states; 
int dp[13][1<<12]; 

int main() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        int row = 0;
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            row = (row << 1) | x;
        }
        fertile[i] = row;
    }
    for (int s = 0; s < (1 << N); s++) {
        if ((s & (s >> 1)) == 0) {
            states.push_back(s);
        }
    }
    dp[0][0] = 1; 
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < states.size(); j++) {
            int cur = states[j];
            if ((cur & ~fertile[i]) != 0) continue;
            
            for (int k = 0; k < states.size(); k++) { 
                int prev = states[k];
                if ((cur & prev) != 0) continue;
                
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < states.size(); j++) {
        ans = (ans + dp[M][j]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}