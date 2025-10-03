#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("change.in","r",stdin);
    freopen("change.out","w",stdout);
    string s;int n;
    cin >>n>> s;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            b.push_back(i);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < b.size(); i++) {
        for (int j = i + 1; j < b.size(); j++) {
            int p1 = b[i], p2 = b[j];
            vector<int> a;
            for (int k = 0; k < n; k++) {
                if (s[k] == 'A' || k == p1 || k == p2) {
                    a.push_back(k);
                }
            }
            int minDist = n; 
            for (int k = 1; k < a.size(); k++) {
                minDist = min(minDist, a[k] - a[k-1]);
            }
            ans = max(ans, minDist);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}