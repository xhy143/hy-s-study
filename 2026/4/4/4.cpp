#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    
    // 分离负数和正数
    vector<int> left, right;
    for (int p : pos) {
        if (p < 0) left.push_back(p);
        else right.push_back(p);
    }
    
    // 排序：负数按绝对值从小到大（靠近0的先），正数从小到大
    sort(left.begin(), left.end(), greater<int>()); // 例如：-1, -2, -3...
    sort(right.begin(), right.end()); // 1, 2, 3...
    
    int L = left.size();
    int R = right.size();
    long long dp[L+1][R+1][2];
    if (L > 0) {
        int wfw = n;  
        int dist = abs(0 - left[0]);
        dp[1][0][0] = (long long)dist * wfw;
    }
    if (R > 0) {
        int wfw = n;
        int dist = abs(0 - right[0]);
        dp[0][1][1] = (long long)dist * wfw;
    }
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= R; j++) {
            for (int side = 0; side < 2; side++) {
                if (dp[i][j][side] >= LLONG_MAX/2) continue;
                
                int visited = i + j;  
                int wfw = n - visited;  
                
                
                int curPos;
                if (side == 0) {  
                    if (i == 0) curPos = 0;
                    else curPos = left[i-1];
                } else {  
                    if (j == 0) curPos = 0;
                    else curPos = right[j-1];
                }
                if (i < L) {
                    int nextPos = left[i];
                    int dist = abs(curPos - nextPos);
                    long long newLoss = dp[i][j][side] + (long long)dist * wfw;
                    dp[i+1][j][0] = min(dp[i+1][j][0], newLoss);
                }
                if (j < R) {
                    int nextPos = right[j];
                    int dist = abs(curPos - nextPos);
                    long long newLoss = dp[i][j][side] + (long long)dist * wfw;
                    dp[i][j+1][1] = min(dp[i][j+1][1], newLoss);
                }
            }
        }
    }
    
    long long ans = min(dp[L][R][0], dp[L][R][1]);
    cout << ans << endl;
    
    return 0;
}