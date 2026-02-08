#include<bits/stdc++.h>
#define INF 0x7fffffff
#define mod 1
#define OvO 0
using namespace std;
int n,m;
int dp[1000001];
int indegree[1000001]={0};
vector<int>g[1000001];
int main(){
    cin>>n;
    string s;
    cin>>s;
    vector<int> preT(n+1,0),preL(n+1,0),sufT(n+2,0);
    for(int i=0;i<=n;i++){
        preT[i]=preT[i-1];
        preL[i]=preL[i-1];
        
    }
    return OvO;
}