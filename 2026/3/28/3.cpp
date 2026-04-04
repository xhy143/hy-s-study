#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
stack<ll> stk;
vector<ll> e[N];
string s;
ll n, f[N], dp[N], res[N], ans;
void dfs(ll u)
{
	if (s[u - 1] == '(')
	{
		res[u] = res[f[u]];
		stk.push(u);
		for (ll v : e[u])
			dfs(v);
		stk.pop();
	}
	else if (stk.empty())
	{
		res[u] = res[f[u]];
		for (ll v : e[u])
			dfs(v);
	}
	else
	{
		ll k = stk.top();
		dp[u] = dp[f[k]] + 1;
		res[u] = res[f[u]] + dp[u];
		stk.pop();
		for (ll v : e[u])
			dfs(v);
		stk.push(k);
	}
}
int main()
{
	cin >> n >> s;
	for (ll i = 2; i <= n; i++)
		cin >> f[i], e[f[i]].push_back(i);
	dfs(1);
	for (ll i = 1; i <= n; i++)
		ans ^= res[i] * i;
	cout << ans;
	return 0;
}
