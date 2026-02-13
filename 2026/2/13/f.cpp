#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool> > isPal(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) isPal[i][i] = true;
    for (int i = 0; i < n-1; i++) isPal[i][i+1] = (s[i] == s[i+1]);
    for (int len = 3; len <= n; len++) {
        for (int l = 0; l+len-1 < n; l++) {
            int r = l+len-1;
            isPal[l][r] = (s[l] == s[r] && isPal[l+1][r-1]);
        }
    }
    queue<pair<int,int> > q;
    vector<vector<int> > dist(n, vector<int>(n, -1));
    
    dist[0][n-1] = 0;
    q.push(make_pair(0, n-1));
    
    int ans = -1;
    
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        int l = cur.first;
        int r = cur.second;
        int len = r-l+1;
        int d = dist[l][r];
        if (l > r) {
            ans = d;
            break;
        }
        vector<int> lens;
        lens.push_back(len/2);
        lens.push_back((len+1)/2);
        
        for (int i = 0; i < lens.size(); i++) {
            int p = lens[i];
            if (p == 0) continue;
            if (isPal[l][l+p-1]) {
                int nl = l+p, nr = r;
                if (dist[nl][nr] == -1) {
                    dist[nl][nr] = d+1;
                    q.push(make_pair(nl, nr));
                }
            }
            if (isPal[r-p+1][r]) {
                int nl = l, nr = r-p;
                if (dist[nl][nr] == -1) {
                    dist[nl][nr] = d+1;
                    q.push(make_pair(nl, nr));
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}