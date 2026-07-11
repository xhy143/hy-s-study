#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e7+5;
int n, len, fa[maxn];
struct Edge {
	int u, v;
	double w;
} edg[maxn>>2];
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int find(int x) {
	if (x != fa[x]) {
		return fa[x] = find(fa[x]);
	}
	return x;
}
int x[maxn>>2], y[maxn>>2], r[maxn>>2];
void read() {
	cin >> n;
	int cnt = 0;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			double w1=0;
			w1 = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))-r[i]-r[j];
			if(w1<0){
				w1=0;
			}
			edg[++len] = {i, j, w1};
		}
	}
	sort(edg + 1, edg + len + 1, cmp);
	for (int i = 1; i <= len; i++) {
		int fr = edg[i].u, to = edg[i].v, rof = find(fr), ros = find(to);
		if (rof != ros) {
			fa[ros] = rof;
			ans += edg[i].w;
			cnt++;
		}
		if (cnt == n - 1) {
			printf("%.2lf",ans);
			return;
		}
	}
}
int main() {
	read();
}
