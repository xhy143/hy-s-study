#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100005;

struct Point {
    int x, y, id;  // id记录原始输入顺序
};

int n;
Point p[MAXN];
int ans[MAXN];     // 存储每个点的答案
int bit[MAXN];     // 树状数组
vector<int> ys;    // 用于y坐标离散化

// 树状数组操作（完全沿用您的模板风格）
int lowbit(int x) { return x & (-x); }

void add(int x, int v) {
    while (x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int find(int x) {
    int sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= lowbit(x);
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    // 读入所有点
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
        ys.push_back(p[i].y);
    }
    
    // y坐标离散化
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    // 按x排序，x相同时按y排序
    sort(p + 1, p + n + 1, [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    
    // 遍历排序后的点
    for (int i = 1; i <= n; ) {
        int j = i;
        // 找出所有x相同的点
        while (j <= n && p[j].x == p[i].x) j++;
        
        // 先查询这些点（避免x相同的点互相计入）
        for (int k = i; k < j; k++) {
            // 找到当前点的y在离散化数组中的位置
            int y_idx = lower_bound(ys.begin(), ys.end(), p[k].y) - ys.begin() + 1;
            // 查询小于当前y的点数（严格小于）
            ans[p[k].id] = find(y_idx - 1);
        }
        
        // 再统一插入这些点
        for (int k = i; k < j; k++) {
            int y_idx = lower_bound(ys.begin(), ys.end(), p[k].y) - ys.begin() + 1;
            add(y_idx, 1);
        }
        
        i = j;
    }
    
    // 按原始顺序输出答案
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}