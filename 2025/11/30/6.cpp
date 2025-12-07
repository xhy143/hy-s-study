#include <bits/stdc++.h>
using namespace std;
int sum(long long k) { 
	int ans = 0;
	for (; k; k /= 10) ans += k % 10;
	return ans;
}

int trans(long long k) { 
	k *= 7;
	while (k > 9) k = sum(k);
	return k;
}

bool judge(long long n) {
	int ans = 0;
	for (int p = 1; n; n /= 10, ++p) {
		if (p %2==1) ans += trans(n % 10);
		else ans += n % 10;
	}
	return !(ans % 8);
}

int main() {
	int T;
    cin>>T;
	long long n;
	while (T--) {
		cin >> n;
		cout << (judge(n) ? 'T' : 'F') << endl;
	}
	return 0;
}
