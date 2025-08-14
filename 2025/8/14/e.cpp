#include<bits/stdc++.h>
using namespace std;
int n, s[20], used[20], ans = 0;

bool isprime(int a) {
    if(a < 2) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}

void dfs(int depth) {
    if(depth == n) {
        if(isprime(s[n-1] + s[0])) {
            ans++;
            cout << ans << ":";
            for(int i = 0; i < n; i++) {
                cout << s[i] << ' ';
            }
            cout<<endl;
        }
        return;
    }
    for(int i = 1; i <= n; i++) { 
        if(!used[i] && isprime(s[depth-1] + i)) {
            s[depth] = i;
            used[i] = 1;
            dfs(depth + 1);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        s[0] = i;
        used[i] = 1;
        dfs(1);
        used[i]=0;
    }
    
    cout << "total:" << ans << endl;
}