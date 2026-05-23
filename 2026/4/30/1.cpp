#include <iostream>
using namespace std;
int a[60][60];
int dp[60][60][60][60];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				for (int t = 1; t <= n; t++) {
					int maxn1 = max(dp[i - 1][j][k - 1][t], dp[i - 1][j][k][t - 1]);
					int maxn2 = max(dp[i][j - 1][k - 1][t], dp[i][j - 1][k][t - 1]);
					int maxn = max(maxn1, maxn2);
					dp[i][j][k][t] = maxn + a[i][j] + a[k][t];
					if (i == k && j == t) {
						dp[i][j][k][t] -= a[i][j];
					}
				}
			}
		}
	}
	cout << dp[m][n][m][n];
	return 0;
}
