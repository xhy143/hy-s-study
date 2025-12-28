#include<bits/stdc++.h>
using namespace std;

int main(){
    int qzh[15][15] = {0}; 
    int a[15][15];
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            qzh[i][j] = qzh[i-1][j] + qzh[i][j-1] - qzh[i-1][j-1] + a[i][j];
        }
    }
    
    int ans = 0;  
    for(int x1 = 1; x1 <= n; x1++){
        for(int y1 = 1; y1 <= m; y1++){
            for(int x2 = x1; x2 <= n; x2++){
                for(int y2 = y1; y2 <= m; y2++){
                    int cnt = qzh[x2][y2] - qzh[x1-1][y2] - qzh[x2][y1-1] + qzh[x1-1][y1-1];
                    int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                    
                    if(cnt == area){
                        ans = max(ans, area);
                    }
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}