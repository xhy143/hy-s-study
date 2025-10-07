#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 1;
    
    for (int x : a) {
        int len = 0, maxLen = 0, last = -1;
        for (int v : a) {
            if (v == x) continue;
            if (v == last) len++;
            else len = 1;
            maxLen = max(maxLen, len);
            last = v;
        }
        ans = max(ans, maxLen);
    }
    
    cout << ans << endl;
    return 0;
}