#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
#define ll __int128

struct frac{
    ll q;
    ll p; 
    ll gcd(ll a, ll b){
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        while(b){
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    void hj(){
        if(q == 0){
            p = 1;
            return;
        }
        ll g = gcd(q, p);
        q /= g;
        p /= g;
        if(p < 0){
            q = -q;
            p = -p;
        }
    }
    frac operator +(const frac& oth) const {
        frac res;
        res.q = q * oth.p + oth.q * p;
        res.p = p * oth.p;
        res.hj();
        return res;
    }
    frac operator /(ll div) const {
        frac res;
        res.q = q;
        res.p = p * div;
        res.hj();
        return res;
    }
} dp[maxn];
void write(ll n){
    if(n < 0){
        cout << '-';
        n = -n;
    }
    if(n > 9) write(n / 10);
    cout << (int)(n % 10);
}
int n, m;
int in[maxn], out[maxn];
vector<int> g[maxn];
void topo(){
    queue<int> q;
    for(int i = 1; i <= m; i++){
        q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            dp[v] = dp[v] + dp[u] / out[u];
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> out[i];
        for(int j = 1; j <= out[i]; j++){
            int x;
            cin >> x;
            g[i].push_back(x);
            in[x]++;
        }
    }
    for(int i = 1; i <= n; i++){
        dp[i].q = 0;
        dp[i].p = 1;
    }
    for(int i = 1; i <= m; i++){
        dp[i].q = 1;
        dp[i].p = 1;
    }
    topo();
    for(int i = 1; i <= n; i++){
        if(out[i] == 0){
            write(dp[i].q);
            cout << ' ';
            write(dp[i].p);
            cout << '\n';
        }
    }
    
    return 0;
}