#include<bits/stdc++.h>
using namespace std;
#define in freopen("car.in","r",stdin);
#define out freopen("car.out","w",stdout);
int main(){
    in;
    out;
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int>jy(501);
        for(int i=1;i<=n;i++){
            cin>>jy[i];
        }
        jy[0]=0;
        int ans=-0x7fffffff;
        for(int i=1;i<=n;i++){
            ans=max(ans,jy[i]-jy[i-1]);
        }
        ans=max(ans,(m-jy[n])*2);
        cout<<ans<<endl;
    }
}