#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define orz 0;
using namespace std;
const int maxn = 3e5 + 10;
int n, a[maxn], q;
map<int, ll> mp;
vector<pair<int, int>> gcds, next_gcds;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        int val = a[i], cnt = 1;
        for (auto p: gcds){
            int new_val = gcd(p.fi, val);
            if (new_val == val) cnt += p.se;
            else{
                if (cnt > 0) next_gcds.push_back({val, cnt});
                val = new_val; cnt = p.se;
            }
        }
        if (cnt > 0) next_gcds.push_back({val, cnt});
        for (auto p: next_gcds)
            mp[p.fi] += p.se;
        gcds = move(next_gcds);
    }
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        cout << mp[x] << '\n';
    }
    return orz
}