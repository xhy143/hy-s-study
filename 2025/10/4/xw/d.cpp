#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    freopen("gap.in", "r", stdin);
    freopen("gap.out", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int N, d;
        cin >> N >> d;
        vector<string> graph(N);
        for (int i = 0; i < N; i++) {
            cin >> graph[i];
        }
        vector<vector<int>> dist(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
            for (int j = 0; j < N; j++) {
                if (graph[i][j] == '1') {
                    dist[i][j] = d;
                }
            }
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        bool disconnected = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] == INF) {
                    disconnected = true;
                    break;
                }
            }
            if (disconnected) break;
        }
        if (disconnected) {
            cout << -1 << endl;
            continue;
        }
        int maxDiff = 0;
        for (int i = 0; i < N; i++) {
            int minVal = INF, maxVal = -INF;
            for (int j = 0; j < N; j++) {
                if (dist[i][j] < minVal) minVal = dist[i][j];
                if (dist[i][j] > maxVal) maxVal = dist[i][j];
            }
            maxDiff = max(maxDiff, maxVal - minVal);
        }

        cout << maxDiff << endl;
    }

    return 0;
}