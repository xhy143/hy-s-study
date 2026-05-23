#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getx(int j, vector<ll>& pre) {
    return pre[j];
}
ll gety(int j, vector<ll>& dp) {
    return dp[j];
}
ll mp(int n, vector<int>& a) {
    vector<ll> sum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + (ll)a[i-1] * a[i-1];
    }
    vector<ll> dp(n + 1, 0);
    deque<int> q;
    q.push_back(0);
    for(int i = 1; i <= n; i++) {
        ll k = a[i-1];
        int l = 0, r = q.size() - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            ll x1 = getx(q[mid], sum), y1 = gety(q[mid], dp);
            ll x2 = getx(q[mid+1], sum), y2 = gety(q[mid+1], dp);
            if((y2 - y1) <= k * (x2 - x1)) {
                l = mid + 1;  
            } else {
                r = mid;
            }
        }
        
        int j = q[l];
        dp[i] = dp[j] + (sum[i] - sum[j]) * a[i-1];
        while(q.size() >= 2) {
            int j1 = q[q.size() - 2], j2 = q.back();
            ll x1 = getx(j1, sum), y1 = gety(j1, dp);
            ll x2 = getx(j2, sum), y2 = gety(j2, dp);
            ll x3 = getx(i, sum), y3 = gety(i, dp);
            if((y2 - y1) * (x3 - x2) >= (y3 - y2) * (x2 - x1)) {
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << mp(n, a) << endl;
    return 0;
}