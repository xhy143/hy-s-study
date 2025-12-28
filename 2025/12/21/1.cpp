#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(__builtin_expect(a[i][j]*a[i+1][j+1]==a[i+1][j]*a[i][j+1], 0) ){
                ans++;
            }
        }
    }
    cout<<ans;
}