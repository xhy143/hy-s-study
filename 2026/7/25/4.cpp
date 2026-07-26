#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100;
int T,n,m;
vector<int>g[maxn];
int dfn[maxn],clk=0,low[maxn];
int A,B,C;
stack<int>sta;
vector<vector<int>>bccs;
void tj(int u,int fa){
    ++clk;
    dfn[u]=low[u]=clk;
    
}