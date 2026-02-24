#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, fa, ls[N], rs[N], col[N], rev[N], q, a;
char x;

void pd(int rt) {
	if (!rev[rt]) return;
	rev[rt] ^= 1, col[rt] ^= 1;
	rev[ls[rt]] ^= 1, rev[rs[rt]] ^= 1;
}
void dfs(int rt) {
	if (!rt) return;
	pd(rt);
	dfs(ls[rt]), dfs(rs[rt]);
}

signed main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> fa;
		(ls[fa] ? rs[fa] : ls[fa]) = i;
	}
	for (int i = 1; i <= n; i++) cin >> x, col[i] = x - '0';
	for (cin >> q; q--; ) {
		cin >> a;
		pd(a); 
		rev[a] ^= 1;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << col[i];
	return 0;
}
