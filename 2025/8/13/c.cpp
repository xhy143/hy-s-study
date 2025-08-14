#include<bits/stdc++.h>
using namespace std;
int a[200005], b[200005], n;

void check() {
    if(b[n] % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
    int sum = b[n] / 3;
    for(int l = 2; l <= n - 1; l++) {
        if(b[l-1] != sum) continue;
        for(int r = l; r <= n - 1; r++) {
            if(b[r] - b[l-1] == sum && b[n] - b[r] == sum) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        b[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = b[i - 1] + a[i];
        }
        check();
    }
}