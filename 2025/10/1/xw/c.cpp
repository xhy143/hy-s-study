#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> happy(n+1, vector<int>(3));
    for(int i=1; i<=n; i++){
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
    }
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(j != k){
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + happy[i][j]);
                }
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}