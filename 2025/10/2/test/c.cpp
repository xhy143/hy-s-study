#include <bits/stdc++.h>
using namespace std;
vector<int> normalize(vector<int> state) {
    sort(state.begin(), state.end(), greater<int>());
    return state;
}

int solve(vector<int> arr) {
    int n = arr.size();
    map<vector<int>, int> dist;
    queue<vector<int> > q;
    dist[arr] = 0;
    q.push(arr);
    while (!q.empty()) {
        vector<int> cur = q.front(); q.pop();
        int steps = dist[cur];
        bool all_zero = true;
        for (int x : cur) {
            if (x > 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) return steps;
        for (int i = 0; i < n; i++) {

            if (cur[i] <= 0) continue;
            vector<int> nxt = cur;
            nxt[i] -= 9;

            for (int j = 0; j < n; j++) {

                if (j == i || nxt[j] <= 0) continue;
                int save_j = nxt[j];
                nxt[j] -= 3;

                for (int k = 0; k < n; k++) {

                    if (k == i || k == j || nxt[k] <= 0) continue;
                    int save_k = nxt[k];
                    nxt[k] -= 1;

                    vector<int> nxt_norm = normalize(nxt);
                    if (dist.find(nxt_norm) == dist.end()) {
                        dist[nxt_norm] = steps + 1;
                        q.push(nxt_norm);
                    }
                    nxt[k] = save_k; 

                }

                vector<int> nxt_norm = normalize(nxt);
                if (dist.find(nxt_norm) == dist.end()) {
                    dist[nxt_norm] = steps + 1;
                    q.push(nxt_norm);
                }
                nxt[j] = save_j;
            }

            vector<int> nxt_norm = normalize(nxt);
            if (dist.find(nxt_norm) == dist.end()) {
                dist[nxt_norm] = steps + 1;
                q.push(nxt_norm);
            }
        }
    }

    return -1; 
}

int main() {
    int n;
    freopen("attack.in","r",stdin);
    freopen("attack.out","w",stdout);
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {

        cin >> arr[i];

    }

    cout << solve(arr) << endl;

    return 0;
}