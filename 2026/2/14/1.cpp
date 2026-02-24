#include<bits/stdc++.h>
using namespace std;
int a[100001]; 
int dp[100001];

int main() {
    int n = 0; 
    int x;
    while (cin >> x) { 
        a[n++] = x;
    }
    int len1 = 0; 
    for (int i = 0; i < n; i++) {
        int l = 0, r = len1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (dp[mid] < a[i]) { 
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        dp[l] = a[i];
        if (l == len1) {
            len1++;
        }
    }
    int len2 = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len2;
        while (l < r) {
            int mid = (l + r) / 2;
            if (dp[mid] >= a[i]) { 
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        dp[l] = a[i];
        if (l == len2) {
            len2++;
        }
    }
    cout << len1 << endl;
    cout << len2 << endl;

    return 0;
}