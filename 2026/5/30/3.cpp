#include <bits/stdc++.h>
using namespace std;
const int maxn = 3.2e7 + 10;
bool fpri[maxn];
vector<int> primes;
int phi[maxn];
void ispr()
{
    fpri[1] = 1,phi[1]=1;
    for (int i = 2; i < maxn; i++)
    {
        if (!fpri[i])
        {
            primes.push_back(i);
            phi[i]=i-1;
        }
        for (int p : primes)
        {
            if (1ll * i * p >= maxn)
                break;
            fpri[i * p] = true;
            if (i % p == 0){
                phi[i*p]=phi[i]*p;
                break;
            }else{
                phi[i*p]=phi[i]*(p-1);
            }
        }
    }
}
long long solve(long long n)
{
    long long ans=1;
    for(int p:primes){
        if(n<maxn) break;
        if(1ll*p*p>n){
            ans=ans*(n-1);
            n=1;
            break;
        }
        if(n%p==0){
            n/=p;
            ans*=(p-1);
            while(n%p==0){
                n/=p;
                ans*=p;
            }
        }
    }
    if(n>1)ans*=phi[n];
    return ans;
}
vector<long long> fac;
signed main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int T;
    ispr();
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        cout<<solve(n)<<'\n';
    }
}