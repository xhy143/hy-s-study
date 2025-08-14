#include <bits/stdc++.h>
using namespace std;


int dfs(int count, int sum, int start, int n, int k) {

    if (count == k) {
        return (sum == n) ? 1 : 0;
    }
    
    int r = k - count; 
    int max_i = (n - sum) / r; 
    int res = 0;
    
    for (int i = start; i <= max_i; ++i) {
        res += dfs(count + 1, sum + i, i, n, k);
    }
    
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    cout << dfs(0, 0, 1, n, k) << endl;
    return 0;
}