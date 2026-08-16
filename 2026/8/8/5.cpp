#include<bits/stdc++.h>
using namespace std;
const int maxn=3.2e7+10;
bool pri[maxn];
int minp[maxn];
vector<int>primes;
void init(){
    int n=maxn;
    pri[1]=1;
    for(int i=2;i<n;i++){
        if(!pri[i]){
            primes.push_back(i);
            minp[i]=i;
        }
        for(int p:primes){
            if(i*p>=n)break;
            pri[i*p]=1;
            minp[i*p]=p;
            if(i%p==0)break;
        }
    }
}
bool prime(long long n){
    if(n<=maxn) return !pri[n];
    else{
        for(int p:primes){
            if(p*p>n)break;
            if(n%p==0)return false;
        }
    }
    return 1;
}
void factorize(long long n, vector<pair<long long, int>>& factors){
    for(int p: primes){
        if(p*p > n) break;
        if(n % p == 0){
            int cnt = 0;
            while(n % p == 0){
                n /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
    }
    if(n > 1){
        factors.push_back({n, 1});
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        
        vector<pair<long long, int>> factors;
        factorize(n, factors);
        for(int i = 0; i < factors.size(); i++){
            cout << factors[i].first << " " << factors[i].second;
            if(i != factors.size() - 1) cout << " ";
        }
        cout << "\n";
    }
}