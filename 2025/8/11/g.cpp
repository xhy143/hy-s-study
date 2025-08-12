#include<bits/stdc++.h>
using namespace std;
struct ticket{
    int t, prise;
}a[100001];
int main(){
    int n, l = 0, r = 0;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int tool, pri, time;
        cin >> tool >> pri >> time;
        if(!tool){
            a[++r] = {time, pri};
            ans += pri;
            continue;
        }
        if(tool){
            while(l <= r && time - a[l].t > 45) l++; 
            if(l < r && pri <= a[l].prise){
                l++;
            }else{
                ans += pri; 
            }
        }
    }
    cout << ans;
}