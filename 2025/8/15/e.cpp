#include <bits/stdc++.h>
using namespace std;

int main() {
    int r,b,c,d,e;
    cin>>r>>b>>c>>d>>e;
    if(e-c<0&&e-d<0){
        cout<<r*c+b*d;
    } else{
        int ans=0;
        ans+=min(r,b)*e;
        r-=(r<b?r:b);
        b-=(r>b?b:r);
        ans+=(r>b?r*c:b*d);
        cout<<ans;
    }
    return 0;
}
