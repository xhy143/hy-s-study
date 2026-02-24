#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10; 
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN], b[MAXN];
int pos[MAXN]; 
int ans = INF;
int check(vector<int>& perm) {
    pos[perm[0]] = 0;
    int maxPos = 0;
    for (int i = 1; i < n; i++) {
        int current = perm[i];      
        int previous = perm[i-1]; 
        int minPos = max(pos[previous] + a[current] + 1, 
                        pos[previous] + b[previous] + 1);
        
        pos[current] = minPos;
        maxPos = max(maxPos, pos[current]);
    }
    return maxPos + 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;
    do {
        int len = check(perm);
        ans = min(ans, len);
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << ans << endl;
    
    return 0;
}