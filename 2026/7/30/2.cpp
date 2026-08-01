#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
string solve(int n, ull k) {
    if (n == 0) return "";
    ull mid = 1ULL << (n - 1); 
    if (k < mid) {
        return "0" + solve(n - 1, k);
    } else {
        ull kk = mid - (k - mid) - 1;
        return "1" + solve(n - 1, kk);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ull k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}