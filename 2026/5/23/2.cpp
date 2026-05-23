#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getx(int j, vector<ll>& S) {
    return S[j];
}

ll gety(int j, vector<ll>& dp, vector<ll>& S) {
    return dp[j];
}
double getSlope(int j1, int j2, vector<ll>& dp, vector<ll>& S) {
    return (double)(dp[j2] - dp[j1]) / (S[j2] - S[j1]);
}
ll solve(int n, vector<int>& a) {
    vector<ll> S(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        S[i] = S[i-1] + (ll)a[i-1] * a[i-1];
    }
    vector<ll> dp(n + 1, 0);
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        ll k = a[i-1]; 
        int l = 0, r = q.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (getSlope(q[mid], q[mid+1], dp, S) <= k) {
                l = mid + 1;  
            } else {
                r = mid;
            }
        }
        int j = q[l];
        dp[i] = dp[j] + (S[i] - S[j]) * a[i-1];
        while (q.size() >= 2) {
            int j1 = q[q.size() - 2], j2 = q.back();
            if (getSlope(j1, j2, dp, S) >= getSlope(j2, i, dp, S)) {
                q.pop_back();
            } else {
                break;
            }
        }
        q.push_back(i);
    }
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}