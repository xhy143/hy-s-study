#include<bits/stdc++.h>
using namespace std;

int n;       
vector<int> queens;     
vector<vector<int> > s;  

bool check(int h, int l) {
    for (int i = 0; i < h; ++i) {
        if (queens[i] == l) {
            return false;
        }
    }
    
    for (int i = 0; i < h; ++i) {
        if (abs(queens[i] - l) == abs(i - h)) {
            return false;
        }
    }
    
    return true;
}

void dfs(int h) {
    if (h == n) {
        s.push_back(queens);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (check(h, i)) {
            queens[h] = i;
            dfs(h + 1);
        }
    }
}

int main() {
    cin >> n;
    queens.resize(n);
    
    dfs(0);
    for (int i = 0; i < (s.size()>3?3:s.size()); ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) cout << " ";
            cout << s[i][j] + 1; 
        }
        cout << endl;
    }
    
    cout << s.size() << endl;
    
    return 0;
}
