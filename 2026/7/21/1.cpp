#include<bits/stdc++.h>
using namespace std;
#define lc ((t)<<1)
#define rc (((t)<<1)+1)

const int maxn = 1e5 + 100;

struct line {
    int x, y1, y2, val;
    bool operator<(const line &b) const {
        if (x != b.x) return x < b.x;
        return val < b.val;  // 先负后正，处理边界
    }
};

struct node {
    int l, r, mark, maxval;
} tree[maxn * 8];

int n, ys[maxn * 2], ql, qr, qk;
vector<line> events;

void push_up(int t) {
    tree[t].maxval = max(tree[lc].maxval, tree[rc].maxval);
}

void seg_add(int t, int val) {
    tree[t].mark += val;
    tree[t].maxval += val;
}

void push_down(int t) {
    if (tree[t].mark != 0) {
        seg_add(lc, tree[t].mark);
        seg_add(rc, tree[t].mark);
        tree[t].mark = 0;
    }
}

void build(int t, int l, int r) {
    tree[t].l = l;
    tree[t].r = r;
    tree[t].mark = tree[t].maxval = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void modify(int t) {
    // 修复：应该用 <= 和 >=，而不是 >= 和 <=
    if (ql <= tree[t].l && qr >= tree[t].r) {
        seg_add(t, qk);
        return;
    }
    push_down(t);
    int mid = (tree[t].l + tree[t].r) >> 1;
    if (ql <= mid) modify(lc);
    if (qr > mid) modify(rc);
    push_up(t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        events.push_back({x1, y1, y2, val});
        events.push_back({x2, y1, y2, -val});
        ys[i * 2 - 2] = y1;
        ys[i * 2 - 1] = y2;
    }
    
    // 离散化y坐标
    sort(ys, ys + 2 * n);
    int m = unique(ys, ys + 2 * n) - ys;
    
    // 修复：正确处理y坐标区间
    // 使用左闭右开区间 [y1, y2)，线段树维护的是离散化后的点
    for (auto &e : events) {
        e.y1 = lower_bound(ys, ys + m, e.y1) - ys;
        e.y2 = lower_bound(ys, ys + m, e.y2) - ys - 1;
        // 确保 y1 <= y2
        if (e.y1 > e.y2) {
            // 如果y1和y2相邻，说明没有内部点
            // 可以交换或者跳过，但通常不会出现
            swap(e.y1, e.y2);
        }
    }
    
    build(1, 0, m - 1);
    sort(events.begin(), events.end());
    
    long long ans = 0;
    int i = 0;
    
    // 修复：正确的扫描逻辑
    while (i < events.size()) {
        int curX = events[i].x;
        
        // 处理当前x位置的所有事件
        while (i < events.size() && events[i].x == curX) {
            ql = events[i].y1;
            qr = events[i].y2;
            qk = events[i].val;
            if (ql <= qr) {  // 只有有效区间才更新
                modify(1);
            }
            i++;
        }
        
        // 关键修复：在下一个事件位置更新答案
        // 这样确保取的是两个事件之间的内部区域
        if (i < events.size()) {
            ans = max(ans, 1LL * tree[1].maxval);
        }
    }
    
    // 特殊情况：可能没有事件之间的区域，但矩形内部可能有最大覆盖
    // 最后的答案也要考虑
    ans = max(ans, 1LL * tree[1].maxval);
    
    cout << ans << '\n';
    return 0;
}