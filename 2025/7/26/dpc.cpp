#include<bits/stdc++.h>
using namespace std;
int n;
int x[100005];
long long dp[100005];
int main(){
    int A,B,C;
    cin>>n>>A>>B>>C;
    for (int i = 1; i <= n; i++){
        int tmp = ((long long)A * i * i + B * i + C) % 20000;
        x[i] = tmp - 10000;
    }
    dp[0] = 0;
    dp[1] = x[1];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1], dp[i-2]) + x[i];
    }
    cout << dp[n] << endl;
}