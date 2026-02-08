#include <bits/stdc++.h>
using namespace std;
#define 什么78题目 0
#define OvO 0
int dp[10001]={-1};
int a[10001];
int pre[10001];
int main() {
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    dp[0] = 0;
    if(pre[n]<0){
        cout<<"Impossible";
        return OvO;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != -1 && pre[i] - pre[j] >= 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    if (dp[n] == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << dp[n] << endl;
    }
    
    return 什么78题目;
}