#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct event {
    int x, y1, y2, val;
    bool operator<(const event &b) const {
        if (x != b.x) return x < b.x;
        return val > b.val;
    }
};
int n;
vector<event> events;
vector<int> ys;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2, a;
        cin >> x1 >> y1 >> x2 >> y2 >> a;
        events.push_back({x1, y1, y2, a});
        events.push_back({x2, y1, y2, -a});
        ys.push_back(y1);
        ys.push_back(y2);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = ys.size();
    for (auto &e : events) {
        e.y1 = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
        e.y2 = lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin();
    }
    sort(events.begin(), events.end());
    vector<long long> diff(m + 2, 0);
    long long ans = 0;
    int i = 0;
    while (i < events.size()) {
        int curX = events[i].x;
        int j = i;
        while (j < events.size() && events[j].x == curX && events[j].val > 0) {
            int y1 = events[j].y1;
            int y2 = events[j].y2;
            int val = events[j].val;
            diff[y1] += val;
            diff[y2 + 1] -= val;  
            j++;
        }
        long long cur_sum = 0;
        long long max_at_curX = 0;
        for (int k = 0; k < m; k++) {
            cur_sum += diff[k];
            max_at_curX = max(max_at_curX, cur_sum);
        }
        ans = max(ans, max_at_curX);
        while (j < events.size() && events[j].x == curX && events[j].val < 0) {
            int y1 = events[j].y1;
            int y2 = events[j].y2;
            int val = events[j].val;
            diff[y1] += val;  
            diff[y2 + 1] -= val;
            j++;
        }
        i = j;
    }
    cout << ans << endl;
    return 0;
}