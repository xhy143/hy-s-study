#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int f[N], g[N]; struct Node {int min, max; Node(int ge = 0, int fe = 0): min(ge), max(fe){}} preX[N], preY[N], sufX[N], sufY[N];
#define update(T, p) (Node){T[i] < T[p.min] ? i : p.min, T[i] > T[p.max] ? i : p.max};
bool check1(int x, int y, int n, int m) 
{
	if (x == 1 || y == 1) return true;
	Node X = preX[x - 1], Y = preY[y - 1];
	if (f[X.min] < g[Y.min]) return check1(X.min, y, n, m);
	if (g[Y.max] > f[X.max]) return check1(x, Y.max, n, m);
	return false;
}
bool check2(int x, int y, int n, int m) 
{
	if (x == n || y == m) return true;
	Node X = sufX[x + 1], Y = sufY[y + 1];
	if (f[X.min] < g[Y.min]) return check2(X.min, y, n, m);
	if (g[Y.max] > f[X.max]) return check2(x, Y.max, n, m);
	return false;
}
bool solve(int tmpf[], int tmpg[], int n, int m)
{
	if (tmpf[1] >= tmpg[1]) return false; 
	for (int i = 1; i <= n; i++) f[i] = tmpf[i]; 
	for (int i = 1; i <= m; i++) g[i] = tmpg[i];
	for (int i = 1; i <= n; i++) preX[i] = (i == 1) ? (Node){1, 1} : update(f, preX[i - 1]);
	for (int i = 1; i <= m; i++) preY[i] = (i == 1) ? (Node){1, 1} : update(g, preY[i - 1]);
	for (int i = n; i >= 1; i--) sufX[i] = (i == n) ? (Node){n, n} : update(f, sufX[i + 1]);
	for (int i = m; i >= 1; i--) sufY[i] = (i == m) ? (Node){m, m} : update(g, sufY[i + 1]);

	Node X = preX[n], Y = preY[m]; 
	if (f[X.min] >= g[Y.min] || g[Y.max] <= f[X.max]) return false;
	return check1(X.min, Y.max, n, m) && check2(X.min, Y.max, n, m); 
}
int tx[N], ty[N], ttx[N], tty[N];
int main()
{
	int n, m, q;
	scanf("%*d%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &tx[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &ty[i]);
	putchar(solve(tx, ty, n, m) || solve(ty, tx, m, n) ? '1' : '0');
	while (q--)
	{
		for (int i = 1; i <= n; i++) ttx[i] = tx[i];
		for (int i = 1; i <= m; i++) tty[i] = ty[i];
		int cx, cy;
		scanf("%d%d", &cx, &cy);
		while (cx--) {int p, v; scanf("%d%d", &p, &v); ttx[p] = v;}
		while (cy--) {int p, v; scanf("%d%d", &p, &v); tty[p] = v;}
		putchar(solve(ttx, tty, n, m) || solve(tty, ttx, m, n) ? '1' : '0');
	}
	return 0;
}
