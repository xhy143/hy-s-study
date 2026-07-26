#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y;
signed main(){
    int ans=1;
    cin>>n>>x>>y;
    int sy=y;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int sx=x-2;
        a-=sx;
        sy--;
        if(sy<0){
            sy+=y;
            ans++;
        }
        sy-=ceil(1.0*a/x);
        if(sy<0){
            sy+=y;
            ans++;
        }
    }
    cout<<(long long)ans;
}
