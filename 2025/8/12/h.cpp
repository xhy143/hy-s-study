#include<bits/stdc++.h>
using namespace std;

string divide(long long a, long long b, int n) {
    string res = to_string((a / b)); 
    a %= b;
    if(n == 0) return res;
    res += ".";
    for(int i = 0; i < n; i++) {
        a *= 10;
        res += to_string(a / b);
        a %= b;
    }
    return res;
}

int main(){
    long long a, b, n;
    cin >> a >> b >> n;
    cout << divide(a, b, n) << endl;
}