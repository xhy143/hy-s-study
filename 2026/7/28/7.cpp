#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+100;
int a[maxn], sum[maxn];
signed main(){
    int n, A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + a[i];
    }
    int bestPower = -1, bestFull = -1, bestMin = -1;
    for(int full=0; full<=n; full++){
        int costFull = 0;
        if(full > 0){
            int start = n - full + 1;
            costFull = full * A - (sum[n] - sum[start-1]);
        }
        if(costFull > m) break;
        int remaining = m - costFull;
        int cnt = n - full; 
        if(cnt == 0){
            int power = full * cf;
            if(power > bestPower){
                bestPower = power;
                bestFull = full;
                bestMin = A;
            }
            continue;
        }
        int l = 0, r = A, minLevel = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            int pos = upper_bound(a+1, a+1+cnt, mid-1) - a;
            int lessCnt = pos - 1;
            int cost = lessCnt * mid - sum[lessCnt];
            if(cost <= remaining){
                minLevel = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        int power = full * cf + minLevel * cm;
        if(power > bestPower){
            bestPower = power;
            bestFull = full;
            bestMin = minLevel;
        }
    }
    cout << bestPower << endl;
    for(int i=n-bestFull+1; i<=n; i++){
        a[i] = A;
    }
    for(int i=1; i<=n-bestFull; i++){
        if(a[i] < bestMin){
            a[i] = bestMin;
        }
    }
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}