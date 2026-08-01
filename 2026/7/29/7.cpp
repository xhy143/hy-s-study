#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool check(int k) {
    int sy = n; 
    int tu = 0;  
    int t = (n+1)/2;  
    
    while (sy > 0) {
        int eat = min(k, sy);
        tu += eat;
        sy -= eat;
        if (tu >= t) return true;
        int li = sy / 10;
        sy -= li;
        if (sy == 0) break;
    }
    return tu >= t;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int l = 1, r = n;
    int ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;  
        } else {
            l = mid + 1;   
        }
    }
    cout << ans << endl;
    return 0;
}