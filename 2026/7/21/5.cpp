#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;  
struct node {
    int son[26], fail, cnt, last;
    int id;  
} tree[maxn];
int tot;
int plen[maxn]; 
void init() {
    tot = 0;
    memset(tree[0].son, 0, sizeof(tree[0].son));
    tree[0].fail = tree[0].last = tree[0].cnt = 0;
    tree[0].id = -1;
}
int newnode() {
    ++tot;
    memset(tree[tot].son, 0, sizeof(tree[tot].son));
    tree[tot].fail = tree[tot].last = tree[tot].cnt = 0;
    tree[tot].id = -1;
    return tot;
}
void insert(const string &s, int id) {
    int u = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (!tree[u].son[idx])
            tree[u].son[idx] = newnode();
        u = tree[u].son[idx];
    }
    tree[u].cnt++;
    tree[u].id = id;
    plen[id] = s.size();
}
void build() {
    queue<int> que;
    for (int i = 0; i < 26; i++) {
        if (tree[0].son[i]) {
            tree[tree[0].son[i]].fail = 0;
            tree[tree[0].son[i]].last = 0;
            que.push(tree[0].son[i]);
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < 26; i++) {
            int &v = tree[u].son[i];
            if (v) {
                tree[v].fail = tree[tree[u].fail].son[i];
                int f = tree[v].fail;
                tree[v].last = (tree[f].cnt ? f : tree[f].last);
                que.push(v);
            } else {
                v = tree[tree[u].fail].son[i];
            }
        }
    }
}
void query(const string &s, vector<int> &ans, int n) {
    int u = 0;
    vector<int> last_end(n, -1); 
    for (int i = 0; i < s.size(); i++) {
        u = tree[u].son[s[i] - 'a'];
        for (int t = u; t; t = tree[t].last) {
            if (tree[t].cnt && tree[t].id != -1) {
                int id = tree[t].id;
                int len = plen[id];
                if (last_end[id] < i - len + 1) {
                    ans[id]++;
                    last_end[id] = i;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    init();
    vector<string> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        insert(p[i], i);
    }
    build();
    vector<int> ans(n, 0);
    query(s, ans, n);
    int max_cnt = -1;
    int max_id = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] > max_cnt) {
            max_cnt = ans[i];
            max_id = i;
        }
    }
    cout << p[max_id] << '\n';
    
    return 0;
}