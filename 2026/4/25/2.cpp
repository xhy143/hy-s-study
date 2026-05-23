#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<vector<int> > mat;
const int mod = 1e9+7;
mat operator * (mat a, mat b) {
    int m = a.size(), n = b[0].size(), k = a[0].size();
    mat c(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ll sum = 0;
            for(int p = 0; p < k; p++) 
                sum = (sum + 1ll * a[i][p] * b[p][j]) % mod;
            c[i][j] = sum;
        }
    }
    return c;
}
mat fastpow(mat a, long long k) {
    int n = a.size();
    if(k == 0) {
        mat res(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    mat ans = fastpow(a, k/2);
    ans = ans * ans;
    if(k % 2 == 1) ans = ans * a;
    return ans;
}
int main() {
    ll n;
    int m;
    cin >> n >> m;
    if (m > n) { 
        if (n == 1 && m == 1) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    if (n == 1 && m == 1) { 
        cout << 1 << endl;
        return 0;
    }
    mat t(m, vector<int>(m, 0));
    for (int j = 0; j < m; j++) {
        if (j - 1 >= 0) t[j][j - 1] = 1; 
        t[j][j] = 1; 
        if (j + 1 < m) t[j][j + 1] = 1;
    }
    mat p = fastpow(t, n - 1);
    cout << p[m - 1][0] << endl;
    return 0;
}