#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define QWQ 0
const int N = 1000010, b = 131;
int h1[N], h2[N], pw[N];

void reset(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*b;
}

void Hash(string s, int* h) {
    for (int i = 1; i <= s.size(); i++) {
        h[i] = h[i-1] * b + s[i-1];
    }
}

int cut(int* k,int l,int r){
    return k[r] - k[l-1] * pw[r-l+1];
}

signed main() {
    reset();
    string s;
    cin >> s;
    int n = s.length();
    Hash(s, h1);
    string s2 = s;
    for(int i = 0; i < n; i++) {
        s2[i] = (s[i] == '0') ? '1' : '0';
    }
    Hash(s2, h2);
    
    int ans = 0;
    for(int zj = 0; zj < n; zj++) {
        int left = zj, right = zj + 1;
        int l = 0, r = min(zj + 1, n - zj - 1);
        while(l <= r) {
            int mid = (l + r) / 2;
            int l1 = left - mid + 1, r1 = left;
            int l2 = right, r2 = right + mid - 1;
            int hash1 = cut(h1, l1, r1);
            int hash2 = cut(h2, l2, r2);
            if(hash1 == hash2) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans += r;
    }
    
    cout << ans << endl;
    return QWQ;
}
