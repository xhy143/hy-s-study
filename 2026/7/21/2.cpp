#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int mod=1e9+7;
const int base=131;
unsigned long long h[maxn], pow_base[maxn];

unsigned long long get_hash(int l, int r) {
    return h[r] - h[l-1] * pow_base[r-l+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin>>T;
    pow_base[0]=1;
    for(int i=1;i<maxn;i++) pow_base[i]=pow_base[i-1]*base;
    while(T--){
        string p;
        cin>>p;
        int n=p.size();
        h[0]=0;
        for(int i=1;i<=n;i++){
            h[i]=h[i-1]*base + p[i-1];
        }
        int ans=-1;
        for(int len=1;len<=n/2;len++){
            if(n%len!=0) continue;
            bool flag=true;
            for(int i=len+1;i<=n;i+=len){
                if(get_hash(1,len)!=get_hash(i-len+1,i)){
                    flag=false;
                    break;
                }
            }
            if(flag&&n/len>=2){
                ans=0;
                break;
            }
        }
        if(ans==-1){
            for(int len=n/2;len>=1;len--){
                int maxk=n/len;
                if(maxk<2) continue;
                bool ok=true;
                for(int i=len+1;i<=maxk*len;i+=len){
                    if(get_hash(1,len)!=get_hash(i-len+1,i)){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    ans=n-maxk*len;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}