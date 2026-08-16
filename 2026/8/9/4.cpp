#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
string raw, str;
int p[maxn*2], n, len, deg[maxn];
long long ans = 0;
int main(){
    cin >> raw;
    n = raw.size();
    for (int i = 0; i < n; i++){
        str += '#'; 
        str += raw[i];
    }
    str += '#'; 
    len = str.size();
    int l = 0, r = -1;
    for (int i = 0; i < len; i++){
        int mir = l + r - i;
        p[i] = (i <= r) ? min(r - i, p[mir]) : 0;
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < len && str[i - p[i] - 1] == str[i + p[i] + 1]){
            p[i]++;
        }
        if (i + p[i] > r){
            l = i - p[i];
            r = i + p[i];
        }
        if (i - p[i] == 0){
            int prefix = (p[i] + 1) / 2;
            if (prefix == 0) continue;
            if (i % 2 == 1) prefix = prefix * 2 - 1;
            else prefix = prefix * 2;
            deg[prefix] = deg[prefix / 2] + 1;
            ans += deg[prefix];
        }
    }
    cout << ans << '\n';
}