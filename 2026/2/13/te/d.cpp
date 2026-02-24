#include <iostream>
using namespace std;

int fa[100005], sz[100005];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            merge(u, v);
        }
        else if (op == 2) {
            cout << (find(u) == find(v) ? "Yes" : "No") << endl;
        }
        else {
            if (find(u) == find(v) && sz[find(u)] >= 5)
                cout << "Ok" << endl;
            else
                cout << "OhNo" << endl;
        }
    }
    return 0;
}