#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<vector<int>> mat;

mat operator *(const mat& a, const mat& b){
    int n = a.size();   
    int m = b[0].size();  
    int k = a[0].size();  
    mat c(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++){       
        for(int j = 0; j < m; j++){    
            int sum = 0;
            for(int p = 0; p < k; p++){ 
                sum += a[i][p] * b[p][j];
            }
            c[i][j] = sum;
        }
    }
    return c;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> k >> m;
    
    mat a(n, vector<int>(k, 0));
    mat b(k, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    
    mat c = a * b; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << c[i][j];
            if(j < m - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}