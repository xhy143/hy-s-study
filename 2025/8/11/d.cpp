#include<bits/stdc++.h>
using namespace std;
int hc[10]={6,2,5,5,4,5,6,3,7,6};
int match(int x) {
    if(x==0) return hc[0];
    int res=0;
    while(x) {
        res += hc[x%10];
        x /= 10;
    }
    return res;
}
int main() {
    int n, ans=0;
    cin >> n;
    n -= 4; 
    for(int A=0; A<=1111; A++) {
        for(int B=0; B<=1111; B++) {
            int C = A+B;
            int sum = match(A) + match(B) + match(C);
            if(sum == n) ans++;
        }
    }
    cout << ans << endl;
}