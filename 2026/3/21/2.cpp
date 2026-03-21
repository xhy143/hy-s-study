#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 15;
ll f[N][2][N][2];
int num[N];  
ll dfs(int len, bool issmall, int sum, bool zero, int d)
{
    ll ret = 0;
    if (len == 0) return sum;  
    if (f[len][issmall][sum][zero] != -1) return f[len][issmall][sum][zero];  
    for (int i = 0; i < 10; i ++){
        if (!issmall && i > num[len]) break;
        ret += dfs(len-1, issmall || (i<num[len]), sum+((!zero || i) && (i==d)), zero && (i == 0), d);
    }
    f[len][issmall][sum][zero] = ret;
    return ret;
}

ll solve(ll x, int d)
{
    int len = 0;
    while (x){
        num[++ len] = x%10;
        x /= 10;
    } 
    memset(f, -1, sizeof f); 
    return dfs(len, 0, 0, 1, d); 
}

int main()
{
    ll a, b; 
    cin>>a>>b;
    for (int i = 0; i < 10; i ++)
        cout<< solve(b, i)-solve(a-1, i)<<' ';
    return 0;
}