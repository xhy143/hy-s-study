#include <iostream>
#include <vector>
using namespace std;

bool check(int t, int M, vector<int>& a) {
    int last = 0; 
    for (int i = 0; i < a.size(); ++i) {
        int x = a[i];
        int r = x + t;
        if (r < M) {
            if (last > r) return false;
            last = max(last, x);
        } else {
            if (last <= M - 1) {
                if (last >= x) {
                } else if (last < x) {
                    last = x;
                } 
            } 
            if (last > M - 1) last = last % M; 
            if (last > (r % M)) return false;
            last = max(last, 0); 
        }
    }
    return true;
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int lo = 0, hi = M, ans = M;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, M, a)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}