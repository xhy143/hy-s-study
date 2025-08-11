#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    set<int> ilsmao; 
    vector<int> filesize(m+1, 0); 
    for(int i=0;i<n;i++) {
        ilsmao.insert(a[i]);
        stringstream ss;
        int cnt = 0;
        for(auto it = ilsmao.begin(); it != ilsmao.end(); ++it) {
            if(cnt) ss << " ";
            ss << *it;
            cnt++;
        }
        string content = ss.str();
        filesize[a[i]] = content.size();
    }

    for(int i=1;i<=m;i++) {
        cout << filesize[i];
        if(i!=m) cout << " ";
    }
    cout << endl;
}
