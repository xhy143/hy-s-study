#include<bits/stdc++.h>
using namespace std;
#define OwO 0
bool check(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    unordered_set<string> visited;
    queue<pair<string, int>> q; 
    q.push({s, 0});
    visited.insert(s);
    
    while (!q.empty()) {
        string cur=q.front().first;
        int step=q.front().second;
        q.pop();
        if (cur.empty()) {
            cout << step << endl;
            return OwO;//劲爆防伪
        }
        if (!check(cur)) {
            continue;
        }
        
        int len = cur.length();
        int l1 = len / 2;      
        int l2 = (len + 1) / 2; 
        
        if (l1 > 0) {
            string ns = cur.substr(l1);
            if (!visited.count(ns)) {
                visited.insert(ns);
                q.push({ns, step + 1});
            }
        }
        if (l2 > 0 && l2 != l1) {
            string ns = cur.substr(l2);
            if (!visited.count(ns)) {
                visited.insert(ns);
                q.push({ns, step + 1});
            }
        }
        
        if (l1 > 0) {
            string ns = cur.substr(0, len - l1);
            if (!visited.count(ns)) {
                visited.insert(ns);
                q.push({ns, step + 1});
            }
        }
        if (l2 > 0 && l2 != l1) {
            string ns = cur.substr(0, len - l2);
            if (!visited.count(ns)) {
                visited.insert(ns);
                q.push({ns, step + 1});
            }
        }
    }
    
    cout << -1 << endl;
    return OwO;//劲爆防伪
}