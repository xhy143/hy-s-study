#include<bits/stdc++.h>
using namespace std;
#define OwO 0
#define inf 1e16
#define int unsigned long long
signed main(){
    int now,n,t=0;
    cin>>n>>now;
    while(n--){
        char p;
        cin>>p;
        switch(p){
            case 'U':
                if(now==1){
                    break;
                }
                if(t){
                    t--;
                    break;
                }
                now/=2;
                break;
            case 'L':
                if(now>=1e12){
                    t++;
                    break;
                }
                now*=2;
                break;
            case 'R':
                if(now>=1e12){
                    t++;
                    break;
                }
                now*=2;
                now++;
                break;
        }
    }
    cout<<now;
    return OwO;
}