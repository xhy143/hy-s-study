#include <bits/stdc++.h>
using namespace std;
struct dy {
    int start;
    int end;
};
bool cmp(const dy &a, const dy &b) {
    return a.end < b.end;
}

int main() {
    int n;
    while (cin >> n && n != 0) {  
        vector<dy> dys(n);
        for (int i = 0; i < n; i++) {
            cin >> dys[i].start >> dys[i].end;
        }
        
        sort(dys.begin(), dys.end(), cmp);
        
        int ans = 0;
        int last_end = -1;  
        for (const auto &dy : dys) {
            if (dy.start >= last_end) {
                ans++;
                last_end = dy.end;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
