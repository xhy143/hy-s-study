#include<bits/stdc++.h>
using namespace std;
int s[10001], q = 0; 

void dfs(int n, int sr, int step, int last) {
    if (sr == 0) {
        q++;
        cout << n << '=';
        for (int i = 0; i < step; i++) {
            cout << s[i] << (i == step - 1 ? '\n' : '+');
        }
        return;
    }
    for (int num = last; num <= sr; num++) {
        s[step] = num;
        dfs(n, sr - num, step + 1, num);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        s[0] = i; 
        dfs(n, n - i, 1, i);
    }
    return 0;
}