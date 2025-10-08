#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    freopen("can.in","r",stdin);
    freopen("can.out","w",stdout);
    cin>>n>>m;
    for(x=0;x<=756;x++){
        if((n+x)==min(756,m+(x/4))){
            cout<<n+x;
            return 0;
        }
    }
    cout<<756;
    return 0;
}