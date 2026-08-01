#include<bits/stdc++.h>
#define in freopen("pick.in","r",stdin);
#define out freopen("pick.out","w",stdout);
#define int long long
using namespace std;
const int maxn=2e5+100;
struct hero {
    int val, pos;
    bool operator<(const hero& b) const {
        if(val == b.val) return pos < b.pos;
        return val > b.val;
    }
};
int used[maxn];
vector<hero> dps; 
vector<hero> tank; 
int n, m;
int SA[maxn], SD[maxn]; 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    in out
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        dps.push_back({val, i});
    }
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        tank.push_back({val, i});
    }
    sort(dps.begin(), dps.end());
    sort(tank.begin(), tank.end());
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> SA[i];
    for(int i = 1; i <= m; i++) cin >> SD[i];
    int p1 = 0, p2 = 0; 
    for(int i = 1; i <= m; i++){
        while(p1 < n && used[dps[p1].pos]) p1++;
        while(p2 < n && used[tank[p2].pos]) p2++;
        if(p1 >= n && p2 >= n) break;
        int curSA = SA[i], curSD = SD[i];
        int gainDPS = LLONG_MIN;
        int chooseDPS = -1;
        if(p1 < n) {
            int idx = dps[p1].pos;
            gainDPS = 2 * curSA * dps[p1].val + dps[p1].val * dps[p1].val;
            chooseDPS = idx;
        }
        int gainTank = LLONG_MIN;
        int chooseTank = -1;
        if(p2 < n) {
            int idx = tank[p2].pos;
            gainTank = 2 * curSD * tank[p2].val + 1LL * tank[p2].val * tank[p2].val;
            chooseTank = idx;
        }
        int choose;
        if(gainDPS > gainTank) {
            choose = chooseDPS;
        } else if(gainTank > gainDPS) {
            choose = chooseTank;
        } else {
            choose = min(chooseDPS, chooseTank);
        }
        cout << choose << '\n';
        used[choose] = 1;
        while(p1 < n && used[dps[p1].pos]) p1++;
        while(p2 < n && used[tank[p2].pos]) p2++;
    }
    return 0;
}