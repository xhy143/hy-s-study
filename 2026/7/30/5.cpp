#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, m;
    cin >> t >> m;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < 0) {
            a = -a; b = -b; c = -c;
        }
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO\n";
            continue;
        }
        int p2 = 1;
        int d = delta;
        for (int i = 2; i * i <= d; i++) {
            while (d % (i * i) == 0) {
                p2 *= i;
                d /= (i * i);
            }
        }
        int p1 = -b;
        int q1 = 2 * a;
        int g1 = gcd(q1, abs(p1));
        p1 /= g1;
        q1 /= g1;
        int q2 = 2 * a;
        int g2 = gcd(q2, p2);
        p2 /= g2;
        q2 /= g2;
        if (d == 0) {
            if (q1 == 1) cout << p1 << '\n';
            else cout << p1 << '/' << q1 << '\n';
            continue;
        }
        if (d == 1) {
            p1 = p1 * q2 + p2 * q1;
            q1 = q1 * q2;
            int g = gcd(q1, abs(p1));
            p1 /= g;
            q1 /= g;
            if (q1 < 0) { p1 = -p1; q1 = -q1; }
            if (q1 == 1) cout << p1 << '\n';
            else cout << p1 << '/' << q1 << '\n';
            continue;
        }
        if (p1 != 0) {
            if (q1 == 1) cout << p1;
            else cout << p1 << '/' << q1;
        }
        if (p1 != 0) cout << '+';
        if (p2 == 1 && q2 == 1) {
            cout << "sqrt(" << d << ")\n";
        } else if (p2 == 1) {
            cout << "sqrt(" << d << ")/" << q2 << "\n";
        } else if (q2 == 1) {
            cout << p2 << "*sqrt(" << d << ")\n";
        } else {
            cout << p2 << "*sqrt(" << d << ")/" << q2 << "\n";
        }
    }
    //这啥玩意这是
    return 0;
}