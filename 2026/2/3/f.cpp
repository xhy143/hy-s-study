#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct MS{
    multiset<int> ms;
    void ins(int x) { 
        ms.insert(x);
    }
    void delOne(int x) {
        multiset<int>::iterator it = ms.find(x);
        if (it == ms.end()) return ;
        ms.erase(it);
    }
    int closest(int x) { 
        if (ms.empty()) return INF;
        multiset<int>::iterator it = ms.lower_bound(x), it2 = it;
        if (it == ms.end()) return *(--it);
        if (it == ms.begin()) return *it; 
        it2--;
        if (*it - x < x - *it2) return *it;
        return *it2;
    }
} bst;

int main(){
    int n, ans =1145141919; 
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = k; i < n; i++) {
        bst.ins(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i + k < n) {
            int clo = bst.closest(a[i]);
            if (clo != INF) {
                ans = min(ans, abs(clo - a[i]));
            }
            bst.delOne(a[i + k]);
        }
        if (i - k >= 0) {
            bst.ins(a[i - k]);
        }
    }
    cout << ans << endl;
    return 0;
}