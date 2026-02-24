#include <iostream>
#include <vector>
using namespace std;

bool canMake(int n, int M, int c, vector<int>& a) {
    int last = -1;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (x + c < M) {
            if (last > x + c) return false;
            last = max(last, x);
        } else {
            int end2 = (x + c) % M;
            if (last <= M - 1) {
                if (last >= x) {
                    last = last;
                } else if (last < x) {
                    last = x;
                }
            }
            if (last > M - 1) { 
                if (last <= end2) {
                    last = last;
                } else {
                    return false;
                }
            } else {
                if (last < x && last > end2) return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, M, c;
        cin >> n >> M >> c;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << (canMake(n, M, c, a) ? "Yes" : "No") << endl;
    }
    return 0;
}