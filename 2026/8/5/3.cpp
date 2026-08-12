#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int t,k,C[maxn][maxn],sum[maxn][maxn];
void init(){
    C[0][0]=1;
    for(int i=1;i<=2000;i++){
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
        }
    }
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=2000;j++){
            if(i==0&&j==0)sum[i][j]=0;
            else if(i==0)sum[i][j]=sum[i][j-1];
            else if(j==0)sum[i][j]=sum[i-1][j];
            else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if(j<=i&&C[i][j]==0)sum[i][j]++;
        }
    }
}
int main(){
    cin>>t>>k;
    init();
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<sum[n][m]<<endl;
    }
}