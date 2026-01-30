#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[10005];  
int t[105];   
ll sco[10005]; 
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    for(int i = 0; i < n; i++){
        cin >> sco[i];
    }
    
    for(int i = 0; i <= n; i++){
        dp[i] = LLONG_MIN;
    }
    dp[0] = 0;
    
    ll ans = LLONG_MIN;
    
    for(int i = 0; i < n; i++){
        if(dp[i] == LLONG_MIN){
            continue;
        }
        for(int j = 0; j < m; j++){
            int nxt = i + t[j];
            ll nsco = dp[i] + sco[i];
            
            if(nxt >= n){
                ans = max(ans, nsco);
            } else {
                dp[nxt] = max(dp[nxt], nsco);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}