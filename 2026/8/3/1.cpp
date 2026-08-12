#include<bits/stdc++.h>
using namespace std;
const int maxn=101,maxk=101,maxm=1e4+10;
int n,m,a[maxn],w[maxn][maxm],dp[maxm],pre[maxn],K[maxm];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        K[i]=k;
        for(int j=1;j<=k;j++){
            cin>>a[j];
            pre[j]=pre[j-1]+a[j];
        }
        for(int x=0;x<k;x++){
            for(int y=0;x+y<=k;y++){
                w[i][x+y]=max(w[i][x+y],pre[x]+(pre[k]-pre[k-y]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<=K[i];k++){
                if(j<k)break;
                dp[j]=max(dp[j],dp[j-k]+w[i][k]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}