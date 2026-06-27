#include <bits/stdc++.h>
using namespace std;
#define ll long long
void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (b == 0) {
        d = a, x = 1, y = 0;
        return;
    }
    ll nx, ny;
    exgcd(b, a % b, d, nx, ny);
    x = ny;
    y = nx - (a / b) * ny;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll n, d, x, y;
        cin >> n >> d >> x >> y;
        if (x == y) {
            cout << 0 << endl;
            continue;
        }
        ll c = (y - x + n) % n;
        ll a = d;     
        ll b = n;     
        ll g, k, t;  
        exgcd(a, b, g, k, t);
        if (c % g != 0) {
            cout << "Impossible" << endl;
            continue;
        }
        k = k * (c / g);          
        ll mod = b / g;            
        k = (k % mod + mod) % mod; 
        if (k == 0) {
            cout << mod << endl;
        } else {
            cout << k << endl;
        }
    }
    
    return 0;
}