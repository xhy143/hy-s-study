#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

ll station, happy, maxdp, mindp, sum, minn = 0x7fffffff, maxx = -0x7fffffff, maxn = -0x7fffffff;

int main() {
    cin >> station;
    bool first = true;
    maxdp = happy;
            mindp = happy;
            maxx = happy;
            minn = happy;
    
    for (ll i = 0; i < station; i++) {
        cin >> happy;
        sum += happy;
        
        // 更新最大值（用于全负数情况）
        maxn = max(maxn, happy);
        
        // 最大子段和
        
            maxdp = max(happy, maxdp + happy);
            maxx = max(maxx, maxdp);
            
            // 最小子段和
            mindp = min(happy, mindp + happy);
            minn = min(minn, mindp);
        
    }
    
    // 特判全负数
    if (maxn < 0) {
        cout << maxn;
    } else {
        // 环形最大子段和 = max(最大子段和, 总和 - 最小子段和)
        ll ans = max(sum - minn, maxx);
        cout << ans;
    }
    
    return 0;
}