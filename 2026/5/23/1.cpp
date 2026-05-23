#include<bits/stdc++.h>
using namespace std;
int c[10001][100001];
int main(){
    int n,l,r;
    cin>>n>>l>>r;;
    int a[10001],b[10001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=a[i]^b[j];
        }
    }
    int dp[10001][10001];//dp[i][j]对于i行，上一行为j
    for(int i=0;i<n;i++){
        dp[0][i]=c[0][i];
    }
    
}