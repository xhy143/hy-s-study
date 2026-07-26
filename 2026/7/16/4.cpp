#include <bits/stdc++.h>
using namespace std;
#define lc ((t) << 1)
#define rc (((t) << 1) + 1)

const int maxn = 1e5 + 10;

struct line {
    int x, y1, y2, val;
    bool operator<(const line &b) const {
        if (x != b.x) return x < b.x;
        return val > b.val;
    }
};

struct node {
    int l, r, mark;
    long long maxval;
} tree[maxn * 8];

int n, ys[maxn * 2], ql, qr, qk;
vector<line> events;

void update(int t) {
    tree[t].maxval = max(tree[lc].maxval, tree[rc].maxval);
}

void seg_add(int t, int tag) {
    tree[t].mark += tag;
    tree[t].maxval += tag;
}

void pushdown(int t) {
    if (tree[t].mark != 0) {
        seg_add(lc, tree[t].mark);
        seg_add(rc, tree[t].mark);
        tree[t].mark = 0;
    }
}

void build(int t, int l, int r) {
    tree[t].l = l;
    tree[t].r = r;
    tree[t].mark = 0;
    tree[t].maxval = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void modify(int t) {
    if (ql <= tree[t].l && qr >= tree[t].r) {
        seg_add(t, qk);
        return;
    }
    pushdown(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid) modify(lc);
    if (qr > mid) modify(rc);
    update(t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int w, h;
    cin >> n >> w >> h;
    
    for (int i = 0; i < n; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        
        // 窗口左下角坐标范围（边框不算，所以是开区间）
        // 能覆盖星星的窗口左下角 x 范围：[x-W+2, x-1]
        // y 范围：[y-H+2, y-1]
        int x1 = x - w + 2;
        int x2 = x;  // x-1 的下一位置，即 x
        int y1 = y - h + 2;
        int y2 = y;  // y-1 的下一位置，即 y
        
        events.push_back({x1, y1, y2 - 1, val});
        events.push_back({x2, y1, y2 - 1, -val});
        
        ys[i * 2] = y1;
        ys[i * 2 + 1] = y2 - 1;
    }
    
    int m = n * 2;
    sort(ys, ys + m);
    m = unique(ys, ys + m) - ys;
    
    for (auto &e : events) {
        e.y1 = lower_bound(ys, ys + m, e.y1) - ys;
        e.y2 = lower_bound(ys, ys + m, e.y2) - ys;
    }
    
    build(1, 0, m - 1);
    
    sort(events.begin(), events.end());
    
    long long ans = 0;
    int i = 0;
    
    while (i < events.size()) {
        int curX = events[i].x;
        int j = i;
        
        while (j < events.size() && events[j].x == curX && events[j].val > 0) {
            ql = events[j].y1;
            qr = events[j].y2;
            qk = events[j].val;
            modify(1);
            j++;
        }
        
        ans = max(ans, tree[1].maxval);
        
        while (j < events.size() && events[j].x == curX && events[j].val < 0) {
            ql = events[j].y1;
            qr = events[j].y2;
            qk = events[j].val;
            modify(1);
            j++;
        }
        
        i = j;
    }
    
    cout << ans << endl;
    return 0;
}