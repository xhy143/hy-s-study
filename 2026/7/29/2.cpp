#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int maxn=1e3+10,maxm=1e3+10;
int r[maxn][maxm], d[maxn][maxm], g[maxn][maxm];
int sumc[maxn][maxm], sumf[maxn][maxm];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, id;
    cin >> t >> id;
    while(t--){
        int n, m, c, f;
        cin >> n >> m >> c >> f;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            for(int j = 1; j <= m; j++){
                g[i][j] = s[j-1] - '0';
            }
        }
        for(int i = 1; i <= n; i++){
            r[i][m+1] = 0;
            for(int j = m; j >= 1; j--){
                if(g[i][j] == 1) r[i][j] = 0;
                else r[i][j] = r[i][j+1] + 1;
            }
        }
        for(int j = 1; j <= m; j++){
            d[n+1][j] = 0;
            for(int i = n; i >= 1; i--){
                if(g[i][j] == 1) d[i][j] = 0;
                else d[i][j] = d[i+1][j] + 1;
            }
        }
        for(int j = 1; j <= m; j++){
            sumc[n+1][j] = 0;
            sumf[n+1][j] = 0;
            for(int i = n; i >= 1; i--){
                if(g[i][j] == 1){
                    sumc[i][j] = 0;
                    sumf[i][j] = 0;
                } else {
                    sumc[i][j] = (sumc[i+1][j] + r[i][j+1]) % mod;
                    sumf[i][j] = (sumf[i+1][j] + r[i][j+1] * d[i+1][j] % mod) % mod;
                }
            }
        }
        int ansc = 0, ansf = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(g[i][j] == 0){
                    if(i + 2 <= n && d[i+1][j] >= 1){
                        ansc = (ansc + r[i][j+1] * sumc[i+2][j] % mod) % mod;
                        ansf = (ansf + r[i][j+1] * sumf[i+2][j] % mod) % mod;
                    }
                }
            }
        }
        cout << (ansc * c) % mod << ' ' << (ansf * f) % mod << endl;
    }
    return 0;
}