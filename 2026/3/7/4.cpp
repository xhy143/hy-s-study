#include <bits/stdc++.h>
using namespace std;
#define MAXN 6005
int h[MAXN],v[MAXN];
vector<int> a[MAXN];
int f[MAXN][2];
namespace solve{
    void dp(int x){
        f[x][0] = 0;
        f[x][1] = h[x];
        for (int i = 0; i < a[x].size(); i++){
            int y = a[x][i];
            dp(y);
            f[x][0] += max(f[y][0], f[y][1]);
            f[x][1] += f[y][0];
        }
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n - 1; i++){
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
        v[x] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (!v[i])
        {
            root = i;
            break;
        }
    solve::dp(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
