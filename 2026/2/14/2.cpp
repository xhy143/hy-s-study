#include <bits/stdc++.h>
#define MAXN 100000
#define OwO 0
using namespace std;
struct node {
	int x, y, val;
}in[MAXN + 10];
int n, m, f[MAXN + 10], ans = 0;
int max(int x, int y) {return ((x > y) ? (x) : (y));}
int dist(int x, int y, int xx, int yy) {
	return abs(x - xx) + abs(y - yy);
}
int main() {
	cin >> n >> m;
	for(int p = 1; p <= m; p++)
		cin >> in[p].val >> in[p].x >> in[p].y;
	for(int p = 1; p <= m; p++) {
		f[p] = 1;
		for(int i = 1; i < p; i++)
			if(dist(in[p].x, in[p].y, in[i].x, in[i].y) <= in[p].val - in[i].val)
				f[p] = max(f[p], f[i] + 1);
	}	
	for(int p = 1; p <= m; p++)
		ans = max(ans, f[p]);
	cout << ans << endl;
    return OwO;
}
