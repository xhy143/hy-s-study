#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int n;
int a[MAXN];
int bit[MAXN]; 
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int v) {
    while (x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0; 
    for (int i = n; i >= 1; i--) {
        ans += query(a[i] - 1);
        add(a[i], 1);
    }
    
    cout << ans << '\n';
    return 0;
}