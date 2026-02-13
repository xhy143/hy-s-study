#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
} a[1005];

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge& o) const {
        return w < o.w;
    }
};
int n, m;
int fa[1005];

int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

bool hb(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return false;
    fa[px] = py;
    return true;
}

double dist(Point& a, Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        fa[i] = i;
    }
    vector<Edge> b;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        b.push_back({u, v, 0.0});
        hb(u, v);  
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find(i) != find(j)) { 
                double d = sqrt( pow( a[i].x-a[j].x , 2 ) + pow( a[i].y-a[j].y , 2 ));
                b.push_back({i, j, d});
            }
        }
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto& e : b) {
        if (e.w == 0.0) {
            hb(e.u, e.v);
        }
    }
    sort(b.begin(), b.end());
    double ans = 0.0;
    for (auto& e : b) {
        if (hb(e.u, e.v)) {
            ans += e.w;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
