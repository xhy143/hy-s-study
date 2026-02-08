#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define QWQ 0
const int N = 1000010, b = 131;
int h1[N], pw[N], h2[N], rh2[N];  
int n;
string s, t;

void reset(){
    pw[0] = 1;
    for(int i = 1; i < N; i++) 
        pw[i] = pw[i-1] * b;
}

void Hash(string str, int* h) {
    for (int i = 1; i <= str.size(); i++) {
        h[i] = h[i-1] * b + str[i-1];
    }
}

int getHash(int* h, int l, int r) {
    return h[r] - h[l-1] * pw[r-l+1];
}

signed main() {
    reset();
    cin >> s;
    n = s.size();
    t = s;
    for (int i = 0; i < n; i++) {
        t[i] = (s[i] == '0') ? '1' : '0';
    }
    Hash(s, h1);
    Hash(t, h2);
    string rt = t;
    reverse(rt.begin(), rt.end());
    Hash(rt, rh2);
    int ans = 0;
    for (int L = 1; L <= n; L++) {
        for (int R = L; R <= n; R++) {
            int len = R - L + 1;
            int hash_s = getHash(h1, L, R);
            int start = n - R + 1;
            int end = n - L + 1;
            int hash_t_rev = getHash(rh2, start, end);
            
            if (hash_s == hash_t_rev) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return QWQ;
}