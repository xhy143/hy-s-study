#include <bits/stdc++.h>
using namespace std;
string solve_one(int n, vector<int>& s) {
    if (s[0] != 1) return "No";
    int max_s = s.back();
    bool all_continuous = true;
    for (int i = 1; i <= max_s; i++) {
        if (i > n || s[i-1] != i) {
            all_continuous = false;
            break;
        }
    }
    if (all_continuous) {
        return "Yes " + string(max_s, '1');
    }
    if (max_s % 2 == 1) {
        bool all_odd = true;
        for (int i = 0; i < n; i++) {
            if (s[i] % 2 == 0) {
                all_odd = false;
                break;
            }
            if (s[i] != 2*i + 1) {
                all_odd = false;
                break;
            }
        }
        if (all_odd && (2*n - 1) == max_s) {
            string res = "1";
            for (int i = 1; i < max_s; i++) {
                res += (i % 2 == 1) ? '0' : '1';
            }
            return "Yes " + res;
        }
    }
    
    return "No";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, V;
    cin >> T >> V;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        cout << solve_one(n, s) << '\n';
    }
    
    return 0;
}