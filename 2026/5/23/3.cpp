#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<vector<int> > mat;
int n, k, b, q; 
mat operator *(mat a, mat b) {
    int m = a.size(), k = a[0].size(), n = b[0].size();
    mat c(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int sum = 0;  
            for(int p = 0; p < k; p++) {
                sum =(sum + a[i][p] * b[p][j])% ::n;
            }
            c[i][j] = sum % ::n;  
        }
    }
    return c;
}

mat qpow(mat a, int b) {
    int sz = a.size();
    mat res(sz, vector<int>(sz, 0));
    for(int i = 0; i < sz; i++) {
        res[i][i] = 1;
    }
    
    while(b > 0) {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
signed main() {
    cin >> n >> k >> b >> q;
    mat M = {
        {1, 1          , 0},
        {k, (1 + k) % n, b},
        {0, 0          , 1}
    };
    while(q--) {
        int s, v, t;
        cin >> s >> v >> t;
        mat Mt = qpow(M, t);
        int x = (Mt[0][0] * s + Mt[0][1] * v + Mt[0][2]) % n;
        
        cout << x << endl;
    }
    
    return 0;
}