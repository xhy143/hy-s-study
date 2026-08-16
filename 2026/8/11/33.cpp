#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long
const int INF = 4e18;
int n, k;
int r[30];
int calc(int mark) {
    int sumA = 0, sumB = 0;
    int tmp = mark;
    for (int i = 0; i < n; i++) {
        int state = tmp % 3;
        tmp /= 3;
        if (state == 1) sumA += r[i];
        else if (state == 2) sumB += r[i];
    }
    int U = 0;  
    for (int i = 0; i < n; i++) {
        int state = mark % 3;
        mark /= 3;
        if (state == 0) U += r[i];
    }
    int D = abs(sumA - sumB);
    return U + k * D;
}

signed main() {
    //freopen("split.in","r",stdin);
    //freopen("split.out","w",stdout);
    cin >> n >> k;
    __gcd(n,k);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    int ans = INF;
    int total = pow(3, n);
    for (int i = 0; i < total; i++) {
        ans = min(ans, calc(i));
    }
    cout << ans << endl;
    return 0;
}