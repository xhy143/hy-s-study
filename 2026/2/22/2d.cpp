#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("dinner.in","r",stdin);
    freopen("dinner.out","w",stdout);
    int N, M;
    cin >> N >> M;
    vector<long long> m(N);
    for (int i = 0; i < N; i++) {
        long long A, B;
        cin >> A >> B;
        m[i] = max(A, B);
    }
    sort(m.rbegin(), m.rend()); 
    long long prefix = 0, ans = 0;
    for (int j = 1; j <= N; j++) {
        prefix += m[j-1];
        ans = max(ans, prefix * M);
    }
    cout << ans << endl;
    return 0;
}