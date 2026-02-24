#include <iostream>
using namespace std;

long long C2(long long x) {
    if (x < 2) return 0;
    return x * (x - 1) / 2;
}

int main() {
    freopen("team.in","r",stdin);
    freopen("team.out","w",stdout);
    long long n, m;
    cin >> n >> m;
    long long q = n / m;
    long long r = n % m;
    long long min_friends = r * C2(q + 1) + (m - r) * C2(q);
    long long max_friends = C2(n - m + 1);

    cout << min_friends << " " << max_friends << endl;

    return 0;
}