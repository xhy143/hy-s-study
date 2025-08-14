#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int dp[100][100];
int path[1001][1001];
struct node{
    int x,y;
};
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            dp[i][j]=a[i][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=i;j++){
            if(dp[i+1][j]>=dp[i+1][j+1]){
                dp[i][j]+=dp[i+1][j];
                path[i][j]=j;
            }   
            else {
                dp[i][j]+=dp[i+1][j+1];
                path[i][j]=j+1;
            }
            //dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    stack<node>st;
    int h=1;
    for(int i=1;i<=n;i++){
        st.push({i,h});
        h=path[i][h];
    }
    while(!st.empty()){
        node f=st.top();
        st.pop();
        if(st.empty()){
            cout<<f.x<<","<<f.y<<endl;
            cout<<dp[1][1];
            return 0;
        }
        cout<<f.x<<","<<f.y<<"->";
    }
}