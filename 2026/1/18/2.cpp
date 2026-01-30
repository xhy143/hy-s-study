#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
int parent[MAXN]; 
int n, Q;

bool isManager(int x, int y) {
    int cur = y;
    while (cur != -1) {
        if (cur == x) return true;
        cur = parent[cur];
    }
    return false;
}

int main() {
    cin >> n;
    
    parent[0] = -1;  
    
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
    }
    
    cin >> Q;
    
    while (Q--) {
        int m;
        cin >> m;
        
        vector<int> employees(m);
        for (int i = 0; i < m; i++) {
            cin >> employees[i];
        }
        
        int ans = -1;
        
        for (int candidate = n - 1; candidate >= 0; candidate--) {
            bool valid = true;
            for (int emp : employees) {
                if (!isManager(candidate, emp)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                ans = candidate;
                break;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}