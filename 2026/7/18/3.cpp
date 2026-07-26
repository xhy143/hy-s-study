#include <bits/stdc++.h>
using namespace std;
string toBaseK(int num, int k) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res = char('0' + num % k) + res;
        num /= k;
    }
    return res;
}
int fromBaseK(const string& s, int k) {
    int res = 0;
    for (char c : s) {
        res = res * k + (c - '0');
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    
    int A[10][10], B[10][10];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }
    
    string n_str, x_str, y_str;
    cin >> n_str >> x_str >> y_str;
    
    int n = fromBaseK(n_str, k);
    int x = fromBaseK(x_str, k);
    int y = fromBaseK(y_str, k);
    
    string xs = x_str;
    string ys = y_str;
    
    int ans = 0;
    for (int a = 1; a <= n; a++) {
        string as = toBaseK(a, k);
        int maxLen = max({as.size(), xs.size(), ys.size()});
        while (as.size() < maxLen) as = "0" + as;
        while (xs.size() < maxLen) xs = "0" + xs;
        while (ys.size() < maxLen) ys = "0" + ys;
        
        bool cond1 = true, cond2 = true;
        for (int i = 0; i < maxLen; i++) {
            int ad = as[i] - '0';
            int xd = xs[i] - '0';
            int yd = ys[i] - '0';
            if (A[ad][xd] != yd) cond1 = false;
            if (B[ad][xd] != yd) cond2 = false;
            if (!cond1 && !cond2) break;
        }
        if (cond1 || cond2) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}