#include <bits/stdc++.h>
using namespace std;
const int maxn = 3.2e7 + 10;
bool fpri[maxn];
vector<int> primes;
int minp[maxn];
void ispr()
{
    fpri[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!fpri[i])
        {
            primes.push_back(i);
            minp[i]=i;
        }
        for (int p : primes)
        {
            if (1ll * i * p >= maxn)
                break;
            fpri[i * p] = true;
            minp[i*p]=p;
            if (i % p == 0)
                break;
        }
    }
}
void solve(long long n,vector<long long> &fac)
{
    for(int p:primes){
        if(n<maxn){break;}
        if(1ll*p*p>n){
            fac.push_back(n);n=1;
            break;
        }
        while(n%p==0){
            fac.push_back(p);
            n/=p;
        }
    }
    while(n>1){
        fac.push_back(minp[n]);
        n/=minp[n];
    }
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
        fac.clear();
        int cnt=1;
        solve(n,fac);
        for(int i=1;i<fac.size();i++){
            if(fac[i]!=fac[i-1]){
                cout<<fac[i-1]<<' '<<cnt<<' ';
                cnt=1;
            }
            else cnt++;
        }
        cout<<fac[fac.size()-1]<<' '<<cnt<<'\n';
    }
}