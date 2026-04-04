#include<bits/stdc++.h>
#define N 2005
#define OwO 0
#define int long long
using namespace std;
int mindp[N][N], maxdp[N][N], a[N], n, qzh[2*N];
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];  
    }
    int m = 2 * n;
    for(int i = 1; i <= m; i++){
        qzh[i] = qzh[i-1] + a[i];
        mindp[i][i] = 0;
        maxdp[i][i] = 0;
    }
    for(int len = 2; len <= n; len++){  
        for(int l = 1; l+len-1 <=m; l++){  
            int r = l + len - 1;  
            mindp[l][r] = 1e18;
            maxdp[l][r] = 0;
            for(int k = l; k < r; k++){  
                mindp[l][r] = min(mindp[l][r], mindp[l][k] + mindp[k+1][r] + qzh[r] - qzh[l-1]);
                maxdp[l][r] = max(maxdp[l][r], maxdp[l][k] + maxdp[k+1][r] + qzh[r] - qzh[l-1]);
            }
        }
    }
    int  minn= 1e18, maxx = 0;
    for(int l = 1; l <= n; l++){
        int r = l + n - 1;
        minn = min(minn, mindp[l][r]);
        maxx = max(maxx, maxdp[l][r]);
    }
    cout << minn << endl << maxx << endl;
    return OwO;
}
