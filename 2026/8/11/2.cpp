#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

struct DistInfo {
    long long d;
    int u, v;
};

int main() {
    freopen("second.in", "r", stdin);
    freopen("second.out", "w", stdout);
    
    int N;
    cin >> N;
    vector<Point> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    if (N <= 2) {
        for (int i = 0; i < N; i++) cout << 0 << endl;
        return 0;
    }
    
    // 计算所有点对
    vector<DistInfo> all_dists;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long dx = p[i].x - p[j].x;
            long long dy = p[i].y - p[j].y;
            all_dists.push_back({dx*dx + dy*dy, i, j});
        }
    }
    
    // 按距离从大到小排序
    sort(all_dists.begin(), all_dists.end(), [](const DistInfo& a, const DistInfo& b) {
        return a.d > b.d;
    });
    
    // 对每个点，找到删除它后的最大和次大距离
    for (int i = 0; i < N; i++) {
        vector<long long> top_dists;
        
        for (const auto& info : all_dists) {
            if (info.u == i || info.v == i) continue;
            if (top_dists.empty() || info.d != top_dists.back()) {
                top_dists.push_back(info.d);
                if (top_dists.size() >= 2) break;
            }
        }
        
        if (top_dists.size() < 2) {
            cout << 0 << endl;
        } else {
            cout << top_dists[1] << endl;  // 次大值
        }
    }
    
    return 0;
}