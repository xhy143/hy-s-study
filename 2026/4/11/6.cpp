#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5, M = 4e5 + 5;

int n, m, a, b, c, ecnt, nxt[M], adj[N], sze[N], maxs[N], go[M], tr[4],
dep[N], ans[N], G = 1;
bool vis[N], ind[N];

std::vector<int> son[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u)
{
	vis[u] = 1; sze[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]])
		{
			dep[v] = dep[u] + 1; dfs(v); sze[u] += sze[v];
			maxs[u] = Max(maxs[u], sze[v]);
			son[u].push_back(v);
		}
}

int calc(int u)
{
	int res = n + 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		res = Min(res, dep[v]);
	for (int i = 0; i < son[u].size(); i++)
		res = Min(res, calc(son[u][i]));
	return res;
}

void setr(int u, int c)
{
	ans[u] = c;
	for (int i = 0; i < son[u].size(); i++)
		setr(son[u][i], c);
}

void other(int c)
{
	for (int u = 1; u <= n; u++) if (!ans[u]) ans[u] = c;
}

void fake(int u, int s)
{
	vis[u] = 1; sze[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]] && ans[u] == ans[v])
		{
			fake(v, s); sze[u] += sze[v];
			if (s <= sze[v]) return;
			s -= sze[v];
		}
	if (s) ans[u] = 3;
}

void output(int ca, int cb)
{
	memset(vis, 0, sizeof(vis));
	for (int u = 1; u <= n; u++)
		if (ans[u] == 1) {fake(u, ca - a); break;}
	for (int u = 1; u <= n; u++)
		if (ans[u] == 2) {fake(u, cb - b); break;}
	for (int u = 1; u <= n; u++) printf("%d ", tr[ans[u]]);
	puts(""); exit(0);
}

int main()
{
	int x, y;
	read(n); read(m); read(a); read(b); read(c);
	tr[1] = 1; tr[2] = 2; tr[3] = 3;
	if (a > b) std::swap(a, b), std::swap(tr[1], tr[2]);
	if (a > c) std::swap(a, c), std::swap(tr[1], tr[3]);
	if (b > c) std::swap(b, c), std::swap(tr[2], tr[3]);
	while (m--) read(x), read(y), add_edge(x + 1, y + 1);
	dfs(dep[1] = 1);
	for (int u = 2; u <= n; u++)
	{
		if (a <= sze[u] && sze[u] <= n - b)
			setr(u, 1), other(2), output(sze[u], n - sze[u]);
		if (b <= sze[u] && sze[u] <= n - a)
			setr(u, 2), other(1), output(n - sze[u], sze[u]);
	}
	for (int u = 2; u <= n; u++)
		if (Max(maxs[u], n - sze[u]) < Max(maxs[G], n - sze[G]))
			G = u;
	int sum = 1;
	for (int i = 0; i < son[G].size(); i++)
		if (ind[i] = calc(son[G][i]) >= dep[G]) sum += sze[son[G][i]];
	if (sum > n - a) output(0, 0);
	setr(G, 2); other(1); sum = sze[G];
	for (int i = 0; i < son[G].size(); i++)
		if (!ind[i] && sum > n - a) sum -= sze[son[G][i]], setr(son[G][i], 1);
	return output(n - sum, sum), 0;
}
