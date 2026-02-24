#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("leg.in","r",stdin);
    freopen("leg.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int minn=0x7fffffff,maxx=-0x7fffffff;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/4;j++){
                if(i*2+j*4==n){
                    minn=min(minn,i+j);
                    maxx=max(maxx,i+j);
                }
                if(i*2+j*4>n){
                    break;
                }
            }
        }
        cout<<minn<<' '<<maxx<<endl;
    }
}