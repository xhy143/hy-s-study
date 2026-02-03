#include<bits/stdc++.h>
using namespace std;

priority_queue<int> s; 
priority_queue<int, vector<int>, greater<int>> b; 
int m, n; 

void ins(int x, int i) {
    if (s.empty() || x <= s.top()) {
        s.push(x);
    } else {
        b.push(x);
    }
    while (s.size() > i) {
        b.push(s.top());
        s.pop();
    }
    while (s.size() < i) {
        s.push(b.top());
        b.pop();
    }
}

int a[1000001],u[10000001];
int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }

    int k = 1; 
    for (int i = 1; i <= m; i++) {
        ins(a[i], k);
        while (k <= n && u[k] == i) {
            cout << s.top() << endl;
            k++;
            while (s.size() > k) {
                b.push(s.top());
                s.pop();
            }
            while (s.size() < k) {
                s.push(b.top());
                b.pop();
            }
        }
    }
    return 0;
}