#include<bits/stdc++.h>
using namespace std;

#define int long long
int a[111111], dp[111111];
string s;
signed main(){
    int n; cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    dp[0] = a[1];
    for (int i = 1; i < n; i ++){
        dp[i] = dp[i-1] + a[1];
        set<char> st;
        st.insert(s[i]);
        for (int j = i-1; j >= 0; j --){
            if (st.count(s[j])) break;
            st.insert(s[j]);
            dp[i] = max(dp[i], (j == 0 ? 0 : dp[j-1]) + a[i - j + 1]); 
        }
    }
    cout << dp[n-1];
    return 0;
}