#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<char> chars;
bool forbid[10][256] = {false};
int cnt = 0;
const int MOD = 9901;

void backtrack(int pos, vector<bool>& used) {
    if (pos > n) { 
        cnt = (cnt + 1) % MOD;
        return;
    }
    for (int i = 0; i < m; ++i) {
        char c = chars[i];
        if (!used[i] && !forbid[pos][c]) { 
            used[i] = true;
            backtrack(pos + 1, used);
            used[i] = false; 
        }
    }
}

int main() {
    cin >> n >> m >> k;
    chars.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> chars[i];
    }
    for (int i = 0; i < k; ++i) {
        int p;
        char c;
        cin >> p >> c;
        forbid[p][c] = true;
    }
    vector<bool> used(m, false);
    backtrack(1, used);
    cout << cnt % MOD << endl;
    return 0;
}
