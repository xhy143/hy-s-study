#include <bits/stdc++.h>
using namespace std;
vector<int> manacher(const string& s) {
    string t = "#";
    for (char c : s) {
        t+=c;
        t+='#';
    }
    int n = t.size();
    vector<int> d(n); 
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) k++;
        d[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        if (l >= r) {
            cout << n << "\n";
            continue;
        }
        string sub = s.substr(l, r - l + 1);
        int m = sub.size();
        string t = "#";
        for (char c : sub) {
            t.push_back(c);
            t.push_back('#');
        }
        auto d = manacher(sub);
        int t_len = t.size();
        int maxLen = 0;
        for (int i = 0; i < t_len; i++) {
            int rad = d[i]; 
            if (i - rad + 1 <= 1) {
                int len = rad - 1;
                maxLen = max(maxLen, len);
            }
        }
        int right_pos = t_len - 2;
        for (int i = 0; i < t_len; i++) {
            int rad = d[i];
            if (i + rad - 1 >= right_pos) {
                int len = rad - 1;
                maxLen = max(maxLen, len);
            }
        }
        cout << 2 * l + maxLen << "\n";
    }
    
    return 0;
}