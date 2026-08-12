#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=7e2+10,mod=1e9+7;
int dp[maxn][maxn][3][3],match_pos[maxn];
string str;
void upd(int &x,int y){
    (x+=y)%=mod;
}
void dfs(int l, int r){
    if (l + 1 == r){
        dp[l][r][0][1] = dp[l][r][0][2] = 1;
        dp[l][r][1][0] = dp[l][r][2][0] = 1;
        return;
    }
    if (match_pos[l] == r){
        dfs(l + 1, r - 1);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (i != 1) upd(dp[l][r][1][0], dp[l + 1][r - 1][i][j]);
                if (j != 1) upd(dp[l][r][0][1], dp[l + 1][r - 1][i][j]);
                if (i != 2) upd(dp[l][r][2][0], dp[l + 1][r - 1][i][j]);
                if (j != 2) upd(dp[l][r][0][2], dp[l + 1][r - 1][i][j]);
            }
        }
        return;
    }
    int p = match_pos[l];
    dfs(l, p); dfs(p + 1, r);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int x = 0; x < 3; x++){
                for (int y = 0; y < 3; y++){
                    if (x > 0 && x == y) continue;
                    upd(dp[l][r][i][j], 1ll * dp[l][p][i][x] * dp[p + 1][r][y][j]);
                }
            }
        }
    }
}
int ans=0;
signed main(){
    cin >> str;
    stack<int> stk;
    for (int i = 0; i < (int)str.size(); i++){
        if (str[i] == '(') stk.push(i);
        else{
            int l = stk.top(); stk.pop();
            match_pos[l] = i; match_pos[i] = l;
        }
    }
    dfs(0, str.size() - 1);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            upd(ans, dp[0][str.size() - 1][i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}