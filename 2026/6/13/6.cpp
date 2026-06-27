#include<bits/stdc++.h>
using namespace std;
int f[2020][2020];
const int p=1e9+7;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(k,i);j++){
                f[i][j]=(f[i-1][j-1]+(1ll*f[i-1][j]*j)%p)%p;
            }
        }
        cout<<f[n][k]<<endl;
    }
}