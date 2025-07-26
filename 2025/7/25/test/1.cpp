#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    int a[100005];
    int ans = 0, maxx = x;
    a[1] = x;
    ans += maxx;
    for(int i = 2; i <= n; i++){
        a[i] = (379 * a[i-1] + 131) % 997;
        maxx = min(maxx, a[i]);
        ans += maxx;
    }
    cout << ans << endl;
}