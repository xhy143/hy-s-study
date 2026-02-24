#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("ab.in", "r", stdin);
    freopen("ab.out", "w", stdout);
    string s;
    cin >> s;
    int ans = 0;
    int pos = 0; 
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            ans += i - pos;
            pos++;
        }
    }
    cout << ans << endl;
    return 0;
}