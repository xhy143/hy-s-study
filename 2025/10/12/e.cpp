#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[101][101];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dp[i][j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=1+i;j<=n;j++){
            dp[j][k]=dp[j-1][k]+dp[j][k+1];
            k++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<i;k++){
            cout<<"     ";
        }
        for(int j=1;j<=n;j++){
            cout<<setw(5)<<dp[i][j];
        }
        cout<<endl;
    }
}