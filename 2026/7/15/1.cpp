#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

struct Point {
    int x, y, id; 
};
int n;
Point p[MAXN];
int ans[MAXN];  
int bit[MAXN];  
vector<int> ys;  
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int v) {
    while (x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}
int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= lowbit(x);
    }
    return sum;
}
bool cmp(Point a,Point b){
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
        ys.push_back(p[i].y);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j <= n && p[j].x == p[i].x) j++;
        for (int k = i; k < j; k++) {
            int y_idx = lower_bound(ys.begin(), ys.end(), p[k].y) - ys.begin() + 1;
            ans[p[k].id] = query(y_idx - 1);
        }
        for (int k = i; k < j; k++) {
            int y_idx = lower_bound(ys.begin(), ys.end(), p[k].y) - ys.begin() + 1;
            add(y_idx, 1);
        }
        i = j;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}