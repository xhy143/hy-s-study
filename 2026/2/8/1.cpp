#include <bits/stdc++.h>
#define INF 0x7fffffff
#define OvO 0
#define 什�?78题目 0
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    vector<int> inc(n, 1);
    vector<int> dec(n, 1); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (height[j] < height[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (height[j] < height[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        maxLen = max(maxLen, inc[i] + dec[i] - 1);
    }
    cout << n - maxLen << endl;

    return OvO;
    return 什�?78题目;
}