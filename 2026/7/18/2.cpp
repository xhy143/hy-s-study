#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x=1<<i;
        if(x>n)break;
        ans += (int)sqrt(n - x);
    }
    cout<<ans<<endl;
}