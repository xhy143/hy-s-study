#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    multiset<pair<int, int>> heap; 
    
    while (q--) {
        int op, i;
        cin >> op >> i;
        
        if (op == 1) {
            auto it = heap.insert({a[i], i});
            int pos = distance(heap.begin(), it) + 1;
            cout << pos << endl;
        } else {
            auto it = heap.find({a[i], i});
            int pos = distance(heap.begin(), it) + 1;
            heap.erase(it);
            cout << pos << endl;
        }
    }
    
    return 0;
}