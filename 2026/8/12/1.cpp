#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct flight {
    int in, out;
    bool operator<(const flight& b) const {
        return in < b.in;
    }
};
struct use {
    int out, id;
    bool operator<(const use& b) const {
        return out > b.out;  
    }
};
int n, m1, m2;
vector<flight> gn, gj;
int solve() {
    vector<int> cnt1(n + 1, 0);
    sort(gn.begin(), gn.end());
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<use> using1;
    for (int i = 1; i <= n; i++) {
        pq1.push(i);
    }
    for (auto& f : gn) {
        while (!using1.empty() && using1.top().out < f.in) {
            pq1.push(using1.top().id);
            using1.pop();
        }
        if (!pq1.empty()) {
            int id = pq1.top();
            pq1.pop();
            using1.push({f.out, id});
            cnt1[id]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt1[i] += cnt1[i - 1];
    }
    vector<int> cnt2(n + 1, 0);
    sort(gj.begin(), gj.end());
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<use> using2;
    for (int i = 1; i <= n; i++) {
        pq2.push(i);
    }
    for (auto& f : gj) {
        while (!using2.empty() && using2.top().out < f.in) {
            pq2.push(using2.top().id);
            using2.pop();
        }
        if (!pq2.empty()) {
            int id = pq2.top();
            pq2.pop();
            using2.push({f.out, id});
            cnt2[id]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt2[i] += cnt2[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, cnt1[i] + cnt2[n - i]);
    }
    
    return ans;
}
int main() {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        int in, out;
        cin >> in >> out;
        gn.push_back({in, out});
    }
    for (int i = 1; i <= m2; i++) {
        int in, out;
        cin >> in >> out;
        gj.push_back({in, out});
    }
    cout << solve() << endl;
    return 0;
}